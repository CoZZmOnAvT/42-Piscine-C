/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:20:38 by pgritsen          #+#    #+#             */
/*   Updated: 2017/07/27 23:30:40 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	print_num_b(char a, char b, char c, char d)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(' ');
	ft_putchar(c);
	ft_putchar(d);
	ft_putchar(',');
	ft_putchar(' ');
}

void	print_num_e(char a, char b, char c, char d)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(' ');
	ft_putchar(c);
	ft_putchar(d);
	ft_putchar('\n');
}

void	main_work(char a, char i, char b, char c)
{
	i = '0';
	while (i <= '9')
	{
		a = '0';
		while (a < '8')
		{
			b = i;
			while (b <= '9')
			{
				c = a + 1;
				while (c <= '9')
				{
					print_num_b(i, a, b, c);
					c++;
				}
				b++;
			}
			a++;
		}
		i++;
	}
}

void	ft_print_comb2(void)
{
	char a;
	char i;
	char b;
	char c;

	a = '0';
	i = '0';
	b = '0';
	c = '0';
	main_work(a, i, b, c);
	print_num_e('9', '8', '9', '9');
}
