/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 21:28:27 by pgritsen          #+#    #+#             */
/*   Updated: 2017/07/28 21:28:37 by pgritsen         ###   ########.fr       */
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

int		ft_find_next_prime(int nb)
{
	int temp;

	temp = ft_is_prime(nb);
	if (temp == 1)
		return (nb);
	while (1)
	{
		nb++;
		temp = ft_is_prime(nb);
		if (temp == 1)
			return (nb);
	}
}
