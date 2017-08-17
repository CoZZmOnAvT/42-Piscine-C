/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 19:31:38 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/02 19:31:40 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		range;
	int		it;
	int		*arr;

	range = max - min;
	if (range <= 0)
		return (0);
	arr = (int *)malloc(sizeof(int) * range);
	it = 0;
	while (it < range)
	{
		arr[it] = min + it;
		it++;
	}
	return (arr);
}
