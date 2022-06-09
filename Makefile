# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 17:39:14 by susami            #+#    #+#              #
#    Updated: 2022/06/09 21:39:05 by susami           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I include

OUTDIR		=	objs
SRCS		=	src/main.c				\
				src/model/stack.c				\
				src/model/ctx.c				\
				src/operation/op.c				\
				src/operation/op_basic.c			\
				src/operation/op_s.c				\
				src/operation/op_p.c				\
				src/operation/op_r.c				\
				src/operation/op_rr.c				\
				src/operation/opflush.c			\
				src/operation/optimize.c			\
				src/operation/optimize_s.c		\
				src/operation/optimize_p.c		\
				src/operation/optimize_r.c		\
				src/operation/optimize_rr.c		\
				src/utility/utility.c			\
				src/utility/utility2.c			\
				src/utility/argparse.c			\
				src/utility/print.c				\
				src/utility/simplify.c			\
				src/sort/selection_sort.c	\
				src/sort/quick_sort.c		\
				src/sort/insert_sort.c		\
				src/sort/radix_sort.c		\

OBJS		=	$(SRCS:%.c=$(OUTDIR)/%.o)

LIBFTDIR	=	libft
LIBFT		=	$(LIBFTDIR)/libft.a
LIB			=	$(LIBFT)

.PHONY: all clean fclean re test norm

all: $(NAME)

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	$(RM) src/*.o bonus/*.o *.out
	$(RM) -r $(OUTDIR)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	$(RM) $(NAME) tests/test_basic_op

re: fclean all

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

debug: fclean
	$(MAKE) debug -C $(LIBFTDIR)
	$(MAKE) CFLAGS="$(CFLAGS) -D DEBUG=1 -D OPTIMIZE=1"

$(OUTDIR)/%.o: %.c
	@mkdir -p $$(dirname $@)
	$(CC) -c $< -o $@ $(CFLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

test: $(TEST_OBJS) $(LIB)
	./test.sh

norm:
	norminette src | grep Error
	norminette include | grep Error
