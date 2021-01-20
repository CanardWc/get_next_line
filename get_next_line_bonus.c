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
	static char	*r[10240];
	char		buf[BUFFER_SIZE + 1];
	ssize_t		read_ret;
	char		*tmp;
	char		*eol;

	read_ret = -1;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	while(read_ret != 0 && !(eol = ft_memchr(r[fd], '\n', ft_strlen(r[fd]))))
	{
		read_ret = read(fd, buf, BUFFER_SIZE);
		buf[read_ret] = 0;
		tmp = ft_strjoin(r[fd], buf);
		free(r[fd]);
		r[fd] = tmp;
		if (read_ret == -1 || !r[fd])
			return (-1);
	}
	*line = ft_substr(r[fd], 0, eol ? eol - r[fd] : ft_strlen(r[fd]));
	tmp = ft_substr(r[fd], (eol - r[fd]) + 1, ft_strlen(r[fd]) - (eol - r[fd]));
	free(r[fd]);
	r[fd] = tmp;
	return (read_ret == 0 ? 0 : 1);
}
