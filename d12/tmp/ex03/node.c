/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 16:51:54 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/10 16:51:54 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t.h"

void			hexadermical(char **files, int count)
{
	int		it;
	int		f_desc;

	it = 1;
	if (files[1][0] == '-' && files[1][1] == 'c' && files[1][2] == '\0')
	{
		g_symb_mode = 1;
		it++;
	}
	while (it < count)
	{
		f_desc = open(files[it], O_RDONLY);
		if (f_desc < 0)
		{
			print("ft_hexdump: ", ": No such file or directory", files[it]);
			if (count == 2)
				print("ft_hexdump: ", ": Bad file descriptor", files[it++]);
			continue ;
		}
		draw_picture(f_desc);
		close(f_desc);
		it++;
	}
}

int				main(int argc, char **argv)
{
	g_symb_mode = 0;
	hexadermical(argv, argc);
	return (0);
}
