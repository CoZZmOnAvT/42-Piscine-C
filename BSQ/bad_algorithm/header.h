/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 11:01:09 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/13 11:01:09 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef enum	e_bool
{
	false, true
}				t_bool;

void	ft_input(int argc, char **argv);

void	print_result_of_the_most_beautiful_algorithm_in_the_world(char *file_name, int *size, char full_s);

#endif
