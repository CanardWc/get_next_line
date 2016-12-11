/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:08:42 by fgrea             #+#    #+#             */
/*   Updated: 2016/11/20 19:05:42 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		s;
	int		i;

	s = 1;
	i = 0;
	while (*str == ' ' || *str == '\r' || *str == '\f' || *str == '\v' \
			|| *str == '\n' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	while (*str > 47 && *str < 58 && *str != 92)
	{
		i = i * 10;
		i = i + (*str - '0');
		str++;
	}
	if (s == -1)
		i = i * s;
	return (i);
}