/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 21:27:59 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/15 21:28:00 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_map				fill_map_info(char *file_name)
{
	t_map	map_info;
	int		it;
	int		fd;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * 16);
	if ((fd = file_or_stream(file_name)) == -1)
		return ((t_map){0, 0, 0, 0, 0});
	it = 0;
	while (read(fd, &buffer[it], 1) && buffer[it] != '\n' && it < 16)
		it++;
	buffer[it] = 0;
	if ((map_info.size = ft_atoi(buffer)) < 1)
		return ((t_map){0, 0, 0, 0, 0});
	it = 0;
	while (it < 16 && buffer[it] >= '0' && buffer[it] <= '9')
		it++;
	map_info = (t_map){buffer[it], buffer[it + 1], buffer[it + 2],
		map_info.size, 0};
	if (buffer[it + 3] != 0)
		return ((t_map){0, 0, 0, 0, 0});
	free(buffer);
	if (fd)
		close(fd);
	return (map_info);
}

short unsigned int	**memmory_and_zeros(t_map map_info)
{
	short unsigned int	**result;
	int					line;
	int					cell;

	line = -1;
	result = (short unsigned int **)malloc(sizeof(short unsigned int *)
					* (map_info.size + 1));
	while ((++line) < map_info.size + 1)
	{
		cell = -1;
		result[line] = (short unsigned int *)malloc(sizeof(short unsigned int)
			* (map_info.l_width + 1));
		while ((++cell) < map_info.l_width + 1)
			result[line][cell] = 0;
	}
	return (result);
}

void				free_map(short unsigned **result, t_map map_info)
{
	int	it;

	it = -1;
	while ((++it) < map_info.size + 1)
		free(result[it]);
}

void				print_data(short unsigned **result,
					t_cell primary, t_map map_info)
{
	int		line;
	int		cell;

	line = 1;
	while (line < map_info.size + 1)
	{
		cell = 1;
		while (cell < map_info.l_width + 1)
		{
			if (result[line][cell] == 0)
				write(1, &map_info.obstacle, 1);
			else if (cell > primary.x - primary.max_square + 1
					&& cell <= primary.x + 1
					&& line > primary.y - primary.max_square + 1
					&& line <= primary.y + 1)
				write(1, &map_info.full, 1);
			else
				write(1, &map_info.free, 1);
			cell++;
		}
		write(1, "\n", 1);
		line++;
	}
}
