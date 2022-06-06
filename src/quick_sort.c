/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:54:45 by susami            #+#    #+#             */
/*   Updated: 2022/06/06 21:34:39 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

// a: [100,99,98,10] [5,9,4,7,8,6] [3,2,1] :b
// b: [1,2,3] [6,8,7,4,9,4] [10,98,99,100] :a

static size_t	partition(t_ctx *c, size_t low, size_t high)
{
	size_t	num_lt_partition;
	t_elm	partition;

	num_lt_partition = 0;
	partition = get_elm((low + high) / 2, c);
	ft_debug_printf("[partition(%d, %d): partitoin=%d]\n", low, high, partition);
	ft_debug_printf("[partition a to b]\n");
	while (len_a(c) > 0)
		pb(c);
	ft_debug_printf("[partition b to a]\n");
	while (len_b(c) - num_lt_partition > low)
	{
		if (top_b(c) < partition)
		{
			rb(c);
			num_lt_partition++;
		}
		else if (top_b(c) > partition)
			pa(c);
		else if (top_b(c) == partition)
		{
			pa(c);
			ra(c);
		}
	}
	rra(c);
	ft_debug_printf("[partition reverse b(%d)]\n", num_lt_partition);
	while (num_lt_partition > 0)
	{
		rrb(c);
		num_lt_partition--;
	}
	print_ctx(c);
	return (len_b(c));
}

void	quick_sort(t_ctx *c, size_t low, size_t high)
{
	size_t	pi;

	if (low < high)
	{
		pi = partition(c, low, high);
		if (low + 1 < pi)
			quick_sort(c, low, pi - 1);
		if (pi + 1 < high)
			quick_sort(c, pi + 1, high);
		print_ctx(c);
	}
	if (low == 0 && high == len_p(c) - 1)
	{
		while (len_b(c) > 0)
			pa(c);
		opflush(c);
	}
}
