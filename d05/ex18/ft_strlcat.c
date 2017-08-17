/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 18:27:34 by pgritsen          #+#    #+#             */
/*   Updated: 2017/07/31 18:27:35 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				str_len(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_it;
	unsigned int	dest_length;
	unsigned int	resault;
	unsigned int	src_it;

	dest_length = str_len(dest);
	resault = dest_length + str_len(src);
	if (size < dest_length)
		resault -= (dest_length - size);
	dest_it = dest_length;
	src_it = 0;
	while (src[src_it] && (src_it + dest_it) < size - 1)
	{
		dest[dest_it + src_it] = src[src_it];
		src_it++;
	}
	dest[dest_it + src_it] = 0;
	return (resault);
}
