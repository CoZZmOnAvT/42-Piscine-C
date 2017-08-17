/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 13:24:53 by pgritsen          #+#    #+#             */
/*   Updated: 2017/07/27 23:26:19 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_putnbr(int nb)
{
	int del;
	int tmp;

	del = 1;
	while (nb / (del * 10) != 0)
	{
		del = del * 10;
	}
	if (nb < 0)
		ft_putchar('-');
	while (del >= 1)
	{
		tmp = nb / del;
		ft_putchar(tmp + 48);
		nb = nb % del;
		del /= 10;
	}
}
