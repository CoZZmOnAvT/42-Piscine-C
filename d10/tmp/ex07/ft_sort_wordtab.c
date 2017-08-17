/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 21:03:40 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/07 21:03:41 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_wordtab(char **tab)
{
	int		it_o;
	int		it_i;
	int		it_s;
	char	*tmp;

	it_o = -1;
	while (tab[++it_o])
	{
		it_i = -1;
		while (tab[++it_i + 1])
		{
			it_s = 0;
			while (tab[it_i][it_s] >= tab[it_i + 1][it_s])
			{
				if (tab[it_i][it_s] > tab[it_i + 1][it_s])
				{
					tmp = tab[it_i + 1];
					tab[it_i + 1] = tab[it_i];
					tab[it_i] = tmp;
					break ;
				}
				it_s++;
			}
		}
	}
}
