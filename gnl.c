/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 15:18:47 by fgrea             #+#    #+#             */
/*   Updated: 2016/12/11 15:44:50 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		gnl(const int fd, char **line)
{
	static char		*save;
	char			*tmp;
	int				ret;

	ret = 0;
	save = NULL;
	tmp = NULL;
	*line = ft_strnew(BUFF_SIZE);
	if (save != NULL)
		ft_strcpy(*line, save);
	while (get_next_line_check(*line) == 1)
	{
		tmp = ft_strnew(BUFF_SIZE);
		if ((ret = read(fd, tmp, BUFF_SIZE)) == -1)
			return (-1);
		*line = ft_strjoin(*line, tmp);
		tmp = ft_strdel(&tmp);
	}
	return (get_next_line_result(*line, save));
}
