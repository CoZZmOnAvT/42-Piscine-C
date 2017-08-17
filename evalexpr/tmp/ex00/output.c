/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 18:22:47 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/12 18:22:48 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long int	mult;
	long int	nb_t;

	mult = 1;
	nb_t = nb;
	if (nb_t < 0)
	{
		ft_putchar('-');
		nb_t *= -1;
	}
	if (nb_t == 0)
		ft_putchar('0');
	while (nb_t / mult != 0)
		mult *= 10;
	while (mult > 1)
	{
		mult /= 10;
		if (mult == 0)
			ft_putchar(nb_t + 48);
		else
			ft_putchar(nb_t / mult + 48);
		nb_t %= mult;
	}
}
