/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 19:16:49 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/02 19:16:50 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned long	ft_strlen(char *str)
{
	unsigned long	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	it;

	it = 0;
	while (src[it] && it < size - 1)
	{
		dest[it] = src[it];
		it++;
	}
	dest[it] = 0;
	return ((unsigned int)ft_strlen(src));
}

char			*ft_strdup(char *src)
{
	char			*clone;
	unsigned long	src_len;

	src_len = ft_strlen(src);
	clone = (char *)malloc(src_len + 1);
	ft_strlcpy(clone, src, src_len + 1);
	if (ft_strlen(clone) != src_len)
		return (0);
	return (clone);
}
