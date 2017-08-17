/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 19:33:02 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/07 19:33:05 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	plus(char *num1, char *num2)
{
	int		i_num1;
	int		i_num2;

	i_num1 = ft_atoi(num1);
	i_num2 = ft_atoi(num2);
	ft_putnbr(i_num1 + i_num2);
}

void	minus(char *num1, char *num2)
{
	int		i_num1;
	int		i_num2;

	i_num1 = ft_atoi(num1);
	i_num2 = ft_atoi(num2);
	ft_putnbr(i_num1 - i_num2);
}

void	mult(char *num1, char *num2)
{
	int		i_num1;
	int		i_num2;

	i_num1 = ft_atoi(num1);
	i_num2 = ft_atoi(num2);
	ft_putnbr(i_num1 * i_num2);
}

void	divide(char *num1, char *num2)
{
	int		i_num1;
	int		i_num2;

	i_num1 = ft_atoi(num1);
	i_num2 = ft_atoi(num2);
	if (i_num2 == 0)
	{
		g_error_caght = true;
		write(1, "Stop : division by zero\n", 24);
	}
	else
		ft_putnbr(i_num1 / i_num2);
}

void	modulo(char *num1, char *num2)
{
	int		i_num1;
	int		i_num2;

	i_num1 = ft_atoi(num1);
	i_num2 = ft_atoi(num2);
	if (i_num2 == 0)
	{
		g_error_caght = true;
		write(1, "Stop : modulo by zero\n", 22);
	}
	else
		ft_putnbr(i_num1 % i_num2);
}
