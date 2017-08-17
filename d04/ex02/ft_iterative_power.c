/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 11:45:51 by pgritsen          #+#    #+#             */
/*   Updated: 2017/07/29 21:55:02 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int temp;
	if (nb == 0 && power == 0)
		return (1);
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	temp = 1;
	while (power > 0)
	{
		temp *= nb;
		power--;
	}
	return (temp);
}
