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

int				ft_atoi(char *str);

void			display_tail(char *file_name, int bytes, int reverse);

void			print(char *title, char *message, char *additional);

unsigned long	ft_strlen(char *str);

#endif
