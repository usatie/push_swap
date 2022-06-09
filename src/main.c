/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:43:10 by susami            #+#    #+#             */
/*   Updated: 2022/06/09 18:28:05 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "ft_error_functions.h"
#include "push_swap.h"

#define NUM_SORT_METHOD 4
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

// returns result context for radix sort
static t_ctx	*_radixsort(int argc, char **argv)
{
	t_ctx	*c;

	c = argparse_ctx(argc, argv);
	if (c == NULL)
		return (NULL);
	ft_debug_printf("\n=====RADIX SORT=====\n");
	debug_print_ctx(c);
	ft_debug_printf("========================\n\n");
	if (argc >= 2)
		radix_sort(c);
	ft_debug_printf("\n=====[RADIX SORT RESULT] (result=%d)=====\n\n", n_op(c));
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
	(void)quicksort;
	c1 = _radixsort(argc, argv);
	print_ops(c1);
	ctx_deinit(c1);
	return (EXIT_SUCCESS);
}
*/

int	main(int argc, char **argv)
{
	t_ctx	*c[NUM_SORT_METHOD];

	c[0] = quicksort(argc, argv);
	c[1] = selectionsort(argc, argv);
	c[2] = insertsort(argc, argv);
	c[3] = _radixsort(argc, argv);
	if (c[0] == NULL || c[1] == NULL || c[2] == NULL || c[3] == NULL)
	{
		ctx_deinit_n(c, NUM_SORT_METHOD);
		err_exit("Error\n");
	}
	ft_debug_printf("[q: %d, s: %d, i: %d, r: %d]\n",
		n_op(c[0]), n_op(c[1]), n_op(c[2]), n_op(c[3]));
	ctx_print_best(c, NUM_SORT_METHOD);
	ctx_deinit_n(c, NUM_SORT_METHOD);
	return (EXIT_SUCCESS);
}
