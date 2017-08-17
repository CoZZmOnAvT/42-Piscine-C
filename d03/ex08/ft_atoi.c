/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 20:55:11 by pgritsen          #+#    #+#             */
/*   Updated: 2017/07/28 18:24:11 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_first_non_space(char *str)
{
	int i;

	i = 0;
	while (str[i] > 0 && str[i] <= 32)
	{
		i += 1;
	}
	if (str[i] != 0)
	{
		return (i);
	}
	return (-1);
}

int	get_string_len(char *str)
{
	int len;

	len = 0;
	while (str[len] != 0)
	{
		len += 1;
	}
	return (len);
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int g_atoi_first_non_space;
int g_atoi_num_length;
int g_atoi_result;
int g_atoi_mult;

int	ft_atoi(char *str)
{
	g_atoi_first_non_space = get_first_non_space(str);
	if (str[g_atoi_first_non_space] < '0'
		|| str[g_atoi_first_non_space] > '9' || g_atoi_first_non_space == -1)
	{
		return (0);
	}
	g_atoi_num_length = g_atoi_first_non_space;
	while (str[g_atoi_num_length] >= '0' && str[g_atoi_num_length] <= '9')
	{
		g_atoi_num_length++;
	}
	g_atoi_num_length--;
	g_atoi_result = 0;
	g_atoi_mult = 1;
	while (g_atoi_num_length >= g_atoi_first_non_space)
	{
		g_atoi_result += g_atoi_mult * (str[g_atoi_num_length] - 48);
		g_atoi_mult *= 10;
		g_atoi_num_length -= 1;
	}
	return (g_atoi_result);
}
