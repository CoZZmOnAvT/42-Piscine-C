#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: modnosum <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/12 20:40:23 by modnosum          #+#    #+#              #
#    Updated: 2017/08/13 19:35:27 by modnosum         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC			=	gcc
CFLAGS		?=	-Wall -Wextra -Werror
CFLAGS		+=	-I.

NORM		=	norminette

TARGET		=	rush-2
MAIN		=	main.c
UTILS		=	libutils.a
FT			=	libft.a

.PHONY: all norm clean fclean re

all: $(TARGET)

$(TARGET): $(MAIN) $(UTILS) $(FT)
	@$(CC) -o $(TARGET) $^ $(CFLAGS)

$(UTILS): $(wildcard utils_*.c)
	@$(CC) $(CFLAGS) -c $^
	@ar crs $@ *.o
	@rm -f *.o

$(FT): $(wildcard ft_*.c)
	@$(CC) $(CFLAGS) -c $^
	@ar crs $@ *.o
	@rm -f *.o

norm: $(wildcard *.h) $(wildcard utils_*.c) $(wildcard ft_*.c) main.c
	@echo $^
	@$(NORM) $^

clean:
	@rm -f $(UTILS) $(FT)

fclean: clean
	@rm -f $(TARGET)

re: fclean all
