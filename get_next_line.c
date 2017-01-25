/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 06:18:10 by fgrea             #+#    #+#             */
/*   Updated: 2017/01/25 19:22:56 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*get_next_line_fd_gestion(const int fd, t_gnl **file)
{
	t_gnl		*fileread;

	fileread = *file;
	while (fileread)
	{
		if (fileread->fd == fd)
			return (fileread);
		fileread = fileread->next;
	}
	if (!(fileread = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	fileread->fd = fd;
	if (!(fileread->buff = ft_strnew(BUFF_SIZE)))
		return (NULL);
	fileread->next = *file;
	*file = fileread;
	return (*file);
}

static ssize_t	get_next_line_finder(t_gnl *filetoread)
{
	ssize_t		ret;
	char		*tmp;
	char		buffer[BUFF_SIZE + 1];

	ret = 1;
	while (ret > 0 && !ft_strchr(filetoread->buff, '\n'))
	{
		if ((ret = read(filetoread->fd, &buffer, BUFF_SIZE)) == -1)
			return (-1);
		buffer[ret] = '\0';
		tmp = filetoread->buff;
		filetoread->buff = ft_strjoin(filetoread->buff, buffer);
		free(tmp);
		ft_memset(buffer, '\0', ret);
	}
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*file;
	char			*tmp;
	ssize_t			ret;

	if (fd < 0 || !line)
		return (-1);
	if ((file = get_next_line_fd_gestion(fd, &file)) == NULL)
		return (-1);
	if ((ret = get_next_line_finder(file)) == -1)
		return (-1);
	*line = ft_strsub(file->buff, 0, ft_strnlen(file->buff, '\n'));
	tmp = file->buff;
	file->buff = ft_strsub(tmp, (ft_strnlen(tmp, '\n') + 1), \
				ft_strlen(ft_strchr(tmp, '\n')));
	free(tmp);
	if (!**line && !ret)
		return (0);
	return (1);
}
