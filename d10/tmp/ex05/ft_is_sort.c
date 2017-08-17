/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 16:51:54 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/07 16:51:56 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int			it;
	int			arr_sort;

	it = 0;
	if (f(tab[it], tab[it + 1]) == 0)
		while (f(tab[it], tab[it + 1]) == 0 && it < length)
			it++;
	if (it == length - 1)
		return (1);
	if (f(tab[it], tab[it + 1]) >= 0)
		arr_sort = 0;
	else
		arr_sort = 1;
	while (it < length - 1)
	{
		if (arr_sort == 0 && f(tab[it], tab[it + 1]) < 0)
			return (0);
		else if (arr_sort == 1 && f(tab[it], tab[it + 1]) > 0)
			return (0);
		it++;
	}
	return (1);
}
