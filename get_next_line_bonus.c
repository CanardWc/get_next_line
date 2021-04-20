/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:53:57 by fgrea             #+#    #+#             */
/*   Updated: 2021/04/20 15:22:44 by fgrea            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (n == 0)
		return (NULL);
	while (--n > 0 && *(unsigned char *)s != (unsigned char)c)
		s++;
	if (n == 0 && *(unsigned char *)s != (unsigned char)c)
		return (NULL);
	else
		return ((void *)s);
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

int	la_norme_cette_sale_grande_tante(int fd, char **r, char **eol)
{
	char		buf[BUFFER_SIZE + 1];
	ssize_t		read_ret;
	char		*tmp;

	read_ret = -2;
	*eol = ft_memchr(*r, '\n', ft_strlen(*r));
	while (read_ret != 0 && !*eol)
	{
		read_ret = read(fd, buf, BUFFER_SIZE);
		buf[read_ret] = 0;
		tmp = ft_strjoin(*r, buf);
		free(*r);
		*r = tmp;
		if (read_ret == -1 || !*r)
			return (-1);
		*eol = ft_memchr(*r, '\n', ft_strlen(*r));
	}
	return (read_ret);
}

int		get_next_line(int fd, char **line)
{
	static char	*r[10240];
	ssize_t		read_ret;
	char		*tmp;
	char		*eol;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	read_ret = la_norme_cette_sale_grande_tante(fd, &r[fd], &eol);
	if (read_ret == -1)
		return (-1);
	if (eol)
		*line = ft_substr(r[fd], 0, eol - r[fd]);
	else
		*line = ft_substr(r[fd], 0, ft_strlen(r[fd]));
	tmp = ft_substr(r[fd], (eol - r[fd]) + 1, ft_strlen(r[fd]) - (eol - r[fd]));
	free(r[fd]);
	r[fd] = tmp;
	if (read_ret == 0)
		return (0);
	else
		return (1);
}
