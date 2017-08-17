/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 00:57:41 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/04 00:57:42 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	g_flytime = 0;

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	if (base == 1)
		return (++g_flytime);
	if (base % 2 == 0)
	{
		g_flytime++;
		return (ft_collatz_conjecture(base / 2));
	}
	g_flytime++;
	return (ft_collatz_conjecture(base * 3 + 1));
}
