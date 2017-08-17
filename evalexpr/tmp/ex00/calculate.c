/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 11:46:58 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/12 11:46:58 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t.h"

int		c_add(int a, int b)
{
	return (b + a);
}

int		c_sub(int a, int b)
{
	return (b - a);
}

int		c_mult(int a, int b)
{
	return (b * a);
}

int		c_div(int a, int b)
{
	if (a == 0)
		return (0);
	return (b / a);
}

int		c_mod(int a, int b)
{
	if (a == 0)
		return (0);
	return (b % a);
}
