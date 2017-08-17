/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 23:44:32 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/05 23:44:34 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HEADER_H
# define MAIN_HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_cell
{
	int x;
	int y;
	int	value;
	int p_v[9];
}				t_cell;

typedef enum	e_bool
{
	false, true
}				t_bool;

typedef struct	s_square
{
	t_cell cells[9][9];
	t_bool wrong_data;
}				t_square;

t_bool			row_is_free(t_cell s_value, int p_v, t_square field);

t_bool			col_is_free(t_cell s_value, int p_v, t_square field);

t_bool			square_is_free(t_cell s_value, int p_v, t_square field);

t_square		fill_start_field(char **av, int ac);

t_bool			input_data_is_coorect(t_square field);

t_square		fill_posible_values(t_square start_field, int ac);

int				count_p_v(t_cell cell);

t_bool			is_val_in_array(int val, int *array);

void			delete_p_v(t_cell *cell, int p_v);

void			delete_from_raw(t_cell cell, t_square *field);

void			delete_from_colmn(t_cell cell, t_square *field);

void			delete_from_square(t_cell cell, t_square *field);

#endif
