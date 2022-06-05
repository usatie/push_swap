/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:43:10 by susami            #+#    #+#             */
/*   Updated: 2022/06/05 16:15:05 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "ft_error_functions.h"
#include "push_swap.h"

static void	argparse_push(const char *arg, t_ps_ctx *c)
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
	t_ps_ctx	*c;

	c = init_ctx(argc - 1);
	while (--argc > 0)
		argparse_push(argv[argc], c);
	if (VERBOSE)
		ft_printf("\n=====INITIAL STACKS=====\n");
	print_ctx(c);
	if (VERBOSE)
		ft_printf("========================\n\n");
	insert_sort(c);
	if (VERBOSE)
		ft_printf("\n=====SORT RESULT(n_op=%d)=====\n\n", c->n_op);
	print_ctx(c);
	deinit_ctx(c);
	return (EXIT_SUCCESS);
}
