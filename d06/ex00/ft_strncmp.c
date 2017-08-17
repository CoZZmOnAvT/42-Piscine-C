/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 16:35:19 by pgritsen          #+#    #+#             */
/*   Updated: 2017/07/31 16:35:22 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	it;

	it = 0;
	while ((s1[it] > 0 || s2[it] > 0) && it < n)
	{
		if (s1[it] != s2[it])
			return ((unsigned int)s1[it] - (unsigned int)s2[it]);
		it++;
	}
	return (0);
}
