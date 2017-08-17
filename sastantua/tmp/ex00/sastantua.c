/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 16:46:48 by pgritsen          #+#    #+#             */
/*   Updated: 2017/07/31 09:26:18 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		g_size;
int		g_ttpd;
int		g_dw;
int		g_raws_it;

int		find_start_block_wide(int step)
{
	int basic_root;
	int it;

	if (step == 0)
		return (0);
	if (step == 1)
		return (10);
	if (step == 2)
		return (22);
	if (step == 3)
		return (38);
	basic_root = 10 + step * 2;
	it = 4;
	while (it < step)
	{
		it += 2;
		basic_root += 2;
	}
	return (find_start_block_wide(step - 1) + basic_root);
}

void	print_sastantua_part(int q, int w, int e, int u)
{
	g_ttpd = 2;
	if (g_size % 2 == 0)
		g_ttpd = 3;
	g_dw = g_size;
	if (g_size % 2 == 0)
		g_dw--;
	if (u < (q - w) / 2)
		ft_putchar(' ');
	else if (u == (q - w) / 2)
		ft_putchar('/');
	else if (u == (q - w) / 2 + w - 1)
		ft_putchar('\\');
	else if (e > 3 && e == g_size - 1 && g_raws_it >= g_ttpd + g_dw /
		2 && g_raws_it < g_ttpd + g_dw / 2 + 1
		&& u > q / 2 - g_dw / 2 + g_dw - 3 && u <= q / 2 - g_dw / 2 + g_dw - 2)
		ft_putchar('$');
	else if (e == g_size - 1 && g_raws_it > g_ttpd - 1 &&
	u > q / 2 - g_dw / 2 - 1 && u < q / 2 + g_dw / 2 + 1)
		ft_putchar('|');
	else
		ft_putchar('*');
}

void	print_sastantua_full(int q, int w, int e)
{
	int i;
	int u;

	i = 0;
	while (i < (find_start_block_wide(g_size - 1) + 4
		+ (g_size - 1) * 2 + 2) / 2 - q / 2)
	{
		ft_putchar(' ');
		i++;
	}
	u = 0;
	while (u < (q - w) / 2 + w)
	{
		print_sastantua_part(q, w, e, u);
		u++;
	}
	ft_putchar('\n');

}

void	sastantua(int size)
{
	int q;

	g_size = size;
	q = 0;
	while (q < size)
	{
		g_raws_it = 0;
		while (g_raws_it < 3 + q)
		{
			print_sastantua_full(find_start_block_wide(q) + q * 2 + 7,
				find_start_block_wide(q) + g_raws_it * 2 + 3, q);
			g_raws_it++;
		}
		q++;
	}
}
