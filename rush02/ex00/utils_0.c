/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils-0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 19:17:57 by modnosum          #+#    #+#             */
/*   Updated: 2017/08/13 19:31:38 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"
#include "ft.h"

t_bool			corner(int *it, int size[], char *symbols, char **res)
{
	if ((it[0] == 0 && it[1] == 0
			&& res[it[0]][it[1]] != symbols[0])
		|| (it[0] == 0 && it[1] == size[1] - 1
			&& res[it[0]][it[1]] != symbols[1] && size[1] > 1)
		|| (it[0] == size[0] - 1 && it[1] == 0 && size[0] > 1
			&& res[it[0]][it[1]] != symbols[2])
		|| (it[0] == size[0] - 1 && it[1] == size[1] - 1
			&& res[it[0]][it[1]] != symbols[3] && size[0] > 1 && size[1] > 1))
		return (false);
	return (true);
}

t_bool			border(int *it, int size[], char *symbols, char **res)
{
	if ((it[0] >= 1 && it[0] <= size[0] - 2
			&& (it[1] == 0 || it[1] == size[1] - 1)
			&& res[it[0]][it[1]] != symbols[4])
		|| ((it[0] == 0 || it[0] == size[0] - 1)
			&& it[1] >= 1 && it[1] <= size[1] - 2
			&& res[it[0]][it[1]] != symbols[5]))
		return (false);
	return (true);
}

t_bool			spaces(int *it, int size[], char *symbols, char **res)
{
	if ((it[0] >= 1 && it[0] <= size[0] - 2)
		&& (it[1] >= 1 && it[1] <= size[1] - 2)
		&& res[it[0]][it[1]] != symbols[6])
		return (false);
	return (true);
}

t_bool			rush(char **input, char *symbols, int size[])
{
	int		it[2];

	it[0] = 0;
	while (input[it[0]])
	{
		it[1] = 0;
		if (ft_strlen(input[it[0]]) != size[1])
			return (false);
		while (input[it[0]][it[1]])
		{
			if (!corner(it, size, symbols, input))
				return (false);
			if (!border(it, size, symbols, input))
				return (false);
			if (!spaces(it, size, symbols, input))
				return (false);
			it[1]++;
		}
		it[0]++;
	}
	return (true);
}

int				*size_of_rush(char **tab)
{
	int		*size;

	size = (int *)malloc(sizeof(int) * 2);
	size[0] = 0;
	while (tab[size[0]])
	{
		size[1] = 0;
		while (tab[size[0]][size[1]])
			size[1]++;
		size[0]++;
	}
	return (size);
}
