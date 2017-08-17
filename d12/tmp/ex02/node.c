/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 10:34:52 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/10 10:34:54 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t.h"

int				g_reverse;

unsigned long	ft_strlen(char *str)
{
	unsigned long	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void			await(void)
{
	char	buffer[STACK_LIMIT];

	while (1)
		read(1, buffer, STACK_LIMIT);
}

int				validate_param(char *param)
{
	int		it;

	it = -1;
	while (param[++it])
	{
		if ((param[it] < '0' || param[it] > '9')
			&& param[it] != ' '
			&& param[it] != '-'
			&& param[it] != '+')
			return (0);
		if (param[it] == '+')
			g_reverse = 1;
	}
	return (1);
}

int				main(int argc, char **argv)
{
	g_reverse = 0;
	if (argc < 2)
		await();
	else if (argc == 2)
		display_tail(argv[1], -1, g_reverse);
	else if (argc < 4)
		print("ft_tail: illegal offset -- ", argv[2], 0);
	else if (argc == 4)
	{
		if (validate_param(argv[2]))
		{
			if (argv[1][0] == '-' && argv[1][1] == 'c' && argv[1][2] == '\0')
				display_tail(argv[3], ft_atoi(argv[2]), g_reverse);
			else
				return (0);
		}
		else
			print("ft_tail: illegal offset -- ", argv[2], 0);
	}
	return (0);
}
