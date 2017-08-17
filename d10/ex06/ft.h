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

# define OPERATORS "+-*/%"

typedef enum	e_bool
{
	false, true
}				t_bool;

typedef void	(*t_operation)(char*, char*);

t_bool			input_data_correct(char **av);

void			ft_putnbr(int nb);

int				ft_atoi(char *str);

void			calculate(char *num1, char operator, char *num2);

void			plus(char *num1, char *num2);

void			minus(char *num1, char *num2);

void			mult(char *num1, char *num2);

void			divide(char *num1, char *num2);

void			modulo(char *num1, char *num2);

t_bool			g_error_caght;

#endif
