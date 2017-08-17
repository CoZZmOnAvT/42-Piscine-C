/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_wordtab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 22:14:07 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/07 22:14:09 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char *))
{
	int		it_o;
	int		it_i;
	char	*tmp;

	it_o = -1;
	while (tab[++it_o])
	{
		it_i = -1;
		while (tab[++it_i + 1])
		{
			if (cmp(tab[it_i], tab[it_i + 1]) > 0)
			{
				tmp = tab[it_i + 1];
				tab[it_i + 1] = tab[it_i];
				tab[it_i] = tmp;
			}
		}
	}
}
