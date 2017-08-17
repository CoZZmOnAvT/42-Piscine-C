/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 05:57:27 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/04 05:57:29 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_door.h"
#include <unistd.h>

void		ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

t_ft_bool		close_door(t_door *door)
{
	ft_putstr("Door closing...\n");
	door->state = 0;
	return (TRUE);
}

t_ft_bool		open_door(t_door *door)
{
	ft_putstr("Door opening...\n");
	door->state = 1;
	return (TRUE);
}

t_ft_bool		is_door_open(t_door *door)
{
	ft_putstr("Door is open ?\n");
	if (door->state == 1)
		return (TRUE);
	else
		return (FALSE);
}

t_ft_bool		is_door_close(t_door *door)
{
	ft_putstr("Door is close ?\n");
	if (door->state == 0)
		return (TRUE);
	else
		return (FALSE);
}
