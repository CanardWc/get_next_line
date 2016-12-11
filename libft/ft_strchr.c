/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:45:03 by fgrea             #+#    #+#             */
/*   Updated: 2016/11/18 18:32:01 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ca;

	ca = (char)c;
	while (*s)
	{
		if (*s == ca)
			return ((char *)s);
		s++;
		if (*s == ca)
			return ((char *)s);
	}
	return (NULL);
}
