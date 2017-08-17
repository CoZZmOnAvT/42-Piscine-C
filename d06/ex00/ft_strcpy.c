/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 11:45:43 by pgritsen          #+#    #+#             */
/*   Updated: 2017/07/31 11:45:49 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int symb_it;

	symb_it = 0;
	while (src[symb_it])
	{
		dest[symb_it] = src[symb_it];
		symb_it++;
	}
	dest[symb_it] = 0;
	return (dest);
}
