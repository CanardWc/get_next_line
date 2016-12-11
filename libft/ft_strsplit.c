/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 06:05:47 by fgrea             #+#    #+#             */
/*   Updated: 2016/11/19 08:05:38 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strsplit_linecount(char const *s, char c)
{
	int		linecount;
	int		swap;

	linecount = 0;
	swap = 0;
	while (*s)
	{
		if (swap == 1 && *s == c)
			swap = 0;
		if (swap == 0 && *s != c)
		{
			swap = 1;
			linecount++;
		}
		s++;
	}
	return (linecount);
}

static int		ft_strsplit_sword(char const *s, char c)
{
	int		i;

	i = 0;
	while (*s != c && *s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		linecount;
	int		line;
	char	**array;

	line = 0;
	if (s == NULL)
		return (NULL);
	linecount = ft_strsplit_linecount(s, c);
	if ((array = (char **)malloc(sizeof(*array) * linecount + 1)) == NULL)
		return (NULL);
	while (linecount--)
	{
		while (*s == c && *s != '\0')
			s++;
		array[line] = ft_strsub(s, 0, ft_strsplit_sword(s, c));
		if (array[line] == NULL)
			return (NULL);
		s = s + ft_strsplit_sword(s, c);
		line++;
	}
	array[line] = 0;
	return (array);
}
