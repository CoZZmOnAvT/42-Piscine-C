/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 21:19:46 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/15 21:19:47 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		main(int ac, char **av)
{
	int		f_it;

	f_it = 0;
	while ((++f_it) < ac)
	{
		if (!read_minds(av[f_it]))
			write(2, "map error\n", 10);
		if (f_it < ac - 1)
			write(1, "\n", 1);
	}
	if (ac == 1)
		if (!read_minds(0))
			write(2, "map error\n", 10);
	return (0);
}
