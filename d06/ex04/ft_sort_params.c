/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 17:21:46 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/02 17:21:49 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	display_argv(int argc, char *argv[])
{
	int it;

	it = 1;
	while (it < argc)
	{
		while (*argv[it])
			ft_putchar(*argv[it]++);
		ft_putchar('\n');
		it++;
	}
}

void	sort_argv(int argc, char *argv[])
{
	int		it[3];
	char	*tmp;

	it[0] = 1;
	while (it[0]++ < argc - 1)
	{
		it[1] = 1;
		while (it[1] < argc - 1)
		{
			it[2] = 0;
			while (argv[it[1]][it[2]] >= argv[it[1] + 1][it[2]])
			{
				if (argv[it[1]][it[2]] > argv[it[1] + 1][it[2]])
				{
					tmp = argv[it[1] + 1];
					argv[it[1] + 1] = argv[it[1]];
					argv[it[1]] = tmp;
				}
				it[2]++;
			}
			it[1]++;
		}
	}
}

int		main(int argc, char *argv[])
{
	char	**argv_t;

	argv_t = argv;
	sort_argv(argc, argv);
	display_argv(argc, argv);
	return (0);
}
