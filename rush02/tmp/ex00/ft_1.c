/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft-1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 19:15:55 by modnosum          #+#    #+#             */
/*   Updated: 2017/08/13 19:16:23 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void			ft_putminint(void)
{
	ft_putstr("-2147483648");
}

void			ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
		ft_putminint();
	else
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
		}
		if (nbr >= 10)
		{
			ft_putnbr(nbr / 10);
			ft_putchar(nbr % 10 + '0');
		}
		if (nbr < 10)
			ft_putchar(nbr % 10 + '0');
	}
}
