/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 18:13:02 by pgritsen          #+#    #+#             */
/*   Updated: 2017/07/31 18:13:04 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long	ft_strlen(char *str);

char	*ft_strncat(char *dest, char *src, int nb)
{
	int		dest_it;
	int		src_it;

	dest_it = (int)ft_strlen(dest);
	src_it = 0;
	while (src[src_it] && src_it < nb)
	{
		dest[dest_it + src_it] = src[src_it];
		src_it++;
	}
	dest[dest_it + src_it] = 0;
	return (dest);
}
