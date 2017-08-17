#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/10 16:50:36 by pgritsen          #+#    #+#              #
#    Updated: 2017/08/10 16:50:37 by pgritsen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

APP_NAME = ft_hexdump

SRC =	node.c		\
		helpers.c	\
		visual.c

all:$(APP_NAME)

$(APP_NAME):
	@gcc -Wextra -Wall -Werror $(SRC) -o $(APP_NAME)

clean:
	@rm $(APP_NAME)

fclean:
	@rm -f $(APP_NAME)