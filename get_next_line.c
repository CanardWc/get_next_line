/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:06:30 by fgrea             #+#    #+#             */
/*   Updated: 2021/01/05 19:31:04 by fgrea            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dst;
	char	*ret;

	if (!(dst = (char *)malloc((ft_strlen(s1) + \
						ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	ret = dst;
	dst = ft_memcpy(dst, s1, ft_strlen(s1));
	dst += ft_strlen(s1);
	dst = ft_memcpy(dst, s2, ft_strlen(s2));
	dst += ft_strlen(s2);
	*dst = '\0';
	return (ret);
}

char	*ft_strdup(const char *s1)
{
	char	*ret;

	if (!(ret = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char))))
		return (NULL);
	*(ret + ft_strlen(s1)) = 0;
	return (ft_memcpy(ret, s1, ft_strlen(s1)));
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (n == 0)
		return (NULL);
	while (--n > 0 && *(unsigned char *)s != (unsigned char)c)
		s++;
	return ((n == 0 && *(unsigned char *)s != (unsigned char)c) ? \
			NULL : (void *)s);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*ret;

	if (!src && !dst)
		return (NULL);
	ret = dst;
	while (n-- > 0)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	static char	*r[4096];
	char		buf[BUFF_SIZE];
	ssize_t		read_ret;
	char		*tmp;
	char		*eol;

	read_ret = 1;
	while(read_ret > 0 && !(eol = ft_memchr(r[fd], '\n', ft_strlen(r[fd]))))
	{
		read_ret = read(fd, buf, BUFF_SIZE);
		tmp = ft_strjoin(r[fd], buf);
		free(r[fd]);
		r[fd] = tmp;
	}
	if (read_ret == -1 || !r[fd])
		return (-1);	
	*line = ft_substr(r[fd], 0, eol - r[fd] + 1);
	tmp = ft_substr(r[fd], eol - r[fd] + 1, ft_strlen(r[fd]) - (eol - r[fd]));
	free(r[fd]);
	r[fd] = tmp;
	return (read_ret == 0 ? 0 : 1);
}
/*
#include <fcntl.h>


int		main(void)
{
	char	*line;
	int		fd;

	fd = open("lol.txt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		write(1, line, ft_strlen(line));
		free(line);
	}
	close(fd);
	return (0);
}*/
