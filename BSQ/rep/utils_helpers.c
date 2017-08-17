/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 00:45:44 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/16 00:45:45 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		file_or_stream(char *file_name)
{
	if (file_name)
		return (open(file_name, O_RDONLY));
	else
		return (0);
}

void	skip_f_l(int fd)
{
	char	tmp;

	while (read(fd, &tmp, 1))
		if (tmp == '\n')
			break ;
}

int		min(int a, int b, int c)
{
	int min;

	min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return (min);
}

int		utl_new_line(int *cell, int *line, t_map map_info)
{
	if (*cell != map_info.l_width)
		return (0);
	*cell = 0;
	*line = *line + 1;
	return (1);
}

void	utl_free_zone(unsigned short int **result, int line,
						int cell, t_cell *primary)
{
	result[line + 1][cell + 1] = min(result[line + 1][cell],
					result[line][cell], result[line][cell + 1]) + 1;
	if (result[line + 1][cell + 1] > primary->max_square)
	{
		primary->max_square = result[line + 1][cell + 1];
		primary->x = cell;
		primary->y = line;
	}
}
