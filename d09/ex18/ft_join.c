/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 11:54:22 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/04 11:54:23 by pgritsen         ###   ########.fr       */
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

char			*ft_strcat(char *dest, char *src)
{
	int		dest_it;
	int		src_it;

	dest_it = (int)ft_strlen(dest);
	src_it = 0;
	while (src[src_it])
	{
		dest[dest_it + src_it] = src[src_it];
		src_it++;
	}
	dest[dest_it + src_it] = 0;
	return (dest);
}

char			*ft_join(char **tab, char *sep)
{
	int		it;
	int		words_count;
	int		size_of_string;
	int		sep_len;
	char	*str;

	size_of_string = 0;
	sep_len = (int)ft_strlen(sep);
	it = 0;
	words_count = 0;
	while (tab[it])
	{
		size_of_string += (int)ft_strlen(tab[it++]) + sep_len;
		words_count++;
	}
	str = (char *)malloc(sizeof(char) * size_of_string);
	it = 0;
	while (tab[it])
	{
		ft_strcat(str, tab[it++]);
		if (it < words_count)
			ft_strcat(str, sep);
	}
	return (str);
}
