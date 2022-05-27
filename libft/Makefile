# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 07:33:20 by susami            #+#    #+#              #
#    Updated: 2022/05/26 23:14:09 by susami           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -I .
NAME	=	libft.a
INC		=	libft.h
M_SRCS	=	ft_isalpha.c	\
			ft_isdigit.c	\
			ft_isalnum.c	\
			ft_isascii.c	\
			ft_isprint.c	\
			ft_strlen.c		\
			ft_memset.c		\
			ft_bzero.c		\
			ft_memcpy.c		\
			ft_memmove.c	\
			ft_strlcpy.c	\
			ft_strlcat.c	\
			ft_toupper.c	\
			ft_tolower.c	\
			ft_strchr.c		\
			ft_strrchr.c	\
			ft_strncmp.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_strnstr.c	\
			ft_atoi.c		\
			ft_calloc.c		\
			ft_strdup.c		\
			ft_substr.c		\
			ft_strjoin.c	\
			ft_strtrim.c	\
			ft_split.c		\
			ft_itoa.c		\
			ft_strmapi.c	\
			ft_striteri.c	\
			ft_putchar_fd.c	\
			ft_putstr_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\

B_SRCS	=	ft_lstnew.c			\
			ft_lstadd_front.c	\
			ft_lstsize.c		\
			ft_lstlast.c		\
			ft_lstadd_back.c	\
			ft_lstdelone.c		\
			ft_lstclear.c		\
			ft_lstiter.c		\
			ft_lstmap.c			\

PRINTF_SRCS	=	ft_printf/ft_printf.c\
				ft_printf/ft_printf_cs.c\
				ft_printf/ft_printf_diu.c\
				ft_printf/ft_printf_fmt.c\
				ft_printf/ft_printf_hex.c\
				ft_printf/ft_printf_parser.c\
				ft_printf/ft_printf_percent.c\
				ft_printf/ft_printf_px.c\

OUT_O_DIR	=	output
SRCS		=	$(M_SRCS) $(B_SRCS) $(PRINTF_SRCS)
OBJS=$(SRCS:%.c=$(OUT_O_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(INC)
	ar -r $(NAME) $(OBJS) 

clean:
	@$(RM) $(OUT_O_DIR)/*.o $(OUT_O_DIR)/*.o

fclean: clean
	@$(RM) $(NAME)

re: fclean all

$(OUT_O_DIR)/%.o: %.c
	@mkdir -p $(OUT_O_DIR)
	@mkdir -p $(OUT_O_DIR)/ft_printf
	$(CC) -c $< -o $@ $(CFLAGS)

.PHONY: all clean fclean re
