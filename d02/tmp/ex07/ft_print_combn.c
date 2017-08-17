/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 09:04:30 by pgritsen          #+#    #+#             */
/*   Updated: 2017/07/27 11:43:52 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_putchar.c"

void	print_nums(int n)
{
	char it;

	if (n <= 0)
		return ;

	it = '0';
	
	while (it <= '9' - n + 1)
	{
		print_nums(n - 1);
		
		ft_putchar(it);
		it++;
	}
	ft_putchar(' ');

}

void	ft_print_combn(int n)
{

}

int main()
{
	print_nums(2);
}
