/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modnosum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 11:52:14 by modnosum          #+#    #+#             */
/*   Updated: 2017/08/13 19:33:10 by modnosum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef enum	e_bool
{
	false,
	true
}				t_bool;

typedef struct	s_list
{
	struct s_list	*next;
	char			data;
}				t_list;

char			**get_input(void);
int				**decide(char **tab);
void			print_decisions(int **decisions);

t_bool			rush(char **input, char *symbols, int *size);
int				*size_of_rush(char **tab);
void			print_results(int rush, int l, int c);
char			**split_newlines(char *str);
void			list_to_str(t_list *list, char **str);
void			list_push(t_list **list, char data);
t_list			*list_elem(char data);
int				list_size(t_list *list);

#endif
