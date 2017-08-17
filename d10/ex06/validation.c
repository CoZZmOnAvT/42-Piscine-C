/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 19:13:39 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/07 19:13:40 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_operation	g_action[] = {
	&plus,
	&minus,
	&mult,
	&divide,
	&modulo
};

t_bool		validate_operator(char c)
{
	int		it;

	it = 0;
	while (OPERATORS[it])
		if (OPERATORS[it++] == c)
			return (true);
	return (false);
}

t_bool		input_data_correct(char **av)
{
	if (av[2][1])
		return (false);
	if (!validate_operator(av[2][0]))
		return (false);
	return (true);
}

void		is_negative(long int *mult, char sign, int *it)
{
	if (sign == '-')
	{
		*it = *it + 1;
		*mult = *mult / 10;
		*mult = *mult * (-1);
	}
	else if (sign == '+')
	{
		*it = *it + 1;
		*mult = *mult / 10;
	}
}

int			ft_atoi(char *str)
{
	int			num_start;
	int			mult_it;
	long int	mult;
	int			resault;

	num_start = 0;
	if (str[num_start] == 0)
		return (0);
	while (((str[num_start] > '\10' && str[num_start] <= '\16')
		|| str[num_start] == '\40') && str[num_start] != '-')
		num_start++;
	mult = 1;
	mult_it = num_start;
	while (str[++mult_it] >= '0' && str[mult_it] <= '9')
		mult *= 10;
	is_negative(&mult, str[num_start], &num_start);
	resault = 0;
	while (str[num_start] >= '0' && str[num_start] <= '9')
	{
		resault += (str[num_start++] - 48) * mult;
		mult /= 10;
	}
	return (resault);
}

void		calculate(char *num1, char operator, char *num2)
{
	int		operator_pos;

	operator_pos = 0;
	while (OPERATORS[operator_pos] != operator)
		operator_pos++;
	g_action[operator_pos](num1, num2);
	if (g_error_caght == false)
		write(1, "\n", 1);
}
