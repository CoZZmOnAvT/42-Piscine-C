/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 12:16:31 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/03 12:16:33 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned long	ft_strlen(char *str)
{
	unsigned long	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int				find_in_str(char *str, char symb)
{
	int		it;
	int		found;

	it = 0;
	found = -1;
	while (str[it])
	{
		if (symb == str[it])
		{
			found = 1;
			break ;
		}
		it++;
	}
	if (found == -1)
		return (-1);
	else
		return (it);
}

char			*convertation(int baseto_len, int nbr_i, char *base_to)
{
	int		it[2];
	char	tmp;
	char	*result;

	result = (char *)malloc(sizeof(char) * 4096);
	it[0] = 0;
	while (nbr_i / baseto_len > 0)
	{
		result[it[0]++] = base_to[nbr_i % baseto_len];
		nbr_i /= baseto_len;
	}
	result[it[0]++] = base_to[nbr_i % baseto_len];
	it[1] = 0;
	it[0]--;
	while (it[0] >= it[1])
	{
		tmp = result[it[0]];
		result[it[0]] = result[it[1]];
		result[it[1]] = tmp;
		it[1]++;
		it[0]--;
	}
	return (result);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nbr_i;
	char	*result;

	nbr_i = 0;
	while (*nbr)
	{
		if (find_in_str(base_from, *nbr) != -1)
			nbr_i = nbr_i * (int)ft_strlen(base_from)
					+ find_in_str(base_from, *nbr);
		else
			return (0);
		nbr++;
	}
	result = convertation((int)ft_strlen(base_to), nbr_i, base_to);
	return (result);
}
