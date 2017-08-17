/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 11:58:08 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/12 11:58:08 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t.h"

unsigned long	ft_strlen(char *str)
{
	unsigned long	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int				found_action(char symb)
{
	int		it;

	if (!symb)
		return (-1);
	it = -1;
	while (ACTIONS[++it])
		if (ACTIONS[it] == symb)
			return (it);
	return (-1);
}

int				g_priority[] = {1, 1, 2, 2, 2};

int				get_priority(char symb)
{
	int	it;

	if (!symb)
		return (0);
	it = -1;
	while (ACTIONS[++it])
		if (ACTIONS[it] == symb)
			return (g_priority[it]);
	return (0);
}
