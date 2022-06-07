/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:54:45 by susami            #+#    #+#             */
/*   Updated: 2022/06/07 14:53:34 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

// a: [100,99,98,10] [5,9,4,7,8,6] [3,2,1] :b
// b: [1,2,3] [6,8,7,4,9,4] [10,98,99,100] :a

static size_t	partition(t_ctx *c, size_t low, size_t high)
{
	size_t	num_gt_partition;
	t_elm	partition;

	num_gt_partition = 0;
	partition = get_elm((low + high) / 2, c);
	ft_debug_printf("[partition(%d, %d): partitoin=%d]\n", low, high, partition);
	ft_debug_printf("[partition b to a]\n");
	while (len_b(c) > 0)
		pa(c);
	ft_debug_printf("[partition a to b]\n");
	while (len_a(c) - num_gt_partition > len_p(c) - 1 - high)
	{
		if (top_a(c) > partition)
		{
			ra(c);
			num_gt_partition++;
		}
		else if (top_a(c) < partition)
			pb(c);
		else if (top_a(c) == partition)
		{
			pb(c);
			rb(c);
		}
	}
	rrb(c);
	ft_debug_printf("[partition reverse a(%d)]\n", num_gt_partition);
	while (num_gt_partition > 0)
	{
		rra(c);
		num_gt_partition--;
	}
	print_ctx(c);
	return (len_b(c) - 1);
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
