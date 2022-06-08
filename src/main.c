/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:43:10 by susami            #+#    #+#             */
/*   Updated: 2022/06/09 02:23:57 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "ft_error_functions.h"
#include "push_swap.h"

// returns result context for quick sort
static t_ctx	*quicksort(int argc, char **argv)
{
	t_ctx	*c;

	c = argparse_ctx(argc, argv);
	if (c == NULL)
		return (NULL);
	ft_debug_printf("\n=====INITIAL STACKS=====\n");
	debug_print_ctx(c);
	ft_debug_printf("========================\n\n");
	if (argc >= 2)
		quick_sort(c, 0, argc - 2);
	ft_debug_printf("\n=====[QUICK SORT RESULT](result=%d)=====\n\n", n_op(c));
	debug_print_ctx(c);
	c = optimize(argc, argv, c);
	return (c);
}

// returns result context for selection sort
static t_ctx	*selectionsort(int argc, char **argv)
{
	t_ctx	*c;

	c = argparse_ctx(argc, argv);
	if (c == NULL)
		return (NULL);
	ft_debug_printf("\n=====INITIAL STACKS=====\n");
	debug_print_ctx(c);
	ft_debug_printf("========================\n\n");
	if (argc >= 2)
		selection_sort(c);
	ft_debug_printf("\n=====[SELECTION RESULT] (result=%d)=====\n\n", n_op(c));
	debug_print_ctx(c);
	c = optimize(argc, argv, c);
	return (c);
}

// returns result context for insert sort
static t_ctx	*insertsort(int argc, char **argv)
{
	t_ctx	*c;

	c = argparse_ctx(argc, argv);
	if (c == NULL)
		return (NULL);
	ft_debug_printf("\n=====INITIAL STACKS=====\n");
	debug_print_ctx(c);
	ft_debug_printf("========================\n\n");
	if (argc >= 2)
		insert_sort(c);
	ft_debug_printf("\n=====[INSERT SORT RESULT] (result=%d)=====\n\n", n_op(c));
	debug_print_ctx(c);
	c = optimize(argc, argv, c);
	return (c);
}

/*
int	main(int argc, char **argv)
{
	t_ctx	*c1;

	(void)selectionsort;
	(void)insertsort;
	c1 = quicksort(argc, argv);
	print_ops(c1);
	ctx_deinit(c1);
	return (EXIT_SUCCESS);
}
*/
int	main(int argc, char **argv)
{
	t_ctx	*c1;
	t_ctx	*c2;
	t_ctx	*c3;

	c1 = quicksort(argc, argv);
	c2 = selectionsort(argc, argv);
	c3 = insertsort(argc, argv);
	if (c1 == NULL || c2 == NULL || c3 == NULL)
	{
		ctx_deinit(c1);
		ctx_deinit(c2);
		ctx_deinit(c3);
		err_exit("Error\n");
	}
	ft_debug_printf("[q: %d, s: %d, i: %d]\n", n_op(c1), n_op(c2), n_op(c3));
	if (min(min(n_op(c1), n_op(c2)), n_op(c3)) == n_op(c1))
		print_ops(c1);
	else if (min(min(n_op(c1), n_op(c2)), n_op(c3)) == n_op(c2))
		print_ops(c2);
	else if (min(min(n_op(c1), n_op(c2)), n_op(c3)) == n_op(c3))
		print_ops(c3);
	ctx_deinit(c1);
	ctx_deinit(c2);
	ctx_deinit(c3);
	return (EXIT_SUCCESS);
}
