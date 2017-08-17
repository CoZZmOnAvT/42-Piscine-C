/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 23:10:36 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/02 23:10:38 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy_m(char *dest, char *src, int to)
{
	int	symb_it;

	symb_it = 0;
	if (to == -1)
		to = 2147483647;
	while (src[symb_it] != '\n' && src[symb_it] != '\t' && src[symb_it] != ' '
			&& src[symb_it] && symb_it < to)
	{
		dest[symb_it] = src[symb_it];
		symb_it++;
	}
	dest[symb_it] = 0;
	return (dest);
}

void	add_value(char **arr, char *src, int memory, int no_limit)
{
	char *tmp;

	tmp = (char *)malloc(sizeof(char) * memory);
	if (no_limit == -1)
		ft_strncpy_m(tmp, src, -1);
	else
		ft_strncpy_m(tmp, src, memory);
	*arr = tmp;
}

int		check_for_useless_symblos(int *it, char *str)
{
	if (str[*it + 1] == ' ' || str[*it + 1] == '\t'
		|| str[*it + 1] == '\n' || !str[*it + 1])
	{
		*it = *it + 1;
		return (1);
	}
	return (0);
}

char	**ft_explode(char *str, int num_of_elemets)
{
	char	**result;
	char	*tmp;
	int		it[3];

	it[0] = 0;
	it[1] = 0;
	it[2] = 0;
	result = (char **)malloc(sizeof(char *) * (num_of_elemets + 1));
	while (str[it[0]])
	{
		if (str[it[0]] == ' ' || str[it[0]] == '\t' || str[it[0]] == '\n')
		{
			if (check_for_useless_symblos(&it[0], str))
				continue ;
			tmp = str + it[1];
			add_value(&result[it[2]], tmp, it[0] - it[1], 0);
			it[1] = it[0] + 1;
			it[2]++;
		}
		it[0]++;
	}
	tmp = (str + it[1]);
	add_value(&result[it[2]], tmp, it[0] - it[1], -1);
	result[++it[2]] = 0;
	return (result);
}

char	**ft_split_whitespaces(char *str)
{
	int		num_of_elemets;
	int		it[2];
	char	**result;

	it[0] = -1;
	num_of_elemets = 1;
	while (str[++it[0]])
		if (str[it[0]] == ' ' || str[it[0]] == '\t' || str[it[0]] == '\n')
			num_of_elemets++;
	result = ft_explode(str, num_of_elemets);
	return (result);
}
