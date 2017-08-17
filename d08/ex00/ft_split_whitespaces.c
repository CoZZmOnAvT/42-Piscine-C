/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 19:57:04 by exam              #+#    #+#             */
/*   Updated: 2017/08/04 21:01:43 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	strncpy_m(char *dest, char *src, int from, int to)
{
	int		it_src;
	int		it_dest;

	if (to == -1)
		to = 2147483647;
	it_src = from;
	it_dest = 0;
	while (src[it_src] && it_src <= to)
	{
		dest[it_dest] = src[it_src];
		it_dest++;
		it_src++;
	}
	dest[it_dest] = 0;
}

int		memmory_to_alloc(char *str)
{
	int		it;

	it = 0;
	if (!str[it])
		return (0);
	while (*str)
	{
		if (*str == ' ' || *str == '\t' || *str == '\n')
			it++;
		str++;
	}
	return (it + 2);
}

char	**write_in_memory(char *str, int to, int from)
{
	int		word_it;
	char	**result;

	word_it = 0;
	result = (char**)malloc(sizeof(char*) * memmory_to_alloc(str));
	while (str[from])
	{
		if ((str[from] == ' ' || str[from] == '\t' || str[from] == '\n')
			&& (str[from + 1] != ' ' || str[from + 1] != '\t'
				|| str[from + 1] != '\n'))
		{
			from++;
			continue ;
		}
		to = from + 1;
		while (str[to] != ' ' && str[to] != '\t' && str[to] != '\n' && str[to])
			to++;
		result[word_it] = (char *)malloc(sizeof(char) * (to - from + 1));
		strncpy_m(result[word_it], str, from, to - 1);
		from = to;
		word_it++;
	}
	result[word_it] = 0;
	return (result);
}

char	**ft_split_whitespaces(char *str)
{
	char	**result;
	int		from;
	int		to;

	from = 0;
	to = 0;
	result = write_in_memory(str, to, from);
	return (result);
}
