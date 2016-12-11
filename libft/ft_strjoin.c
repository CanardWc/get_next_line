/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 04:30:26 by fgrea             #+#    #+#             */
/*   Updated: 2016/12/11 16:48:07 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		y;
	char	*s3;

	if (ft_strlen(s1) == 0 && ft_strlen(s2) == 0)
		return (NULL);
	if ((s3 = (char *)malloc(sizeof(s3) * \
					(ft_strlen(s1) + ft_strlen(s2) + 1))) == NULL)
		return (NULL);
	i = 0;
	y = 0;
	while (s1 != NULL && s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2 != NULL && s2[y])
	{
		s3[i] = s2[y];
		i++;
		y++;
	}
	s3[i] = '\0';
	return (s3);
}
