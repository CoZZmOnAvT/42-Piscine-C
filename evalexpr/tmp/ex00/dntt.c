/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dntt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 18:20:45 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/12 18:20:46 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t.h"
#include "stack.h"
#include "t_opp.h"
#include <stdio.h>

void		push_operands(char *str, int *from, t_stack **operands)
{
	if (str[*from] >= '0' && str[*from] <= '9')
	{
		c_push_front(operands, ft_atoi(str + *from));
		while (str[*from] >= '0' && str[*from] <= '9')
			*from = *from + 1;
	}
}

void		clear_operations(char *str, int from, t_stack **operands,
	t_stack **operators)
{
	int		num_tmp;
	int		act_it;
	char	opp_tmp;

	if ((act_it = found_action(str[from])) != -1)
	{
		while (get_priority(str[from]) <=
				get_priority((char)c_get_data(*operators)))
		{
			opp_tmp = (char)c_shift_back_data(operators);
			num_tmp = g_opp[found_action(opp_tmp)].action(
				c_shift_back_data(operands), c_shift_back_data(operands));
			c_push_front(operands, num_tmp);
		}
		c_push_front(operators, (int)str[from]);
	}
}

void		parentheses_detection(char *str, int *from, t_stack **operands)
{
	int		parentheses_t_s;
	int		num_tmp;
	int		to_it;

	if (str[*from] == '(')
	{
		to_it = *from;
		parentheses_t_s = 0;
		while (str[++to_it])
		{
			if (str[to_it] == '(')
				parentheses_t_s++;
			else if (str[to_it] == ')' && !parentheses_t_s)
				break ;
			else if (str[to_it] == ')')
				parentheses_t_s--;
		}
		num_tmp = calculate(str, *from + 1, to_it);
		c_push_front(operands, num_tmp);
		*from = to_it;
	}
}

int			calculate(char *str, int from, int to)
{
	t_stack	*operands;
	t_stack	*operators;
	char	opp_tmp;
	int		num_tmp;

	operands = 0;
	operators = 0;
	while (str[from] && from < to)
	{
		push_operands(str, &from, &operands);
		clear_operations(str, from, &operands, &operators);
		parentheses_detection(str, &from, &operands);
		from++;
	}
	opp_tmp = (char)c_shift_back_data(&operators);
	while (opp_tmp)
	{
		num_tmp = g_opp[found_action(opp_tmp)].action(
			c_shift_back_data(&operands), c_shift_back_data(&operands));
		c_push_front(&operands, num_tmp);
		opp_tmp = (char)c_shift_back_data(&operators);
	}
	return (operands->data);
}
