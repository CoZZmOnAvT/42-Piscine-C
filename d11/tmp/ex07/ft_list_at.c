/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 17:07:54 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/09 17:07:56 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	it;
	t_list			*tmp;

	tmp = begin_list;
	it = 0;
	while (it < nbr && tmp)
	{
		it++;
		tmp = tmp->next;
	}
	return (tmp);
}
