/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 00:47:33 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/16 00:47:34 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int					read_minds(char *file_name)
{
	t_map	map_info;

	map_info = fill_map_info(file_name);
	if (!map_info.full)
		return (0);
	if (!get_calculating(file_name, map_info))
		return (0);
	return (1);
}

short unsigned int	**read_firts_line(char *file_name, t_map *map_info,
										int *fd, t_cell *primary)
{
	int					cell;
	char				*f_l_buff;
	short unsigned int	**result;

	f_l_buff = (char *)malloc(sizeof(char) * 65536);
	if ((*fd = file_or_stream(file_name)) == -1)
		return (0);
	if (*fd)
		skip_f_l(*fd);
	map_info->l_width = -1;
	while (read(*fd, &f_l_buff[++(map_info->l_width)], 1))
		if (f_l_buff[map_info->l_width] == '\n')
			break ;
	if (map_info->l_width < 1)
		return (0);
	result = memmory_and_zeros(*map_info);
	cell = -1;
	primary->max_square = 0;
	while (f_l_buff[++cell] != '\n')
		if (f_l_buff[cell] == map_info->free)
			utl_free_zone(result, 0, cell, primary);
		else if (f_l_buff[cell] != map_info->obstacle)
			return (0);
	free(f_l_buff);
	return (result);
}

int					get_the_biggest_square(int fd, t_map map_info,
					short unsigned int **result, t_cell *primary)
{
	char	tmp_buff;
	int		line;
	int		cell;

	line = 1;
	cell = 0;
	while (read(fd, &tmp_buff, 1))
	{
		if (tmp_buff == '\n')
		{
			if (!utl_new_line(&cell, &line, map_info))
				return (0);
			continue ;
		}
		if (tmp_buff == map_info.free && line < map_info.size)
			utl_free_zone(result, line, cell, primary);
		else if (tmp_buff != map_info.obstacle)
			return (0);
		cell++;
	}
	if (line != map_info.size)
		return (0);
	return (1);
}

int					get_calculating(char *file_name, t_map map_info)
{
	short unsigned int	**result;
	int					fd;
	t_cell				primary;

	if (!(result = read_firts_line(file_name, &map_info, &fd, &primary)))
		return (0);
	if (!get_the_biggest_square(fd, map_info, result, &primary))
		return (0);
	print_data(result, primary, map_info);
	free_map(result, map_info);
	return (1);
}
