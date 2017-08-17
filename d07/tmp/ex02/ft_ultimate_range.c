/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 20:18:45 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/02 20:18:46 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		average;
	int		it;
	int		*tmp;

	average = max - min;
	if (average <= 0)
	{
		range = 0;
		return (0);
	}
	tmp = (int*)malloc(sizeof(int) * average);
	it = 0;
	while (it < average)
	{
		tmp[it] = min + it;
		it++;
	}
	*range = tmp;
	return (average);
}
