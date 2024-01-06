# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lteng <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 12:55:53 by lteng             #+#    #+#              #
#    Updated: 2024/01/05 13:07:50 by lteng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = pipex.c libft/libft.a

OBJS = $(SRCS:%.c=%.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = pipex

RM = rm -rf

AR = ar rc

all:	$(NAME)

$(NAME):
	make all -C libft
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
