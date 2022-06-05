/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:43:10 by susami            #+#    #+#             */
/*   Updated: 2022/06/05 22:55:00 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "ft_error_functions.h"
#include "push_swap.h"

static void	argparse_push(const char *arg, t_ctx *c)
{
	char	*endptr;
	t_elm	new;

	if (*arg == '\0')
	{
		deinit_ctx(c);
		err_exit("null or empty string");
	}
	errno = 0;
	new = ft_strtol(arg, &endptr, 10);
	if (errno != 0)
	{
		deinit_ctx(c);
		err_exit("ft_strtol() failed\n	text: %s", arg);
	}
	if (*endptr != '\0')
	{
		deinit_ctx(c);
		err_exit("nonnumeric characters\n	text: %s", arg);
	}
	if (contains(new, c->a))
	{
		deinit_ctx(c);
		err_exit("duplicate values\n", arg);
	}
	push(c->a, new);
}

int	main(int argc, char **argv)
{
	t_ctx	*c;
	t_ctx	*c1;
	t_ctx	*c2;

	c = init_ctx(argc - 1);
	c1 = init_ctx(argc - 1);
	c2 = init_ctx(argc - 1);
	c1->dry = TRUE;
	c2->dry = TRUE;
	while (--argc > 0)
	{
		argparse_push(argv[argc], c);
		argparse_push(argv[argc], c1);
		argparse_push(argv[argc], c2);
	}
	if (VERBOSE)
		ft_printf("\n=====INITIAL STACKS=====\n");
	print_ctx(c);
	if (VERBOSE)
		ft_printf("========================\n\n");
	insert_sort(c1);
	quick_sort(c2, 0, c2->a->len - 1);
	if (c1->n_op > c2->n_op)
		quick_sort(c, 0, c->a->len - 1);
	else
		insert_sort(c);

	if (VERBOSE)
		ft_printf("\n=====SORT RESULT(n_op=%d)=====\n\n", c->n_op);
	print_ctx(c);
	deinit_ctx(c);
	return (EXIT_SUCCESS);
}
