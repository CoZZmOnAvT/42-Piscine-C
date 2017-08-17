/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 22:38:33 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/06 22:38:34 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

void	delete_from_raw(t_cell cell, t_square *field)
{
	t_cell tmp_cell;

	tmp_cell.y = 0;
	while (tmp_cell.y < 9)
	{
		if (tmp_cell.y == cell.y)
		{
			tmp_cell.y++;
			continue ;
		}
		if (is_val_in_array(cell.value, field->cells[tmp_cell.y][cell.x].p_v))
			delete_p_v(&field->cells[tmp_cell.y][cell.x], cell.value);
		tmp_cell.y++;
	}
}

void	delete_from_colmn(t_cell cell, t_square *field)
{
	t_cell tmp_cell;

	tmp_cell.x = 0;
	while (tmp_cell.x < 9)
	{
		if (tmp_cell.x == cell.x)
		{
			tmp_cell.x++;
			continue ;
		}
		if (is_val_in_array(cell.value, field->cells[cell.y][tmp_cell.x].p_v))
			delete_p_v(&field->cells[cell.y][tmp_cell.x], cell.value);
		tmp_cell.x++;
	}
}

void	delete_from_square(t_cell cell, t_square *field)
{
	int		square_x;
	int		square_y;

	square_y = cell.y - (cell.y % 3);
	while (square_y < cell.y - (cell.y % 3) + 3)
	{
		square_x = cell.x - (cell.x % 3);
		while (square_x < cell.x - (cell.x % 3) + 3)
		{
			if (square_y == cell.y && square_x == cell.x)
			{
				square_x++;
				continue ;
			}
			if (is_val_in_array(cell.value,
				field->cells[square_y][square_x].p_v))
				delete_p_v(&field->cells[square_y][square_x], cell.value);
			square_x++;
		}
		square_y++;
	}
}
