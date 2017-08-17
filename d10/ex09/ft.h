/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 19:03:21 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/07 19:03:22 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

typedef enum	e_bool
{
	false, true
}				t_bool;

typedef	struct	s_opp
{
	char	*opp;
	void	(*t_act)(char*, char*);
}				t_opp;

t_bool			input_data_correct(char **av);

void			ft_putchar(char c);

void			ft_putnbr(int nb);

void			ft_putstr(char *str);

int				ft_atoi(char *str);

void			calculate(char *num1, char *operator, char *num2);

void			ft_add(char *num1, char *num2);

void			ft_sub(char *num1, char *num2);

void			ft_mul(char *num1, char *num2);

void			ft_div(char *num1, char *num2);

void			ft_mod(char *num1, char *num2);

void			ft_usage();

t_bool			g_error_caght;

#endif
