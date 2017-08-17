/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 23:28:25 by pgritsen          #+#    #+#             */
/*   Updated: 2017/07/27 23:28:28 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	print_num(char a, char b, char c)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(c);
}

void	ft_print_comb(void)
{
	char i;
	char x;
	char z;

	i = '0';
	while (i < '7')
	{
		x = i + 1;
		while (x <= '8')
		{
			z = x + 1;
			while (z <= '9')
			{
				print_num(i, x, z);
				ft_putchar(',');
				ft_putchar(' ');
				z++;
			}
			x++;
		}
		i++;
	}
	print_num('7', '8', '9');
	ft_putchar('\n');
}
