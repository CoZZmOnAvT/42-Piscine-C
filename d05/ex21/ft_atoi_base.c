/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 00:46:25 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/01 00:46:28 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	it;

	it = 0;
	while (src[it] && it < size - 1)
	{
		dest[it] = src[it];
		it++;
	}
	dest[it] = 0;
	return (0);
}

char			*ft_strupcase(char *str)
{
	int		it;

	it = 0;
	while (str[it])
	{
		if (str[it] >= 'a' && str[it] <= 'z')
			str[it] = str[it] - 32;
		it++;
	}
	return (str);
}

long int	g_resault;
char		g_input[2][2048];
int			g_is_negative;

int				double_base(char *base)
{
	int it[2];

	it[0] = 0;
	while (base[it[0]])
	{
		it[1] = it[0] + 1;
		while (base[it[1]])
		{
			if (base[it[0]] == base[it[1]])
				return (1);
			it[1]++;
		}
		it[0]++;
	}
	return (0);
}

int				filter_input(char *str, char *base)
{
	int		it;

	if (str[0] == 0)
		return (-1);
	if (base[0] == 0 || base[1] == 0)
		return (-1);
	while (str[0] > 0 && str[0] <= 31)
		str++;
	if (str[0] == '-' || str[0] == '+')
	{
		g_is_negative = str[0] - 44;
		str++;
	}
	it = -1;
	while (base[++it] > 0)
		if (base[it] <= 31 || base[it] == '+' || base[it] == '-')
			return (-1);
	ft_strlcpy(g_input[0], str, 2048);
	ft_strlcpy(g_input[1], base, 2048);
	ft_strupcase(g_input[0]);
	ft_strupcase(g_input[1]);
	if (double_base(g_input[1]))
		return (-1);
	return (1);
}

int				ft_atoi_base(char *str, char *base)
{
	unsigned int	it[2];
	int				found;

	g_is_negative = 0;
	if (filter_input(str, base) == -1)
		return (0);
	it[0] = 0;
	g_resault = 0;
	while (g_input[0][it[0]] && g_input[0][it[0]] > 31)
	{
		it[1] = -1;
		found = 0;
		while (g_input[1][++it[1]])
			if (g_input[0][it[0]] == g_input[1][it[1]] && !found)
			{
				g_resault = g_resault * 16 + it[1];
				found = 1;
			}
		if (!found)
			return (0);
		it[0]++;
	}
	if (g_is_negative == 1)
		g_resault *= -1;
	return (g_resault);
}
