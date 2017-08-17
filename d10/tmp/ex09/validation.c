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

#include "ft_opp.h"

int			ft_strcmp(char *s1, char *s2)
{
	int		it;

	it = 0;
	while (s1[it] > 0 || s2[it] > 0)
	{
		if (s1[it] != s2[it])
			return ((unsigned int)s1[it] - (unsigned int)s2[it]);
		it++;
	}
	return (0);
}

t_bool		input_data_correct(char **av)
{
	t_bool	operator_found;
	int		it;

	operator_found = false;
	it = -1;
	while (g_opptab[++it].opp)
		if (ft_strcmp(av[2], g_opptab[it].opp) == 0)
		{
			operator_found = true;
			break ;
		}
	if (operator_found == false)
	{
		ft_usage();
		return (false);
	}
	return (true);
}

void		calculate(char *num1, char *operator, char *num2)
{
	int		opp_it;

	opp_it = 0;
	while (ft_strcmp(g_opptab[opp_it].opp, operator) != 0)
		opp_it++;
	g_opptab[opp_it].t_act(num1, num2);
	if (g_error_caght == false)
		write(1, "\n", 1);
}

void		ft_usage(void)
{
	int		it;

	write(1, "error : only [ ", 15);
	it = -1;
	while (g_opptab[++it].opp)
	{
		ft_putstr(g_opptab[it].opp);
		if (g_opptab[it].opp[0])
			ft_putchar(' ');
	}
	write(1, "] are accepted.\n", 16);
	g_error_caght = true;
}
