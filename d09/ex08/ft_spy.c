/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 01:45:35 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/04 01:45:36 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	int		it;

	it = 0;
	while (str[it] > 0)
	{
		if (str[it] >= 'A' && str[it] <= 'Z')
			str[it] = str[it] + 32;
		it++;
	}
	return (str);
}

int		ft_strcmp_m(char *s1, char *s2)
{
	int		it;
	int		it_c;

	it = 0;
	while ((s1[it] >= 9 && s1[it] <= 13) || s1[it] == 32)
		it++;
	it_c = 0;
	while (s1[it] > 0 && s2[it_c] > 0)
	{
		if (s1[it] >= 9 && s1[it] <= 13 && s1[it] == 32)
			continue ;
		if (s1[it] != s2[it_c])
		{
			return ((unsigned int)s1[it] - (unsigned int)s2[it_c]);
		}
		it_c++;
		it++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	while (argc > 1)
	{
		ft_strlowcase(argv[argc - 1]);
		if (ft_strcmp_m(argv[argc - 1], "president") == 0
			|| ft_strcmp_m(argv[argc - 1], "attack") == 0
			|| ft_strcmp_m(argv[argc - 1], "powers") == 0)
		{
			write(1, "Alert!!!\n", 9);
			return (0);
		}
		argc--;
	}
	return (0);
}
