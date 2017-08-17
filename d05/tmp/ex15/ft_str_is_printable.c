/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 17:49:43 by pgritsen          #+#    #+#             */
/*   Updated: 2017/07/31 17:49:45 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_printable(char *str)
{
	int		it;

	it = 0;
	while (str[it])
	{
		if (str[it] > 0 && str[it] <= 31)
			return (0);
		it++;
	}
	return (1);
}