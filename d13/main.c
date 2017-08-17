/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 20:35:35 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/11 20:35:36 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdio.h>

void		btree_apply_suffix(t_btree *root, void (*applyf)(void *));

void	*btree_search_item(t_btree *root, void *data_ref,
							int (*cmpf)(void *, void *));

t_btree		*btree_create_node(void *item);

void		print(void *data)
{
	printf("%s\n", data);
}

int		ft_strcmp(char *s1, char *s2)
{
	int		it;

	it = 0;
	while (s1[it] > 0 || s2[it] > 0)
	{
		if (s1[it] != s2[it])
			return ((unsigned int)s1[it] - (unsigned int)s2[it]);
		it++;
	}
	return (0);
}

int			main()
{
	t_btree		*tree;

	tree = 0;
	tree = btree_create_node("A");
	tree->left = btree_create_node("B");
	tree->right = btree_create_node("C");
	tree->left->left = btree_create_node("D");
	tree->left->right = btree_create_node("E");
	tree->left->left->right = btree_create_node("H");
	tree->right->left = btree_create_node("F");
	tree->right->right = btree_create_node("G");
	tree->right->left->right = btree_create_node("J");
	tree->right->left->left = btree_create_node("I");

	printf("%s\n\n", btree_search_item(tree, "E", &ft_strcmp));

	btree_apply_suffix(tree, &print);
}
