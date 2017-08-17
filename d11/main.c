/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 18:38:59 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/08 18:38:59 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include <stdio.h>

int		main(int argc, char **argv)
{
	t_list *t;

	t = 0;

	// printf("%d\n", (int)t->data);

	// t = ft_create_elem("START!");
	// t = malloc(sizeof(t_list));

	// t->data = "Hello";
	// t->next = 0;
	

	// printf("%s\n", t->data);

	// t = ft_create_elem("HELLO");

	// printf("%d\n", (int)t->data);

	ft_list_push_front(&t, "6");
	// ft_list_push_front(&t, "5");
	// ft_list_push_back(&t, "World!");

	// printf("%s\n", t->data);

	// ft_list_push_back(&t, "Come");
	//ft_list_push_back(&t, "ON");
	// ft_list_push_back(&t, "PEOPLE");


	ft_list_push_front(&t, "4");
	ft_list_push_front(&t, "3");
	ft_list_push_front(&t, "2");
	ft_list_push_front(&t, "1");
	// t_list *thnn;
	// while (thnn)
	// {
	// 	printf("%s\n", thnn->data);
	// }

	// int		elements;
	
	
	// tmp = t;
	// elements = 0;
	// while(*tmp)
	// {
	// 	elements++;
	// 	tmp = &(*tmp)->next;		
	// }
	// printf("%d\n", elements);

	// t = ft_list_push_params(argc, argv);

	// printf("%s\n", t->data);

	// ft_list_clear(&t);

	//printf("%s\n", t->data);

	ft_list_reverse(&t);

	while (t)
	{
		printf("%s\n", t->data);
		t = t->next;
	}

	//ft_list_push_front(&t, "Jopa");

	// printf("%s\n", t->data);
	// printf("%s\n", ft_list_last(t)->data);
	
	//printf("%d\n", ft_list_size(t));
}
