/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 17:44:32 by pgritsen          #+#    #+#             */
/*   Updated: 2017/07/31 17:44:35 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_uppercase(char *str)
{
	int		it;

	it = 0;
	while (str[it])
	{
		if (str[it] < 'A' || str[it] > 'Z')
			return (0);
		it++;
	}
	return (1);
}
