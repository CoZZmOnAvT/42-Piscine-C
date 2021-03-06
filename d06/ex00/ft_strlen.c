/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 09:24:21 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/02 09:24:23 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long	ft_strlen(char *str)
{
	unsigned long	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
