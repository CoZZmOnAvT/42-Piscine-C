/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 19:50:31 by pgritsen          #+#    #+#             */
/*   Updated: 2017/07/31 19:50:32 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long	ft_strlen(char *str);

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
