/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 13:41:01 by fgrea             #+#    #+#             */
/*   Updated: 2021/01/05 19:15:26 by fgrea            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*dst;

	if (!s)
		return (NULL);
	len = len > ft_strlen(s) ? ft_strlen(s) : len;
	if (!(dst = (char *)malloc((len == 0 || start >= ft_strlen(s) \
						? 1 : len + 1) * sizeof(char))))
		return (NULL);
	ret = dst;
	if (start < ft_strlen(s))
		while (s[start] && len--)
			*dst++ = s[start++];
	*dst = '\0';
	return (ret);
}
