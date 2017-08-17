/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 20:33:31 by pgritsen          #+#    #+#             */
/*   Updated: 2017/07/31 20:33:33 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_putchar(char c);

unsigned long	ft_strlen(char *str);

int				check_base(char *base)
{
	int base_len;
	int it[2];

	base_len = (int)ft_strlen(base);
	if (base_len < 2)
		return (0);
	it[0] = 0;
	while (it[0] < base_len)
	{
		it[1] = 1;
		while (it[1] < base_len)
		{
			if ((base[it[0]] == base[it[1]] && it[0] != it[1])
				|| base[it[1]] == '-' || base[it[1]] == '+'
				|| (((unsigned)base[it[0]] > 0 && (unsigned)base[it[0]] < 9)
					|| ((unsigned)base[it[0]] > 13
					&& (unsigned)base[it[0]] <= 31))
				|| base[it[0]] <= '\200')
				return (0);
			it[1]++;
		}
		it[0]++;
	}
	return (1);
}

void			ft_putnbr_base(int nbr, char *base)
{
	unsigned long	base_len;
	char			resault[2048];
	long int		nbr_t;
	int				it;

	if (!check_base(base))
		return ;
	nbr_t = nbr;
	if (nbr_t < 0)
	{
		nbr_t *= -1;
		ft_putchar('-');
	}
	it = 0;
	base_len = ft_strlen(base);
	while (nbr_t / base_len >= base_len)
	{
		resault[it++] = base[nbr_t % base_len];
		nbr_t /= base_len;
	}
	resault[it++] = base[nbr_t % base_len];
	if (base[nbr_t / base_len] - 48 != 0)
		resault[it] = base[nbr_t / base_len];
	while (it >= 0)
		ft_putchar(resault[it--]);
}
