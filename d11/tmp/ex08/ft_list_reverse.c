/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 17:21:46 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/09 17:21:46 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*g_prev = 0;

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*next;

	if (*begin_list)
	{
		next = (*begin_list)->next;
		(*begin_list)->next = g_prev;
		g_prev = (*begin_list);
		(*begin_list) = next;
		ft_list_reverse(&next);
	}
	*begin_list = g_prev;
}
