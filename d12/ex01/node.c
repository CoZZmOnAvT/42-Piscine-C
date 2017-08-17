/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 09:43:46 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/10 09:43:47 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t.h"

#include <stdio.h>

unsigned long	ft_strlen(char *str)
{
	unsigned long	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void			print_error(char *propose, char *message)
{
	write(2, "ft_cat: ", 8);
	write(2, propose, ft_strlen(propose));
	write(2, message, ft_strlen(message));
}

void			duplicate_input(void)
{
	char	buff[STACK_LIMIT];
	int		bytes_read;

	while (1)
	{
		bytes_read = read(0, buff, STACK_LIMIT);
		write(1, buff, bytes_read);
		if (buff[bytes_read - 1] == 0)
			break ;
		buff[0] = 0;
	}
}

void			read_file(int ac, char **av)
{
	int		it;
	int		f_desc;
	char	buff[STACK_LIMIT];
	int		bytes_read;

	it = 0;
	while (++it < ac)
	{
		if (av[it][0] == '-' && av[it][1] == '\0')
		{
			duplicate_input();
			continue ;
		}
		f_desc = open(av[it], O_RDONLY);
		if (f_desc < 0)
		{
			print_error(av[it], ": No such file or directory\n");
			return ;
		}
		bytes_read = read(f_desc, buff, STACK_LIMIT);
		write(1, buff, bytes_read);
		close(f_desc);
	}
}

int				main(int argc, char **argv)
{
	if (argc < 2)
		duplicate_input();
	else
		read_file(argc, argv);
}
