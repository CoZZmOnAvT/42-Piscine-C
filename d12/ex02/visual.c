/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 14:44:41 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/10 14:44:42 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t.h"

void	print(char *title, char *message, char *additional)
{
	write(1, title, ft_strlen(title));
	if (additional)
		write(1, additional, ft_strlen(additional));
	write(1, message, ft_strlen(message));
	write(1, "\n", 1);
}

void	display_content(char *buffer, int bytes, int bytes_read, int reverse)
{
	int		it;

	if (bytes != -1)
	{
		it = bytes_read - bytes;
		if (reverse)
			it = bytes - 1;
		if (it < 0)
			it = 0;
		while (buffer[it])
			write(1, &buffer[it++], 1);
	}
	else
	{
		while (buffer[bytes_read - 1] == '\n')
			bytes_read--;
		it = 0;
		while (it < 10 && bytes_read)
			if (buffer[--bytes_read] == '\n')
				it++;
		bytes_read++;
		while (buffer[bytes_read])
			write(1, &buffer[bytes_read++], 1);
	}
}

void	display_tail(char *file_name, int bytes, int reverse)
{
	char	buffer[STACK_LIMIT];
	int		f_desc;
	int		bytes_read;

	f_desc = open(file_name, O_RDONLY);
	if (f_desc < 0)
		return (print("ft_tail: ", ": No such file or directory", file_name));
	bytes_read = read(f_desc, buffer, STACK_LIMIT);
	if (bytes_read < 1)
		return ;
	display_content(buffer, bytes, bytes_read, reverse);
	close(f_desc);
}
