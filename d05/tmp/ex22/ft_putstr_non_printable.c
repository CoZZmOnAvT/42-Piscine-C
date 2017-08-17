/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 11:32:49 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/01 11:32:52 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BASE "0123456789abcdef"

int				ft_putchar(char c);

unsigned long	str_len(char *str)
{
	unsigned long	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void			ft_putnbr_16_base(int nbr)
{
	unsigned long	base_len;
	char			resault[2048];
	int				it;

	if (nbr < 0)
		nbr *= -1;
	it = 0;
	base_len = str_len(BASE);
	while (nbr / base_len >= base_len)
	{
		resault[it++] = BASE[nbr % base_len];
		nbr /= base_len;
	}
	resault[it++] = BASE[nbr % base_len];
	resault[it] = BASE[nbr / base_len];
	while (it >= 0)
		ft_putchar(resault[it--]);
}

void			ft_putstr_non_printable(char *str)
{
	while (str[0])
	{
		if (str[0] <= 31)
		{
			ft_putchar('\\');
			ft_putnbr_16_base(str[0]);
		}
		else
			ft_putchar(str[0]);
		str++;
	}
}
