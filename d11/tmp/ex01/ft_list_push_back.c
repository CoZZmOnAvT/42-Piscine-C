/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 17:35:02 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/08 17:35:03 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	if (*begin_list == 0)
	{
		*begin_list = ft_create_elem(data);
	}
	else
	{
		while (*begin_list)
			begin_list = &(*begin_list)->next;
		*begin_list = ft_create_elem(data);
	}
}
