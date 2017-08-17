/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 10:20:55 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/09 10:20:56 by pgritsen         ###   ########.fr       */
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

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*tmp;
	int		it;

	tmp = 0;
	it = 1;
	while (it < ac)
		ft_list_push_front(&tmp, av[it++]);
	return (tmp);
}
