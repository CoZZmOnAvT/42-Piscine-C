/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 10:40:03 by pgritsen          #+#    #+#             */
/*   Updated: 2017/07/31 10:40:05 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	is_negative(long int *mult, char sign, int *it)
{
	if (sign == '-')
	{
		*it = *it + 1;
		*mult = *mult / 10;
		*mult = *mult * (-1);
	}
	else if (sign == '+')
	{
		*it = *it + 1;
		*mult = *mult / 10;
	}
}

int		ft_atoi(char *str)
{
	int			num_start;
	int			mult_it;
	long int	mult;
	int			resault;

	num_start = 0;
	if (str[num_start] == 0)
		return (0);
	while (((str[num_start] > '\10' && str[num_start] <= '\16')
		|| str[num_start] == '\40') && str[num_start] != '-')
		num_start++;
	mult = 1;
	mult_it = num_start;
	while (str[++mult_it] >= '0' && str[mult_it] <= '9')
		mult *= 10;
	is_negative(&mult, str[num_start], &num_start);
	resault = 0;
	while (str[num_start] >= '0' && str[num_start] <= '9')
	{
		resault += (str[num_start++] - 48) * mult;
		mult /= 10;
	}
	return (resault);
}
