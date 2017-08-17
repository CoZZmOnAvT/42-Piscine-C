#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgritsen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/16 17:47:32 by pgritsen          #+#    #+#              #
#    Updated: 2017/08/16 17:47:33 by pgritsen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =	bsq

CC	=	gcc

FLAGC = -Wextra -Werror -Wall

SRC =	node.c					\
		core.c					\
		atoi.c					\
		utils_helpers.c			\
		utils_input_output.c	\

OBJ =	node.o					\
		core.o					\
		atoi.o					\
		utils_helpers.o			\
		utils_input_output.o	\

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(FLAGC) -c $(SRC)
	@$(CC) $(FLAGC) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all