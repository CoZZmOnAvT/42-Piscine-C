/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 21:15:28 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/06 21:15:30 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

void		fill_start_field_helper(t_square *tmp, t_cell value, char **av)
{
	int			it;

	it = 0;
	while (it < 9)
		tmp->cells[value.y][value.x].p_v[it++] = 0;
	tmp->wrong_data = false;
	if (av[value.y + 1][value.x] == '.')
		tmp->cells[value.y][value.x].value = 0;
	else if (av[value.y + 1][value.x] >= '0'
		&& av[value.y + 1][value.x] <= '9')
		tmp->cells[value.y][value.x].value =
			av[value.y + 1][value.x] - '0';
	else
	{
		tmp->wrong_data = true;
	}
}

t_square	fill_start_field(char **av, int ac)
{
	t_cell		value;
	t_square	tmp;

	if (ac != 10)
	{
		tmp.wrong_data = true;
		return (tmp);
	}
	value.y = 0;
	while (value.y < ac - 1)
	{
		value.x = 0;
		while (value.x < ac - 1)
		{
			fill_start_field_helper(&tmp, value, av);
			if (tmp.wrong_data == true)
				return (tmp);
			value.x++;
		}
		value.y++;
	}
	return (tmp);
}

t_bool		place_is_avalible(t_cell value, int p_v, t_square field)
{
	if (p_v != 0 &&
		(!row_is_free(value, p_v, field)
		|| !col_is_free(value, p_v, field)
		|| !square_is_free(value, p_v, field)))
		return (false);
	return (true);
}

t_bool		input_data_is_coorect(t_square field)
{
	t_cell	value;
	int		hints_given;

	if (field.wrong_data == true)
		return (false);
	value.y = 0;
	hints_given = 0;
	while (value.y < 9)
	{
		value.x = 0;
		while (value.x < 9)
		{
			if (!place_is_avalible(value,
				field.cells[value.y][value.x].value, field))
				return (false);
			if (field.cells[value.y][value.x].value != 0)
				hints_given++;
			value.x++;
		}
		value.y++;
	}
	if (hints_given <= 16)
		return (false);
	return (true);
}
