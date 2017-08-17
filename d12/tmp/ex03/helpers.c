/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 20:51:25 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/10 20:51:26 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t.h"

unsigned long	ft_strlen(char *str)
{
	unsigned long	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void			print(char *title, char *message, char *additional)
{
	write(1, title, ft_strlen(title));
	if (additional)
		write(1, additional, ft_strlen(additional));
	write(1, message, ft_strlen(message));
	write(1, "\n", 1);
}

char			*ft_strrev(char *str)
{
	int len;
	int i;
	int j;
	int temp;

	len = 0;
	while (str[len] != 0)
	{
		len += 1;
	}
	i = 0;
	j = len - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i += 1;
		j -= 1;
	}
	return (str);
}

char			*ft_putnbr_base(int nbr)
{
	char			*result;
	int				it;

	result = (char *)malloc(sizeof(char) * 2048);
	it = 0;
	while (nbr / BASE_SIZE >= BASE_SIZE)
	{
		result[it++] = BASE[nbr % BASE_SIZE];
		nbr /= BASE_SIZE;
	}
	result[it++] = BASE[nbr % BASE_SIZE];
	result[it] = BASE[nbr / BASE_SIZE];
	result = ft_strrev(result);
	return (result);
}
