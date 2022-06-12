/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 21:40:34 by susami            #+#    #+#             */
/*   Updated: 2022/06/12 15:28:59 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_debug.h"

#define SEL_THRESHOLD 30

static void	filter_a2b(t_ctx *c, size_t low, size_t high, t_elm partition)
{
	size_t	num_gt_partition;
	size_t	i;

	ft_debug_printf("[filter_a2b(%d, %d, %d)] start\n", low, high, partition);
	i = low;
	num_gt_partition = 0;
	while (i++ <= high)
	{
		if (top_a(c) > partition)
		{
			ra(c);
			num_gt_partition++;
		}
		else if (top_a(c) <= partition)
		{
			pb(c);
			if (top_b(c) == partition)
				rb(c);
		}
	}
	rrb(c);
	while (!(low == 0 && high == len_p(c) - 1) && num_gt_partition-- > 0)
		rra(c);
	ft_debug_printf("[filter_a2b(%d, %d, %d)] end\n", low, high, partition);
}

static size_t	partition(t_ctx *c, size_t low, size_t high)
{
	t_elm	partition;

	partition = (low + high) / 2;
	ft_debug_printf("[partition(%d, %d): partitoin=%d]\n", low, high, partition);
	ft_debug_printf("[partition b to a]\n");
	while (len_b(c) > 0)
		pa(c);
	while (top_a(c) < (t_elm)low)
		ra(c);
	filter_a2b(c, low, high, partition);
	debug_print_ctx(c);
	ft_debug_printf("[partition(%d, %d)] end\n", low, high);
	return (partition);
}

static void	selection(t_ctx *c, size_t low, size_t high)
{
	ft_debug_printf("[selection(%d, %d)] start\n", low, high);
	while (len_b(c) > 0)
		pa(c);
	while (top_a(c) < (t_elm)low)
		ra(c);
	while (low <= high)
	{
		if (top_a(c) == (t_elm)low)
		{
			ra(c);
			low++;
		}
		else if (stack_contains(low, c->b) && top_b(c) == (t_elm)low)
			pa(c);
		else if (stack_contains(low, c->b) && top_b(c) <= (t_elm)low + 2)
			pa(c);
		else if (stack_contains(low, c->b))
			rb(c);
		else
			pb(c);
	}
	ft_debug_printf("[selection] end\n");
}

void	custom_sort(t_ctx *c, size_t low, size_t high)
{
	size_t	pi;

	if (len_p(c) <= 6)
		small_sort(c);
	else if (high < low + SEL_THRESHOLD)
		selection(c, low, high);
	else if (high > low)
	{
		pi = partition(c, low, high);
		if (low + 1 < pi)
			custom_sort(c, low, pi - 1);
		custom_sort(c, pi + 1, high);
	}
	if (low == 0 && high + 1 == len_p(c))
	{
		ft_debug_printf("post process\n");
		while (len_b(c) > 0)
			pa(c);
		while (top_a(c) > 0)
			ra(c);
	}
}
