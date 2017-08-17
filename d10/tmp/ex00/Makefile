#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/07 09:54:02 by pgritsen          #+#    #+#              #
#    Updated: 2017/08/07 12:15:02 by pgritsen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = libft.a

FILES_SRC = srcs/ft_putchar.c	\
			srcs/ft_putstr.c	\
			srcs/ft_strcmp.c	\
			srcs/ft_strlen.c	\
			srcs/ft_swap.c

FILES_INCLDS = includes/*.h

FILES_OBJ = ft_putchar.o	\
			ft_putstr.o		\
			ft_strcmp.o		\
			ft_strlen.o		\
			ft_swap.o

FILES_PH = includes/*.gch

all:$(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(FILES_SRC) $(FILES_INCLDS)
	@ar rc $(NAME) $(FILES_OBJ)

.PHONY:clean

clean:
	@rm -f $(FILES_OBJ)

fclean:clean
	@rm -f $(NAME)
	@rm -f $(FILES_PH)

re:fclean all
