/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 18:13:33 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/08 18:13:34 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*tmp;

	if (*begin_list == 0)
	{
		*begin_list = ft_create_elem(data);
	}
	else
	{
		tmp = *begin_list;
		*begin_list = ft_create_elem(data);
		(*begin_list)->next = tmp;
	}
}
