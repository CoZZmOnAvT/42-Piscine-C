/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 10:00:46 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/15 10:00:47 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

#include "header.h"

typedef struct	s_list
{
	int				left_p;
	int				right_p;
	int				start_l;
	int				end_l;
	struct s_list	*next;
}				t_list;

t_list			*create_node(int left, int right, int line_start);

void			push_front(t_list **node, int left, int right, int line_start);

void			push_back(t_list **node, int left, int right, int line_start);

void			insert_sorted(t_list **node, int left, int right, int line_start);

t_list			*get_index(t_list *node, int index);

void			ft_list_clear(t_list **begin_list);

t_bool			find_in_list(t_list *haystack, t_list *needle);

#endif
