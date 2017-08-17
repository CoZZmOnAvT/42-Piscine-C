/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_llist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 10:00:17 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/15 10:00:18 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "llist.h"
#include <stdlib.h>
#include <stdio.h>

int		g_line_end = -1;

t_list	*create_node(int left, int right, int line_start)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->left_p = left;
		tmp->right_p = right;
		tmp->start_l = line_start;
		if (g_line_end == -1)
			tmp->end_l = line_start + 1;
		else
		{
			tmp->end_l = g_line_end;
			g_line_end = -1;
		}
		tmp->next = NULL;
	}
	return (tmp);
}

void	push_front(t_list **node, int left, int right, int line_start)
{
	t_list	*tmp;

	tmp = create_node(left, right, line_start);
	tmp->next = *node;
	*node = tmp;
}

void	push_back(t_list **node, int left, int right, int line_start)
{
	while(*node)
		node = &(*node)->next;
	*node = create_node(left, right, line_start);
}

void	insert_sorted(t_list **node, int left, int right, int line_start)
{
	t_list	*tmp;

	tmp = create_node(left, right, line_start);
	if (*node == NULL)
	{
		*node = create_node(left, right, line_start);
		return ;
	}
	while(*node)
	{		
		if (line_start - (*node)->end_l == 0)
		{
			if (left == (*node)->left_p && right == (*node)->right_p)
			{
				(*node)->end_l = (*node)->end_l + 1;
			}
			else if (left >= (*node)->left_p && right <= (*node)->right_p)
			{
				g_line_end = line_start + 1;
				push_back(node, left, right, (*node)->start_l);
			}
			else if (left < (*node)->left_p && right > (*node)->right_p)
			{
				(*node)->end_l = (*node)->end_l + 1;
				if (!find_in_list(*node, tmp))
					push_back(node, left, right, line_start);
			}
			else if (left <= (*node)->left_p && right <= (*node)->right_p && right > (*node)->left_p)
			{
				g_line_end = line_start + 1;
				push_back(node, (*node)->left_p, right, (*node)->start_l);
				if (!find_in_list(*node, tmp))
					push_back(node, left, right, line_start);
			}
			else if (left >= (*node)->left_p && right >= (*node)->right_p && left < (*node)->right_p)
			{
				g_line_end = line_start + 1;
				push_back(node, left, (*node)->right_p, (*node)->start_l);
				if (!find_in_list(*node, tmp))
					push_back(node, left, right, line_start);
			}
			else
				if (!find_in_list(*node, tmp))
					push_back(node, left, right, line_start);
		}
		node = &(*node)->next;
	}
}

t_list	*get_index(t_list *node, int index)
{
	int		it;

	it = -1;
	while (node && (++it) < index)
		node = node->next;
	return (node);
}

t_bool	find_in_list(t_list *haystack, t_list *needle)
{
	while (haystack)
	{
		if (haystack->left_p == needle->left_p && haystack->right_p == needle->right_p)
			return (true);
		haystack = haystack->next;
	}
	return (false);
}

void	ft_list_clear(t_list **begin_list)
{
	if (!(*begin_list))
		return ;
	ft_list_clear(&(*begin_list)->next);
	free(*begin_list);
	*begin_list = 0;
}
