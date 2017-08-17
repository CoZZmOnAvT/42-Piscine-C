/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 21:31:32 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/06 21:31:34 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

int			count_p_v(t_cell cell)
{
	int		it;
	int		len;

	it = 0;
	len = 0;
	while (it < 9)
	{
		if (cell.p_v[it])
			len++;
		it++;
	}
	return (len);
}

void		delete_p_v(t_cell *cell, int p_v)
{
	int		it;
	t_bool	found;

	it = 0;
	found = false;
	if (cell->p_v[0] == 0)
		return ;
	while (cell->p_v[it])
	{
		if (cell->p_v[it] == p_v)
		{
			found = true;
			break ;
		}
		it++;
	}
	if (found == false)
		return ;
	while (it < 8)
	{
		cell->p_v[it] = cell->p_v[it + 1];
		it++;
	}
	cell->p_v[it + 1] = 0;
}

t_bool		row_is_free(t_cell s_value, int p_v, t_square field)
{
	int		it_c;
	int		it_pv;

	it_c = 0;
	while (it_c < 9)
	{
		if (it_c == s_value.x)
		{
			it_c++;
			continue ;
		}
		it_pv = 0;
		if (field.cells[s_value.y][it_c].value == p_v)
			return (false);
		it_c++;
	}
	return (true);
}

t_bool		col_is_free(t_cell s_value, int p_v, t_square field)
{
	int		it_r;
	int		it_pv;

	it_r = 0;
	while (it_r < 9)
	{
		if (it_r == s_value.y)
		{
			it_r++;
			continue ;
		}
		it_pv = 0;
		if (field.cells[it_r][s_value.x].value == p_v)
			return (false);
		it_r++;
	}
	return (true);
}

t_bool		square_is_free(t_cell s_value, int p_v, t_square field)
{
	int		square_x;
	int		square_y;

	square_y = s_value.y - (s_value.y % 3);
	while (square_y < s_value.y - (s_value.y % 3) + 3)
	{
		square_x = s_value.x - (s_value.x % 3);
		while (square_x < s_value.x - (s_value.x % 3) + 3)
		{
			if (square_y == s_value.y && square_x == s_value.x)
			{
				square_x++;
				continue ;
			}
			if (field.cells[square_y][square_x].value == p_v)
				return (false);
			square_x++;
		}
		square_y++;
	}
	return (true);
}
