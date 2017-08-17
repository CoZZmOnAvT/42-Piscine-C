/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 12:01:36 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/01 12:01:38 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BASE "0123456789abcdef"
#define BASE_SIZE 16

long int	g_resault;
char		g_input[2048];

int				ft_putchar(char c);

void			ft_putnbr_base(unsigned int nbr)
{
	char			resault[2048];
	long int		nbr_t;
	int				it;

	nbr_t = nbr;
	it = 0;
	while (nbr_t / BASE_SIZE >= BASE_SIZE)
	{
		resault[it++] = BASE[nbr_t % BASE_SIZE];
		nbr_t /= BASE_SIZE;
	}
	resault[it++] = BASE[nbr_t % BASE_SIZE];
	resault[it] = BASE[nbr_t / BASE_SIZE];
	while (it >= 0)
		ft_putchar(resault[it--]);
}

void			print_hex_memory(unsigned int *it, unsigned char *src,
	unsigned int size)
{
	int spc_it;

	if (*it < size)
	{
		ft_putnbr_base((unsigned int)src[*it]);
		if (*it + 1 < size)
			ft_putnbr_base((unsigned int)src[*it + 1]);
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		ft_putchar(' ');
	}
	else
	{
		spc_it = 0;
		while (spc_it++ < 5)
			ft_putchar(' ');
	}
	*it = *it + 2;
}

void			print_string(unsigned char *src, unsigned int size)
{
	unsigned int	it;

	it = 0;
	while (it < 16)
		print_hex_memory(&it, src, size);
	ft_putchar(' ');
	it = 0;
	while (it < 16 && it < size)
	{
		if (src[it] <= 31)
			ft_putchar('.');
		else
			ft_putchar(src[it]);
		if (it + 1 < size && src[it + 1] <= 31)
			ft_putchar('.');
		else if (it + 1 < size)
			ft_putchar(src[it + 1]);
		it += 2;
	}
}

void			*ft_print_memory(void *addr, unsigned int size)
{
	int				intr_it;
	unsigned char	*src;

	src = addr;
	intr_it = size / 16;
	while (intr_it >= 0 && (unsigned)intr_it < size)
	{
		ft_putnbr_base((unsigned int)&src[0]);
		ft_putchar(':');
		ft_putchar(' ');
		print_string(src, size);
		intr_it--;
		src += 16;
		size -= 16;
		ft_putchar('\n');
	}
	return (addr);
}
