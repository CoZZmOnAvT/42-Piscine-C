/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 12:07:20 by pgritsen          #+#    #+#             */
/*   Updated: 2017/07/31 12:07:24 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	symb_it;

	symb_it = 0;
	while (src[symb_it] && symb_it < n)
	{
		dest[symb_it] = src[symb_it];
		symb_it++;
	}
	dest[symb_it] = 0;
	return (dest);
}
