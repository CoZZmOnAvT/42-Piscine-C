/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 16:02:30 by pgritsen          #+#    #+#             */
/*   Updated: 2017/07/28 17:45:34 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int it;
	int temp;

	if (nb <= 2)
		return (nb == 2);
	if (nb % 2 == 0)
		return (0);
	temp = nb / 2;
	it = 3;
	while (it <= temp)
	{
		if (nb % it == 0)
			return (0);
		it += 2;
	}
	return (1);
}
