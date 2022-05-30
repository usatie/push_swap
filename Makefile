# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 17:39:14 by susami            #+#    #+#              #
#    Updated: 2022/05/27 21:44:33 by susami           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I include

OUTDIR		=	output
SRCS		=	src/push_swap.c	
OBJS		=	$(SRCS:%.c=$(OUTDIR)/%.o)

LIBFTDIR	=	libft
LIBFT		=	$(LIBFTDIR)/libft.a
LIB			=	$(LIBFT)


.PHONY: all clean fclean re

all: $(NAME)

clean:
	$(RM) src/*.o bonus/*.o *.out output/**/*.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

$(OUTDIR)/%.o: %.c
	@mkdir -p $$(dirname $@)
	$(CC) -c $< -o $@ $(CFLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)
