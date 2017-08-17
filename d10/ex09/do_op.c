/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 19:02:32 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/07 19:02:32 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	if (!input_data_correct(argv))
		return (0);
	calculate(argv[1], argv[2], argv[3]);
	return (0);
}
