# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 17:39:14 by susami            #+#    #+#              #
#    Updated: 2022/05/31 00:59:57 by susami           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I include

OUTDIR		=	output
SRCS		=	src/push_swap.c		\
				src/stack.c			\
				src/machine.c		\
				src/op_basic.c		\
				src/op_s.c		\
				src/op_p.c		\
				src/op_r.c		\
				src/op_rr.c		\
				src/insert_sort.c		\

TEST_SRCS	=	tests/test_basic_op.c		\
				src/stack.c					\
				src/machine.c				\
				src/op_basic.c				\
				src/op_s.c					\
				src/op_p.c					\
				src/op_r.c					\
				src/op_rr.c					\

OBJS		=	$(SRCS:%.c=$(OUTDIR)/%.o)
TEST_OBJS	=	$(TEST_SRCS:%.c=$(OUTDIR)/%.o)

LIBFTDIR	=	libft
LIBFT		=	$(LIBFTDIR)/libft.a
LIB			=	$(LIBFT)


.PHONY: all clean fclean re test

all: $(NAME)

clean:
	$(RM) src/*.o bonus/*.o *.out output/**/*.o

fclean: clean
	$(RM) $(NAME) runtest

re: fclean all

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

$(OUTDIR)/%.o: %.c
	@mkdir -p $$(dirname $@)
	$(CC) -c $< -o $@ $(CFLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

test: $(TEST_OBJS) $(LIB)
	$(CC) $(CFLAGS) $(TEST_OBJS) $(LIB) -o runtest
	./runtest

