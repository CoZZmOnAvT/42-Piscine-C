/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 12:04:12 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/03 12:04:14 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**ft_split_whitespaces(char *str);

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int it;

	it = 0;
	while (str[it] != 0)
		ft_putchar(str[it++]);
}

void	ft_print_words_tables(char **tab)
{
	int		it;

	it = 0;
	while (tab[it])
	{
		ft_putstr(tab[it++]);
		ft_putchar('\n');
	}
}
