/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 20:45:01 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/10 20:45:02 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t.h"

void			print_addr(int num, int l_s)
{
	char	*tmp;
	int		empty_zeros;

	tmp = ft_putnbr_base(num);
	empty_zeros = 7 - ft_strlen(tmp);
	while (empty_zeros--)
		write(1, "0", 1);
	write(1, tmp, ft_strlen(tmp));
	if (g_symb_mode && l_s)
		write(1, " ", 1);
}

void			draw_symb(char symb, int l_s)
{
	if (symb > 31)
	{
		write(1, " ", 1);
		write(1, &symb, 1);
	}
	else
	{
		if (symb == '\010')
			write(1, "\\b", 2);
		else if (symb == '\014')
			write(1, "\\f", 2);
		else if (symb == '\012')
			write(1, "\\n", 2);
		else if (symb == '\015')
			write(1, "\\r", 2);
		else if (symb == '\011')
			write(1, "\\t", 2);
		else if (symb == '\040')
			write(1, "\\s", 2);
		else
			write(1, " ", 1);
	}
	if (l_s)
		write(1, " ", 1);
}

void			fill_with_spaces(int len)
{
	if (g_symb_mode)
		len = len * 4 - 1;
	else
		len = len * 3;
	while (len)
	{
		write(1, " ", 1);
		len--;
	}
}

void			draw_picture(int f_desc)
{
	char	buffer[STACK_LIMIT];
	char	*tmp;
	int		bytes_read;
	int		it;

	bytes_read = read(f_desc, buffer, STACK_LIMIT);
	it = -1;
	while (++it < bytes_read)
	{
		if (it % BASE_SIZE == 0)
			print_addr(it, 1);
		write(1, " ", 1);
		tmp = ft_putnbr_base(buffer[it]);
		if (g_symb_mode)
			draw_symb(buffer[it], (it + 1) % BASE_SIZE != 0);
		else
			write(1, tmp, ft_strlen(tmp));
		if ((it + 1) % BASE_SIZE == 0)
			write(1, "\n", 1);
	}
	fill_with_spaces((BASE_SIZE - (it % BASE_SIZE)));
	write(1, "\n", 1);
	print_addr(it, 0);
	write(1, "\n", 1);
}
