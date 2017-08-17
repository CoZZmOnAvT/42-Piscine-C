/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 21:20:38 by pgritsen          #+#    #+#             */
/*   Updated: 2017/07/30 21:20:43 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		g_board[8][8];
int		g_results_count;

int		is_free(int a, int b)
{
	int i;

	i = 0;
	while (++i < a)
	{
		if (g_board[i][b])
			return (0);
	}
	i = 1;
	while (++i <= a && b - i >= 0)
	{
		if (g_board[a - i][b - i])
			return (0);
	}
	i = 1;
	while (i++ <= a && b + i < 8)
	{
		if (g_board[a - i][b + i])
			return (0);
	}
	return (1);
}

void	add_queen(int a)
{
	int i;

	if (a == 8)
	{
		g_results_count++;
		return ;
	}
	i = 0;
	while (i < 8)
	{
		if (is_free(a, i))
		{
			g_board[a][i] = 1;
			add_queen(a + 1);
			g_board[a][i] = 0;
		}
		i++;
	}
	return ;
}

int		ft_eight_queens_puzzle(void)
{
	g_results_count = 0;
	add_queen(0);
	return (g_results_count);
}
