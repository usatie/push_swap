/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:43:10 by susami            #+#    #+#             */
/*   Updated: 2022/06/06 16:07:37 by susami           ###   ########.fr       */
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
	long	res;

	if (*arg == '\0')
	{
		deinit_ctx(c);
		err_exit("Error\n");
	}
	errno = 0;
	res = ft_strtol(arg, &endptr, 10);
	if (errno != 0 || *endptr != '\0' || res > INT_MAX || res < INT_MIN)
	{
		deinit_ctx(c);
		err_exit("Error\n");
	}
	if (contains(res, c->a))
	{
		deinit_ctx(c);
		err_exit("Error\n");
	}
	push(c->a, res);
}

static t_ctx	*argparse_ctx(int argc, char **argv)
{
	t_ctx	*c;

	c = init_ctx(argc - 1);
	if (c == NULL)
		return (NULL);
	while (--argc > 0)
		argparse_push(argv[argc], c);
	return (c);
}

// returns op count for quick sort
static size_t	quicksort(int argc, char **argv, BOOL dry)
{
	t_ctx	*c;
	size_t	n_op;

	c = argparse_ctx(argc, argv);
	if (c == NULL)
		err_exit("Error\n");
	ft_debug_printf("\n=====INITIAL STACKS=====\n");
	print_ctx(c);
	ft_debug_printf("========================\n\n");
	c->dry = dry;
	if (argc >= 2)
		quick_sort(c, 0, argc - 2);
	n_op = c->n_op;
	ft_debug_printf("\n=====[QUICK SORT RESULT](n_op=%d)=====\n\n", c->n_op);
	print_ctx(c);
	deinit_ctx(c);
	return (n_op);
}

// returns op count for insert sort
static size_t	insertsort(int argc, char **argv, BOOL dry)
{
	t_ctx	*c;
	size_t	n_op;

	c = argparse_ctx(argc, argv);
	if (c == NULL)
		err_exit("Error\n");
	ft_debug_printf("\n=====INITIAL STACKS=====\n");
	print_ctx(c);
	ft_debug_printf("========================\n\n");
	c->dry = dry;
	if (argc >= 2)
		insert_sort(c);
	n_op = c->n_op;
	ft_debug_printf("\n=====[INSERT SORT RESULT] (n_op=%d)=====\n\n", c->n_op);
	print_ctx(c);
	deinit_ctx(c);
	return (n_op);
}

int	main(int argc, char **argv)
{
	if (quicksort(argc, argv, TRUE) < insertsort(argc, argv, TRUE))
		quicksort(argc, argv, FALSE);
	else
		insertsort(argc, argv, FALSE);
	return (EXIT_SUCCESS);
}
