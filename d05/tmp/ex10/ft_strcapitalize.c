/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 17:05:16 by pgritsen          #+#    #+#             */
/*   Updated: 2017/07/31 17:05:17 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		str_len(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strlowcase(char *str)
{
	int		it;

	it = 0;
	while (str[it] > 0)
	{
		if (str[it] >= 'A' && str[it] <= 'Z')
			str[it] = str[it] + 32;
		it++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int		it;

	ft_strlowcase(str);
	it = 0;
	while (str[it])
	{
		if ((it == 0 || str[it] < '0' || (str[it] > '9' && str[it] <= 'A')
			|| (str[it] > 'Z' && str[it] < 'a') || str[it] > 'z')
			&& it + 1 < str_len(str)
			&& str[it + 1] >= 'a'
			&& str[it + 1] <= 'z')
		{
			if (it == 0)
				str[it] -= 32;
			else
				str[it + 1] -= 32;
		}
		it++;
	}
	return (str);
}
