/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 12:12:19 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/08 12:12:19 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t.h"

int			ft_atoi(char *str)
{
	int			num_start;
	int			mult_it;
	long int	mult;
	int			resault;

	num_start = 0;
	if (str[num_start] == 0)
		return (0);
	while ((str[num_start] > '\10' && str[num_start] <= '\16')
		|| str[num_start] == '\40' || str[num_start] == '-'
		|| str[num_start] == '+')
		num_start++;
	mult = 1;
	mult_it = num_start;
	while (str[++mult_it] >= '0' && str[mult_it] <= '9')
		mult *= 10;
	resault = 0;
	while (str[num_start] >= '0' && str[num_start] <= '9')
	{
		resault += (str[num_start++] - 48) * mult;
		mult /= 10;
	}
	return (resault);
}
