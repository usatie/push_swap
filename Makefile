# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 17:39:14 by susami            #+#    #+#              #
#    Updated: 2022/06/06 19:46:18 by susami           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I include

OUTDIR		=	objs
SRCS		=	src/main.c				\
				src/stack.c				\
				src/ctx.c				\
				src/op_basic.c			\
				src/op_s.c				\
				src/op_p.c				\
				src/op_r.c				\
				src/op_rr.c				\
				src/utility.c			\
				src/utility2.c			\
				src/opflush.c			\
				src/insert_sort.c		\
				src/quick_sort.c		\

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
	$(MAKE) CFLAGS="$(CFLAGS) -D DEBUG=1 OPTIMIZE=0"

$(OUTDIR)/%.o: %.c
	@mkdir -p $$(dirname $@)
	$(CC) -c $< -o $@ $(CFLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

test: $(TEST_OBJS) $(LIB)
	$(CC) $(CFLAGS) $(filter-out $(OUTDIR)/src/main.o, $(OBJS)) $(LIB) tests/test_basic_op.c -o tests/test_basic_op
	./tests/test_basic_op
	./tests/test.sh

norm:
	norminette src/*.c | grep Error
	norminette include/*.c | grep Error
