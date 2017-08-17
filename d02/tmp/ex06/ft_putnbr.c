/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 13:24:53 by pgritsen          #+#    #+#             */
/*   Updated: 2017/07/28 10:25:38 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr(int nb)
{
	long int del;
	long int tmp;
	long int nb_m;

	del = 1;
	nb_m = nb;
	while (nb_m / (del * 10) != 0)
	{
		del = del * 10;
	}
	if (nb_m < 0)
	{
		ft_putchar('-');
		nb_m *= -1;
	}
	while (del >= 1)
	{
		tmp = nb_m / del;
		ft_putchar(tmp + 48);
		nb_m = nb_m % del;
		del /= 10;
	}
}
