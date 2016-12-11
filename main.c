/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:41:53 by fgrea             #+#    #+#             */
/*   Updated: 2016/12/11 19:46:59 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int		get_next_line(const int fd, char **line);

int		main(int argc, char **argv)
{
	char	*lol;
	int		fd;
	int 	r;

	argc = 2;
	lol = ft_strnew(BUFF_SIZE);
	fd = open(argv[1], O_RDONLY);
	r = 1;
	while (r == 1)
	{
		r = get_next_line(fd, &lol);
		printf("\n\n%s\n\n", lol);
	}
	return (0);
}
