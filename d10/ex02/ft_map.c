/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 11:45:17 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/07 11:45:18 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int		it;
	int		*result;

	result = (int*)malloc(sizeof(int) * length);
	it = 0;
	while (it < length)
	{
		result[it] = f(tab[it]);
		it++;
	}
	return (result);
}
