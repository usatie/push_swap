/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:54:45 by susami            #+#    #+#             */
/*   Updated: 2022/06/07 15:53:03 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

// a: [100,99,98,10] [5,9,4,7,8,6] [3,2,1] :b
// b: [1,2,3] [6,8,7,4,9,4] [10,98,99,100] :a

static void	filter_a2b(t_ctx *c, size_t high, t_elm partition)
{
	size_t	num_gt_partition;

	num_gt_partition = 0;
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
	while (num_gt_partition > 0)
	{
		rra(c);
		num_gt_partition--;
	}
}

static size_t	partition(t_ctx *c, size_t low, size_t high)
{
	t_elm	partition;

	partition = get_elm((low + high) / 2, c);
	ft_debug_printf("[partition(%d, %d): partitoin=%d]\n", low, high, partition);
	ft_debug_printf("[partition b to a]\n");
	while (len_b(c) > 0)
		pa(c);
	ft_debug_printf("[filter_a2b a to b]\n");
	filter_a2b(c, high, partition);
	print_ctx(c);
	return (len_b(c) - 1);
}

void	rule_sort(t_ctx *c, size_t low, size_t high)
{
	ft_debug_printf("[rule_sort(%d, %d)]\n", low, high);
	while (len_b(c) > 0)
		pa(c);
	if (high - low == 1)
	{
		while (len_b(c) < low)
			pb(c);
		if (get_elm(low, c) > get_elm(high, c))
			sa(c);
	}
	else if (high - low == 2)
	{
		// goal: 3, 2, 1
		while (len_b(c) < low)
			pb(c);
		// 1, 2, 3
		if (get_elm(low, c) > get_elm(low + 1, c) && get_elm(low + 1, c) > get_elm(high, c))
		{
			ra(c);
			ra(c);
			pb(c);
			rra(c);
			pb(c);
			rra(c);
		}
		// 1, 3, 2
		else if (get_elm(low + 1, c) > get_elm(low, c) && get_elm(low, c) > get_elm(high, c))
		{
			ra(c);
			sa(c);
			rra(c);
			sa(c);
		}
		// 2, 1, 3
		else if (get_elm(low, c) > get_elm(high, c) && get_elm(high, c) > get_elm(low + 1, c))
		{
			ra(c);
			pb(c);
			pb(c);
			rra(c);
		}
		// 2, 3, 1
		else if (get_elm(low + 1, c) > get_elm(high, c) && get_elm(high, c) > get_elm(low, c))
		{
			pb(c);
			sa(c);
		}
		// 3, 1, 2
		else if (get_elm(high, c) > get_elm(low, c) && get_elm(low, c) > get_elm(low + 1, c))
		{
			sa(c);
		}
	}
}

void	quick_sort(t_ctx *c, size_t low, size_t high)
{
	size_t	pi;

	ft_debug_printf("[quick_sort(%d, %d)]\n", low, high);
	if (low < high)
	{
		if (high - low <= 2)
			rule_sort(c, low, high);
		else
		{
			pi = partition(c, low, high);
			ft_debug_printf("[pi = %d]\n", pi);
			if (low + 1 < pi)
				quick_sort(c, low, pi - 1);
			quick_sort(c, pi + 1, high);
		}
		print_ctx(c);
	}
	if (low == 0 && high == len_p(c) - 1)
	{
		while (len_b(c) > 0)
			pa(c);
		opflush(c);
	}
}
