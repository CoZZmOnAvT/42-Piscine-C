/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 19:22:47 by modnosum          #+#    #+#             */
/*   Updated: 2017/08/13 19:22:48 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"
#include "ft.h"

void			skip_newlines(char **str)
{
	while (**str == '\n')
		(*str)++;
}

int				count_newlines(char *str)
{
	int		count;

	count = 0;
	while (*str != '\0')
	{
		if (*str == '\n')
			count++;
		str++;
	}
	return (count);
}

int				length_before_newline(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		++i;
	return (i);
}

char			*get_line(char **str)
{
	int		i;
	int		len;
	char	*temp;

	len = length_before_newline(*str);
	temp = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (**str != '\n' && **str != '\0')
	{
		temp[i] = **str;
		(*str)++;
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char			**split_newlines(char *str)
{
	int		splits;
	int		i;
	char	**tab;

	splits = count_newlines(str) + 1;
	tab = malloc(sizeof(char*) * splits);
	i = 0;
	while (i < splits)
	{
		if (i < (splits - 1))
		{
			skip_newlines(&str);
			tab[i] = get_line(&str);
		}
		else
			tab[i] = 0;
		++i;
	}
	return (tab);
}
