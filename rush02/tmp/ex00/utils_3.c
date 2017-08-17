/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 19:23:28 by modnosum          #+#    #+#             */
/*   Updated: 2017/08/13 19:26:02 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

t_list			*list_elem(char data)
{
	t_list	*temp;

	temp = malloc(sizeof(t_list));
	if (temp == NULL)
		return (NULL);
	temp->next = NULL;
	temp->data = data;
	return (temp);
}

void			list_push(t_list **list, char data)
{
	if (*list == NULL)
		*list = list_elem(data);
	else
	{
		while ((*list)->next)
			list = &(*list)->next;
		(*list)->next = list_elem(data);
	}
}

int				list_size(t_list *list)
{
	int i;

	i = 0;
	if (list != NULL)
		while (list->next)
		{
			++i;
			list = list->next;
		}
	return (i);
}

void			list_to_str(t_list *list, char **str)
{
	int i;

	i = 0;
	while (list->next)
	{
		str[0][i] = list->data;
		++i;
		list = list->next;
	}
	str[0][i] = list->data;
}
