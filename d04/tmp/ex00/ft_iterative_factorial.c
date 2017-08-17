/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 09:12:56 by pgritsen          #+#    #+#             */
/*   Updated: 2017/07/29 21:52:45 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int factorial;

	if (nb < 0)
		return (0);
	if (nb > 12)
		return (0);
	else if (nb == 0)
		return (1);
	factorial = 1;
	while (nb > 0)
	{
		factorial *= nb;
		nb--;
	}
	return (factorial);
}
