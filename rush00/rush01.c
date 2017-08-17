/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 08:59:36 by pgritsen          #+#    #+#             */
/*   Updated: 2017/07/29 17:52:47 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	rush(int x, int y)
{
	int it_x;
	int it_y;

	it_y = 0;
	while (it_y < y && x > 0)
	{
		it_x = 0;
		while (it_x < x)
		{
			if ((it_y == y - 1 && it_x == x - 1 && it_x > 0 && it_y > 0)
				|| (it_y == 0 && it_x == 0))
				ft_putchar('/');
			else if ((it_y == y - 1 && it_x == 0)
				|| (it_y == 0 && it_x == x - 1))
				ft_putchar('\\');
			else if (it_y == 0 || it_y == y - 1
				|| it_x == 0 || it_x == x - 1)
				ft_putchar('*');
			else
				ft_putchar(' ');
			it_x++;
		}
		ft_putchar('\n');
		it_y++;
	}
}
