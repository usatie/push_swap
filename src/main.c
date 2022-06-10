/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:43:10 by susami            #+#    #+#             */
/*   Updated: 2022/06/10 17:14:00 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "ft_error_functions.h"
#include "push_swap.h"

#define NUM_SORT_METHOD 4

int	main(int argc, char **argv)
{
	t_ctx	*c[NUM_SORT_METHOD];

	(void)customsort;
	c[0] = quicksort(argc, argv);
	c[1] = selectionsort(argc, argv);
	c[2] = insertsort(argc, argv);
	c[3] = _radixsort(argc, argv);
	if (c[0] == NULL || c[1] == NULL || c[2] == NULL || c[3] == NULL)
	{
		ctx_deinit_all(c, NUM_SORT_METHOD);
		err_exit("Error\n");
	}
	ft_debug_printf("[q: %d, s: %d, i: %d, r: %d]\n",
		n_op(c[0]), n_op(c[1]), n_op(c[2]), n_op(c[3]));
	ctx_print_best(c, NUM_SORT_METHOD);
	ctx_deinit_all(c, NUM_SORT_METHOD);
	return (EXIT_SUCCESS);
}

/*
int	main(int argc, char **argv)
{
	t_ctx	*c;

	(void)selectionsort;
	(void)insertsort;
	(void)quicksort;
	(void)_radixsort;
	(void)customsort;
	c = customsort(argc, argv);
	//c = quicksort(argc, argv);
	if (c == NULL)
		return (EXIT_FAILURE);
	print_ops(c);
	ctx_deinit(c);
	return (EXIT_SUCCESS);
}

static void	destructor(void) __attribute__((destructor));

static void	destructor(void)
{
	system("leaks -q push_swap");
}
*/
