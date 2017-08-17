/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 11:28:15 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/07 11:28:17 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	if (length == 0)
		return ;
	f(tab[0]);
	ft_foreach(tab + 1, length - 1, f);
}
