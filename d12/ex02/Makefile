#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/10 10:58:11 by pgritsen          #+#    #+#              #
#    Updated: 2017/08/10 10:58:12 by pgritsen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

APP_NAME = ft_tail

SRC =	atoi.c	\
		node.c	\
		visual.c

all:$(APP_NAME)

$(APP_NAME):
	@gcc -Wextra -Wall -Werror $(SRC) -o $(APP_NAME)

.PHONY:clean

clean:
	@rm $(APP_NAME)
fclean:clean
	@rm -f $(APP_NAME)