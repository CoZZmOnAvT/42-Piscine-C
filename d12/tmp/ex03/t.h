/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 10:34:59 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/10 10:35:00 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_H
# define T_H

# include <unistd.h>

# include <stdlib.h>

# include <fcntl.h>

# define STACK_LIMIT 65534

# define BASE "0123456789abcdef"

# define BASE_SIZE 16

int				g_symb_mode;

unsigned long	ft_strlen(char *str);

void			print_addr(int num, int l_s);

void			draw_symb(char symb, int l_s);

void			fill_with_spaces(int len);

void			draw_picture(int f_desc);

char			*ft_putnbr_base(int nbr);

void			print(char *title, char *message, char *additional);

#endif
