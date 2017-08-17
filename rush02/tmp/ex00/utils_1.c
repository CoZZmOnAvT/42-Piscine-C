/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 19:20:51 by modnosum          #+#    #+#             */
/*   Updated: 2017/08/13 19:31:48 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"
#include "ft.h"

char		*g_symbols[6] = {
	"oooo|- ",
	"/\\\\/** ",
	"AACCBB ",
	"ACACBB ",
	"ACCABB ",
	0
};

char			**get_input(void)
{
	char	c;
	t_list	*list;
	char	*str;

	list = NULL;
	while (ft_readchar(&c))
		list_push(&list, c);
	if (list_size(list) == 0)
		return (NULL);
	str = malloc(sizeof(char) * (list_size(list) + 1));
	list_to_str(list, &str);
	return (split_newlines(str));
}

void			print_results(int rush, int l, int c)
{
	ft_putstr("[rush-0");
	ft_putnbr(rush);
	ft_putstr("] [");
	ft_putnbr(l);
	ft_putstr("] [");
	ft_putnbr(c);
	ft_putstr("]");
}

void			print_bonus(char *message, int l, int c)
{
	ft_putstr(" || [");
	ft_putstr(message);
	ft_putstr("] [");
	ft_putnbr(l);
	ft_putstr("] [");
	ft_putnbr(c);
	ft_putstr("]");
}

void			print_decisions(int **decisions)
{
	int i;

	if (decisions == NULL)
		ft_putstr("aucune");
	else
	{
		i = 0;
		while (decisions[0][i] != -1)
		{
			if (i != 0)
				ft_putstr(" || ");
			print_results(decisions[0][i], decisions[1][1], decisions[1][0]);
			++i;
		}
		if (decisions[1][0] == decisions[1][1])
			print_bonus("square", decisions[1][1], decisions[1][0]);
		print_bonus("rectangle", decisions[1][1], decisions[1][0]);
	}
	ft_putstr("\n");
}

int				**decide(char **tab)
{
	int		**result;
	int		template;
	int		it;

	if (tab == NULL)
		return (NULL);
	result = (int **)malloc(sizeof(int *) * 2);
	result[0] = (int *)malloc(sizeof(int) * 6);
	result[1] = (int *)malloc(sizeof(int) * 2);
	result[1] = size_of_rush(tab);
	it = 0;
	template = -1;
	while (g_symbols[++template])
		if (rush(tab, g_symbols[template], result[1]))
			result[0][it++] = template;
	result[0][it] = -1;
	if (!it)
	{
		free(result);
		return (NULL);
	}
	return (result);
}
