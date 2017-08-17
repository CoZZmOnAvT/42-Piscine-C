/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 15:50:03 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/02 15:50:05 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char const *argv[])
{
	while (argc-- > 1)
	{
		while (*argv[argc])
			ft_putchar(*argv[argc]++);
		ft_putchar('\n');
	}
	return (0);
}
