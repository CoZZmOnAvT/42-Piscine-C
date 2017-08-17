/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 17:02:59 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/05 17:03:01 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void				ft_show_tab(struct s_stock_par *par);

char				**ft_split_whitespaces(char *str);

unsigned long		ft_strlen(char *str)
{
	unsigned long	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

unsigned int		ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	it;

	it = 0;
	while (src[it] && it < size - 1)
	{
		dest[it] = src[it];
		it++;
	}
	dest[it] = 0;
	return ((unsigned int)ft_strlen(src));
}

char				*ft_strdup(char *src)
{
	char			*clone;
	unsigned long	src_len;

	src_len = ft_strlen(src);
	clone = (char *)malloc(sizeof(char) * (src_len + 1));
	ft_strlcpy(clone, src, src_len + 1);
	if (ft_strlen(clone) != src_len)
		return (0);
	return (clone);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	struct s_stock_par	*res;
	int					it;

	res = (struct s_stock_par*)malloc(sizeof(struct s_stock_par) * (ac + 1));
	it = 0;
	while (it < ac)
	{
		res[it].size_param = ft_strlen(av[it]);
		res[it].str = av[it];
		res[it].copy = ft_strdup(av[it]);
		res[it].tab = ft_split_whitespaces(av[it]);
		it++;
	}
	res[it].str = 0;
	return (res);
}
