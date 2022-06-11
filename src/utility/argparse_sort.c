/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparse_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:11:08 by susami            #+#    #+#             */
/*   Updated: 2022/06/11 15:06:41 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_error_functions.h"
#include "push_swap.h"

// returns result context for quick sort
t_ctx	*quicksort(int argc, char **argv)
{
	t_ctx	*c;

	c = argparse_ctx(argc, argv);
	if (c == NULL)
		return (NULL);
	ft_debug_printf("\n=====[QUICK SORT]=====\n");
	debug_print_ctx(c);
	ft_debug_printf("========================\n\n");
	if (argc >= 2)
		quick_sort(c, 0, argc - 2);
	ft_debug_printf("\n=====[QUICK SORT] (result=%d)=====\n\n", opsize(c));
	debug_print_ctx(c);
	c = optimize(argc, argv, c);
	return (c);
}

// returns result context for selection sort
t_ctx	*selectionsort(int argc, char **argv)
{
	t_ctx	*c;

	c = argparse_ctx(argc, argv);
	if (c == NULL)
		return (NULL);
	ft_debug_printf("\n=====[SELECTION SORT]=====\n");
	debug_print_ctx(c);
	ft_debug_printf("========================\n\n");
	if (argc >= 2)
		selection_sort(c);
	ft_debug_printf("\n=====[SELECTION SORT] (result=%d)=====\n\n", opsize(c));
	debug_print_ctx(c);
	c = optimize(argc, argv, c);
	return (c);
}

// returns result context for insert sort
t_ctx	*insertsort(int argc, char **argv)
{
	t_ctx	*c;

	c = argparse_ctx(argc, argv);
	if (c == NULL)
		return (NULL);
	ft_debug_printf("\n=====[INSERT SORT] =====\n");
	debug_print_ctx(c);
	ft_debug_printf("========================\n\n");
	if (argc >= 2)
		insert_sort(c);
	ft_debug_printf("\n=====[INSERT SORT] (result=%d)=====\n\n", opsize(c));
	debug_print_ctx(c);
	c = optimize(argc, argv, c);
	return (c);
}

// returns result context for radix sort
t_ctx	*_radixsort(int argc, char **argv)
{
	t_ctx	*c;

	c = argparse_ctx(argc, argv);
	if (c == NULL)
		return (NULL);
	ft_debug_printf("\n=====[RADIX SORT]=====\n");
	debug_print_ctx(c);
	ft_debug_printf("========================\n\n");
	if (argc >= 2)
		radix_sort(c);
	ft_debug_printf("\n=====[RADIX SORT] (result=%d)=====\n\n", opsize(c));
	debug_print_ctx(c);
	c = optimize(argc, argv, c);
	return (c);
}

t_ctx	*customsort(int argc, char **argv)
{
	t_ctx	*c;

	c = argparse_ctx(argc, argv);
	if (c == NULL)
		return (NULL);
	ft_debug_printf("\n=====[CUSTOM SORT]=====\n");
	debug_print_ctx(c);
	ft_debug_printf("========================\n\n");
	if (argc >= 2)
		custom_sort2(c, 0, argc - 2);
	ft_debug_printf("\n=====[CUSTOM SORT] (result=%d)=====\n\n", opsize(c));
	debug_print_ctx(c);
	c = optimize(argc, argv, c);
	return (c);
}
