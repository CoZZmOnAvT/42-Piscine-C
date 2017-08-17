/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 23:44:23 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/03 23:44:24 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ultimator.h>
#include <stdlib.h>

void	ft_destroy(char ***factory)
{
	while (***factory)
	{
		while (**factory)
			free(*factory++);
		free(*factory++);
	}
	free(*factory);
}
