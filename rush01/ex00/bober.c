/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bober.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 23:38:29 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/05 23:38:31 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

t_bool		is_val_in_array(int val, int *array)
{
	int		it;

	it = 0;
	while (it < 9)
	{
		if (array[it] == val)
			return (true);
		it++;
	}
	return (false);
}

void		clear_other_p_v(t_cell cell, t_square *field)
{
	delete_from_raw(cell, field);
	delete_from_colmn(cell, field);
	delete_from_square(cell, field);
}

void		filter_alone_p_v(t_square *field)
{
	int		val;
	t_cell	cell;

	cell.y = 0;
	while (cell.y < 9)
	{
		cell.x = 0;
		while (cell.x < 9)
		{
			if (field->cells[cell.y][cell.x].value == 0
				&& count_p_v(field->cells[cell.y][cell.x]) == 1)
			{
				val = field->cells[cell.y][cell.x].p_v[0];
				field->cells[cell.y][cell.x].value = val;
				cell.value = val;
				clear_other_p_v(cell, field);
				filter_alone_p_v(field);
			}
			cell.x++;
		}
		cell.y++;
	}
}

void		print_sudoku(t_square field)
{
	int			it_x;
	int			it_y;
	char		num;

	it_y = 0;
	while (it_y < 9)
	{
		it_x = 0;
		while (it_x < 9)
		{
			num = field.cells[it_y][it_x].value + '0';
			write(1, &num, 1);
			if (it_x < 8)
				write(1, " ", 1);
			it_x++;
		}
		write(1, "\n", 1);
		it_y++;
	}
}

int			main(int argc, char **argv)
{
	t_square	field;

	field = fill_start_field(argv, argc);
	if (input_data_is_coorect(field) == false)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	field = fill_posible_values(field, argc);
	filter_alone_p_v(&field);
	print_sudoku(field);
	return (0);
}
