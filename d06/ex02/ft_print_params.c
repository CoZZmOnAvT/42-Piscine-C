/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 15:29:24 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/02 15:29:25 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char const *argv[])
{
	int		it;

	it = 1;
	while (it < argc)
	{
		while (*argv[it])
			ft_putchar(*argv[it]++);
		it++;
		ft_putchar('\n');
	}
	return (0);
}
