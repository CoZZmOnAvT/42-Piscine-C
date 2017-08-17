/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 05:57:41 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/04 05:57:43 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOOR_H
# define FT_DOOR_H

typedef	enum
{
	FALSE, TRUE
}	t_ft_bool;

typedef struct
{
	int		state;
}			t_door;

void		ft_putstr(char *str);

t_ft_bool	close_door(t_door *door);

t_ft_bool	open_door(t_door *door);

t_ft_bool	is_door_open(t_door *door);

t_ft_bool	is_door_close(t_door *door);

#endif
