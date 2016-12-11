/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 01:02:32 by fgrea             #+#    #+#             */
/*   Updated: 2016/11/23 22:19:01 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if((str = (char *)malloc(sizeof(str) * (size + 1))) == NULL)
		return (NULL);
	ft_memset(str, (int)'\0', (size + 1));
	return (str);
}
