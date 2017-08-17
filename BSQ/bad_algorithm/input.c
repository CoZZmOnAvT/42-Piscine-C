/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 14:32:57 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/14 14:32:59 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "stack.h"
#include "llist.h"
#include <stdio.h>
#include "header.h"

int string_to_int(char *string)
{
	int sign;
	int last;
	int i;
	int result;
	int mult;

	sign = 1;
	last = 0;
	while (string[last] != 0)
		last += 1;
	last -= 1;
	i = 0;
	if ((string[0] == '-') || (string[0] == '+'))
		i += 1;
	if (string[0] == '-')
		sign = -1;
	result = 0;
	mult = 1;
	while (last >= i)
	{
		result += mult * (string[last] - '0');
		mult *= 10;
		last -= 1;
	}
	return (result * sign);
}

int get_size_legend(int fd, char *map_legend)
{
	char	buffer;
	char	result[11];
	int		i;

	read(fd, &buffer, 1);
	if ((buffer >= '0' && buffer <= '9') || (buffer == '+' || buffer == '-'))
		result[0] = buffer;
	else
		return (-1);
	i = 1;
	while (read(fd, &buffer, 1) && buffer >= '0' && buffer <= '9')
	{
		result[i] = buffer;
		i += 1;
	}
	i = -1;
	while ((++i) < 3)
	{
		map_legend[i] = buffer;
		read(fd, &buffer, 1);
	}
	map_legend[i] = 0;
	result[i] = 0;
	if (((result[0] == '+') || (result[0] == '-')) && (i == 1))
		return (-1);
	return (string_to_int(result));
}

t_bool	is_in_map(char c, char *map_legend, int *line, int *edge)
{
	int i;

	i = -1;
	while ((++i) < 2)
		if (c == map_legend[i])
			return (true);
		else if (c == '\n')
		{
			*line = *line + 1;
			edge[0] = 0;
			edge[1] = -1;
			return (true);
		}
	return (false);
}

int min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

/*	____RESERVED__FOR__ANYA_____
t_list *find_square_start(t_list *start, int square_size, int map_size)
{
	int i = square_size;

	while ((start->start_l + square_size) <= map_size)
	{
		t_list *prev = start;
		t_list *next = start->next;
		while (next->start_l <= prev->start_l)
			next = next->next;
		if ((prev->left_p >= next->left_p) && (prev->right_p <= next->right_p) && i >= 0)
		{
			prev = next;
			next = next->next;
			i--;
		}
		if (i == 0)
			return (start);
	}
	return (0);
}

int square_size = map_size;
t_list *square_start = 0;
while (square_size > 0)
{
	t_list *start = limits;
	while (start)
	{			
		find_square_start(start, square_size, map_size);
		if (find_square_start(start, square_size, map_size) != 0)
		{				
			square_start = find_square_start(start, square_size, map_size);
			break ;
		}
		else
			start = start->next;
	}
	square_size--;
}*/

void	fill_tree(int fd, char *map_legend, int map_size, char *file_name)
{
	char	buffer;	
	int		edge[2];
	int		line;
	int		line_width[2];
	t_list	*limits;
	int		size[3];
	
	limits = 0;
	edge[0] = 0;
	edge[1] = 0;
	line = 0;
	line_width[1] = 0;
	while (line < map_size && read(fd, &buffer, 1))
	{
		if (buffer == map_legend[1] || buffer == '\n')
		{
			if (buffer == '\n')
			{
				if (line == 0)
					line_width[0] = line_width[1] + 1;
				else if (line > 0 && line_width[0] != line_width[1])
				{
					ft_list_clear(&limits);
					write(2, "map error\n\n", 11);
					return ;
				}
				line_width[1] = 0;
			}
			if (edge[1] - edge[0] > 0)
				insert_sorted(&limits, edge[0], edge[1], line);
			edge[0] = edge[1] + 1;
		}		
		if (!is_in_map(buffer, map_legend, &line, edge))
		{
			ft_list_clear(&limits);
			write(2, "map error\n\n", 11);
			return ;
		}
		line_width[1]++;
		edge[1]++;
	}

	int max_size = 0;
	size[0] = 0;
	size[1] = 0;
	size[2] = 0;
	while (limits)
	{		
		if (min(limits->right_p - limits->left_p, limits->end_l - limits->start_l) > max_size
			|| (min(limits->right_p - limits->left_p, limits->end_l - limits->start_l) == max_size
				&& limits->start_l < size[1]))
		{
			max_size = min(limits->right_p - limits->left_p, limits->end_l - limits->start_l);
			size[0] = limits->left_p;
			size[1] = limits->start_l;
			size[2] = max_size;		
		}
		limits = limits->next;
	}
	close(fd);
	print_result_of_the_most_beautiful_algorithm_in_the_world(file_name, size, map_legend[2]);
}

int		get_map_data(int fd, char *file_name)
{
	int		map_size;
	char	map_legend[3];

	if (fd == -1)
	{
		file_name = "tmp_input";
		fd = open(file_name, O_RDONLY);
	}
	map_size = get_size_legend(fd, map_legend);
	if (map_size == -1)
	{		
		write(2, "map error\n\n", 11);
		return (0);
	}
	fill_tree(fd, map_legend, map_size, file_name);
	return (fd);
}

void	create_file_from_stream_data()
{
	int fd;
	char buffer;

	fd = open("tmp_input", O_RDWR | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
	while(read(0, &buffer, 1))
		write(fd, &buffer, 1);
	close(fd);
}

void	ft_input(int argc, char **argv)
{
	int file_index;
	int fd;

	if (argc > 1)
	{
		file_index = 0;
		while (++file_index < argc)
		{
			fd = open(argv[file_index], O_RDONLY);
			if (fd == -1)
			{
				write(2, "map error\n\n", 11);
				continue ;
			}
			else
			{
				get_map_data(fd, argv[file_index]);
				if (file_index < (argc - 1))
					write(1, "\n", 1);
				close(fd);
			}
		}
	}
	else
	{
		create_file_from_stream_data();
		fd = get_map_data(-1, 0);
		close(fd);
	}
}
