/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 05:42:42 by fgrea             #+#    #+#             */
/*   Updated: 2016/12/11 20:01:43 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

static int		get_next_line_check(char *line, int ret)
{
	size_t	i;

	i = 0;
	ft_putendl("LOLcheck");
	if (line == NULL && ret > 0)
		return (1);
	if (line == NULL)
		return (0);
	while (line != NULL && line[i] && line[i] != '\n')
		i++;
	ft_putnbr(i);
	ft_putendl("LOLcheck");
	if (line[i] == '\n' || ret == 0)
		return (0);
	else
		return (1);
}

static char		*get_next_line_result(char *line, char **save)
{
	char	**array;
	char	*tmp;
	size_t	i;
	size_t	s;

	i = 0;
	s = 0;
	tmp = NULL;
	array = ft_strsplit(line, '\n');
	if (array != NULL)
		line = array[i];
	ft_putendl("lol");
	i = 1;
	while (array != NULL && array[i])
	{
		tmp = ft_strjoin(*save, array[i]);
		ft_strdel(save);
		*save = ft_strjoin(tmp, NULL);
		ft_strdel(&tmp);
		i++;
	}
	return (line);
}

int			get_next_line(const int fd, char **line)
{
	static char		*save = NULL;
	char			*tmp;
	char			*tmp2;
	int				ret;

	ret = 1;
	tmp = NULL;
	tmp2 = NULL;
	*line = *line = ft_strjoin(save, NULL);
	ft_strdel(&save);
	while (get_next_line_check(*line, ret) == 1)
	{
		tmp = ft_strnew(BUFF_SIZE);
		if (*line != NULL)
			tmp2 = ft_strjoin(*line, NULL);
		ft_strdel(line);
		if ((ret = read(fd, tmp, BUFF_SIZE)) == -1)
			return (-1);
		*line = ft_strjoin(tmp2, tmp);
		tmp2 = ft_strjoin(*line, NULL);
		ft_strdel(&tmp2);
		ft_strdel(&tmp);
	}
	*line = get_next_line_result(*line, &save);
	ft_putnbr(ret);
	return (ret == 0 ? 0 : 1);
}
