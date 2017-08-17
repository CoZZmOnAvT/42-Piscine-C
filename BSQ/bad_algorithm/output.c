/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 16:38:49 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/15 16:38:50 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	print_result_of_the_most_beautiful_algorithm_in_the_world(char *file_name, int *size, char full_s)
{
	char buffer;
	int line;
	int symbol;
	int	fd;

	line = 0;
	symbol = 0;
	fd = open(file_name, O_RDONLY);
	while (read(fd, &buffer, 1))
		if (buffer == '\n')
			break ;
	while (read(fd, &buffer, 1))
	{
		if (symbol >= size[0] && symbol < size[2] + size[0]
			&& line >= size[1] && line < size[1] + size[2] && buffer != '\n')
			write(1, &full_s, 1);
		else
			write(1, &buffer, 1);
		symbol += 1;
		if (buffer == '\n')
		{
			symbol = 0;
			line += 1;
		}
	}
	close(fd);
}
