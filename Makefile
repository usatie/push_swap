# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 17:39:14 by susami            #+#    #+#              #
#    Updated: 2022/06/16 08:59:12 by susami           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
B_NAME		=	checker

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I include

OUTDIR		=	objs
SRCS		=	src/main.c						\
				src/model/stack.c				\
				src/model/stack_op.c			\
				src/model/ctx.c					\
				src/model/ctx_len.c				\
				src/model/ctx_get.c				\
				src/model/ctx_get2.c			\
				src/model/ctx_minmax.c			\
				src/model/ctx_op.c				\
				src/model/ctx_print.c			\
				src/op/op.c						\
				src/op/op_s.c					\
				src/op/op_p.c					\
				src/op/op_r.c					\
				src/op/op_rr.c					\
				src/optimizer/opflush.c			\
				src/optimizer/optimize.c		\
				src/optimizer/optimize_s.c		\
				src/optimizer/optimize_p.c		\
				src/optimizer/optimize_r.c		\
				src/optimizer/optimize_rr.c		\
				src/utility/utility.c			\
				src/utility/argparse.c			\
				src/utility/argparse_sort.c		\
				src/utility/simplify.c			\
				src/sort/selection_sort.c		\
				src/sort/quick_sort.c			\
				src/sort/insert_sort.c			\
				src/sort/radix_sort.c			\
				src/sort/custom_sort.c			\
				src/sort/small_sort.c			\
				src/sort/custom_sort2.c			\
				src/sort/partition.c			\
				src/debug/ft_debug_printf.c		\

B_SRCS		=	bonus/checker.c					\

OBJS		=	$(SRCS:%.c=$(OUTDIR)/%.o)
B_OBJS		=	$(B_SRCS:%.c=$(OUTDIR)/%.o)

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
	$(RM) $(NAME)
	$(RM) $(B_NAME)

re: fclean all

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

debug:
	$(RM) src/*.o bonus/*.o *.out
	$(RM) -r $(OUTDIR)
	$(RM) $(NAME)
	$(RM) $(B_NAME)
	$(MAKE) $(NAME) CFLAGS="$(CFLAGS) -D DEBUG=1 -D OPTIMIZE=1"
	$(MAKE) $(B_NAME) CFLAGS="$(CFLAGS) -D DEBUG=1 -D OPTIMIZE=1"

$(OUTDIR)/%.o: %.c
	@mkdir -p $$(dirname $@)
	$(CC) -c $< -o $@ $(CFLAGS)

bonus: $(B_OBJS) $(filter-out objs/src/main.o,$(OBJS)) $(LIB)
	$(CC) $(CFLAGS) $(B_OBJS) $(filter-out objs/src/main.o,$(OBJS)) $(LIB) -o $(B_NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

test: $(TEST_OBJS) $(LIB)
	./test.sh

norm:
	norminette src include libft | grep Error
