/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 12:44:26 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/04 12:44:28 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_pair(int *tab, int length)
{
	int		found_pair;
	int		it;

	found_pair = -1;
	it = 0;
	while (it < length - 1)
	{
		if (tab[it] == tab[it + 1])
			found_pair *= -1;
		if (found_pair == -1)
			return (tab[it]);
		if (tab[it] != tab[it + 1])
			found_pair = -1;
		it++;
	}
	return (-1);
}

int		ft_unmatch(int *tab, int length)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < length - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	if (is_pair(tab, length) != -1)
		return (is_pair(tab, length));
	else
		return (0);
}
