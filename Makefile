# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 17:39:14 by susami            #+#    #+#              #
#    Updated: 2022/05/27 17:46:32 by susami           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I include

SRCS		=	./src/push_swap.c	
OBJS		=	$(SRCS:%.c=%.o)

LIBFTDIR	=	./libft
LIBFT		=	$(LIBFTDIR)/libft.a
LIB			=	$(LIBFT)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	$(RM) src/*.o bonus/*.o *.out

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)
