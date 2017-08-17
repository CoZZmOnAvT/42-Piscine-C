/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 09:17:13 by pgritsen          #+#    #+#             */
/*   Updated: 2017/08/10 09:17:14 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t.h"

void	read_file(char *file_name)
{
	int		f_desc;
	char	*buff[65534];
	int		bytes_read;

	f_desc = open(file_name, O_RDONLY);
	if (f_desc < 0)
		return ;
	bytes_read = read(f_desc, buff, 65534);
	if (bytes_read == FILE_ERROR)
		return ;
	write(1, buff, bytes_read);
	close(f_desc);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		return (write(2, "File name missing.\n", 19));
	if (argc > 2)
		return (write(2, "Too many arguments.\n", 20));
	read_file(argv[1]);
}
