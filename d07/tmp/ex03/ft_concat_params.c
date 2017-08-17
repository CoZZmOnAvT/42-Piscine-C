/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 21:48:15 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/02 21:48:16 by pgritsen         ###   ########.fr       */
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

char			*ft_concat_params(int argc, char **argv)
{
	int		it;
	int		size_of_arr;
	char	*dest_arr;

	it = 1;
	size_of_arr = 0;
	while (it < argc)
		size_of_arr += (int)ft_strlen(argv[it++]) + 1;
	dest_arr = (char*)malloc(sizeof(char) * size_of_arr);
	it = 1;
	while (it < argc)
	{
		ft_strcat(dest_arr, argv[it]);
		it++;
		if (it < argc)
			ft_strcat(dest_arr, "\n");
	}
	dest_arr[size_of_arr - 1] = 0;
	return (dest_arr);
}
