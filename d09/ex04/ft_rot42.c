/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 21:28:30 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/03 21:28:31 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_rot42(char *str)
{
	int		tmp;
	char	del_symb;

	tmp = 0;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			del_symb = 'Z';
		else if (*str >= 'a' && *str <= 'z')
			del_symb = 'z';
		if (del_symb)
		{
			tmp = *str + 42;
			while (del_symb - tmp < 0)
			{
				tmp = (del_symb - tmp) * -1;
				tmp = tmp + del_symb - 26;
			}
			del_symb = 0;
			*str = tmp;
		}
		str++;
	}
	return (str);
}
