/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 17:56:17 by pgritsen          #+#    #+#             */
/*   Updated: 2017/07/31 17:56:19 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		str_len(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int		dest_it;
	int		src_it;

	dest_it = str_len(dest);
	src_it = 0;
	while (src[src_it])
	{
		dest[dest_it + src_it] = src[src_it];
		src_it++;
	}
	dest[dest_it + src_it] = 0;
	return (dest);
}
