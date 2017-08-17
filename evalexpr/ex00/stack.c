/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 12:12:42 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/12 12:12:43 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

t_stack		*c_create_elem(int data)
{
	t_stack	*tmp;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	if (tmp)
	{
		tmp->data = data;
		tmp->next = 0;
	}
	return (tmp);
}

void		c_push_front(t_stack **stack, int data)
{
	t_stack	*tmp;

	tmp = *stack;
	*stack = c_create_elem(data);
	(*stack)->next = tmp;
}

int			c_shift_back_data(t_stack **stack)
{
	int			tmp;
	t_stack		*t_s;

	if (!(*stack))
		return (0);
	tmp = (*stack)->data;
	t_s = (*stack)->next;
	free(*stack);
	*stack = t_s;
	return (tmp);
}

int			c_get_data(t_stack *stack)
{
	int		tmp;

	if (!stack)
		return (0);
	tmp = stack->data;
	return (tmp);
}
