/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 19:31:02 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/05 19:31:04 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int it;

	it = 0;
	while (str[it] != 0)
		ft_putchar(str[it++]);
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

void	ft_show_tab(struct s_stock_par *par)
{
	int		it;
	int		argv_it;

	it = 0;
	while (par[it].str)
	{
		ft_putstr(par[it].copy);
		ft_putchar('\n');
		ft_putnbr(par[it].size_param);
		ft_putchar('\n');
		argv_it = 0;
		while (par[it].tab[argv_it])
		{
			ft_putstr(par[it].tab[argv_it]);
			ft_putchar('\n');
			argv_it++;
		}
		it++;
	}
}
