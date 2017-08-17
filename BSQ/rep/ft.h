/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 21:28:45 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/15 21:28:46 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_cell
{
	int		x;
	int		y;
	int		max_square;
}					t_cell;

typedef struct		s_map
{
	char	free;
	char	obstacle;
	char	full;
	int		size;
	int		l_width;
}					t_map;

int					read_minds(char *file_name);

t_map				fill_map_info(char *file_name);

int					file_or_stream(char *file_name);

int					min(int a, int b, int c);

void				skip_f_l(int fd);

int					get_calculating(char *file_name, t_map map_info);

void				print_data(short unsigned **result,
					t_cell primary, t_map map_info);

int					utl_new_line(int *cell,
						int *line, t_map map_info);

void				utl_free_zone(unsigned short int **result,
						int line, int cell, t_cell *primary);

short unsigned int	**memmory_and_zeros(t_map map_info);

void				free_map(short unsigned **result, t_map map_info);

int					ft_atoi(char *str);

#endif
