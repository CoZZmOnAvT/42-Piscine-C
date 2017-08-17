/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 11:44:06 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/12 11:44:07 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_H
# define T_H

# define ACTIONS "+-*/%"

typedef struct	s_opp
{
	char	opp;
	int		(*action)(int, int);
}				t_opp;

int				ft_atoi(char *str);

int				c_add(int a, int b);
int				c_sub(int a, int b);
int				c_mult(int a, int b);
int				c_div(int a, int b);
int				c_mod(int a, int b);

unsigned long	ft_strlen(char *str);
int				found_action(char symb);
int				get_priority(char	symb);

int				calculate(char *str, int from, int to);

void			ft_putnbr(int nb);
void			ft_putchar(char c);

#endif
