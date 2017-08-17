/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 12:13:38 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/12 12:13:39 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef	struct	s_stack
{
	int				data;
	struct s_stack	*next;
}				t_stack;

t_stack			*c_create_elem(int data);

void			c_push_front(t_stack **stack, int data);

int				c_shift_back_data(t_stack **stack);

int				c_get_data(t_stack	*stack);

#endif
