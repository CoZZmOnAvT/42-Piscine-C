#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/07 18:51:16 by pgritsen          #+#    #+#              #
#    Updated: 2017/08/07 18:51:17 by pgritsen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = do-op

SRCS =	calculate.c	\
		do_op.c		\
		print.c		\
		validation.c

all:$(NAME)

$(NAME):
	@gcc -Wextra -Wall -Werror $(SRCS) -o $(NAME)

.PHONY:clean

clean:
	@rm -f $(NAME)
