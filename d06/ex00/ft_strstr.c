/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 12:29:29 by pgritsen          #+#    #+#             */
/*   Updated: 2017/07/31 12:29:31 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long	ft_strlen(char *str);

char	*ft_strstr(char *str, char *to_find)
{
	int		s_it;
	int		f_it;
	int		found;

	s_it = 0;
	found = -1;
	while (str[s_it])
	{
		f_it = 0;
		while (str[s_it + f_it] == to_find[f_it] && to_find[f_it] != 0)
		{
			if (f_it == 0)
				found = s_it;
			f_it++;
		}
		if (f_it == (int)ft_strlen(to_find))
			return (&str[found]);
		s_it++;
	}
	return (0);
}
