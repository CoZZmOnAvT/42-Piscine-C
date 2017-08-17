/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_is_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 21:29:37 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/06 21:29:39 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

t_cell		add_values(t_cell value, t_square field)
{
	int		p_v;
	int		it;
	t_cell	tmp;
	t_bool	num_corr;

	p_v = 1;
	it = 0;
	tmp = value;
	while (p_v <= 9)
	{
		num_corr = false;
		if (row_is_free(value, p_v, field) && col_is_free(value, p_v, field)
			&& square_is_free(value, p_v, field))
			num_corr = true;
		if (num_corr)
		{
			tmp.p_v[it] = p_v;
			it++;
		}
		p_v++;
	}
	while (it < 9)
		tmp.p_v[it++] = 0;
	return (tmp);
}

void		fill_posible_values_helper(t_square start_field,
										t_cell value, t_square *tmp)
{
	int			it;
	t_cell		tmp_val;

	if (start_field.cells[value.y][value.x].value == 0)
	{
		tmp_val = add_values(value, start_field);
		if (tmp_val.p_v[0] == 0)
			tmp->wrong_data = true;
		tmp->cells[value.y][value.x] = tmp_val;
		tmp->cells[value.y][value.x].value = 0;
	}
	else
	{
		it = 0;
		while (it < 9)
			tmp->cells[value.y][value.x].p_v[it++] = 0;
		tmp->cells[value.y][value.x].value =
			start_field.cells[value.y][value.x].value;
	}
}

t_square	fill_posible_values(t_square start_field, int ac)
{
	t_cell		value;
	t_square	tmp;

	value.y = 0;
	while (value.y < ac - 1)
	{
		value.x = 0;
		while (value.x < ac - 1)
		{
			fill_posible_values_helper(start_field, value, &tmp);
			if (tmp.wrong_data == true)
				return (tmp);
			value.x++;
		}
		value.y++;
	}
	return (tmp);
}
