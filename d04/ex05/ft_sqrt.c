/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 12:04:56 by pgritsen          #+#    #+#             */
/*   Updated: 2017/07/28 17:07:06 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	double it;
	double nb_t;

	nb_t = nb;
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (0);
	else if (nb == 1)
		return (1);
	it = 2;
	while (it <= nb_t / 2)
	{
		if (it * it == nb_t)
		{
			if (it != (int)it)
				return (0);
			return ((int)it);
		}
		it = (it + (nb_t / it)) / 2;
	}
	return (0);
}
