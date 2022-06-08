/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:54:45 by susami            #+#    #+#             */
/*   Updated: 2022/06/09 02:16:49 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

#define SEL_THRESH 30
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


static t_elm	get_partition(t_ctx *c, size_t low, size_t high)
{
	size_t	i;
	size_t	mi;
	size_t	n;
	t_elm	m;
	t_elm	last_m;
	n = 0;
	i = low;
	m = get_elm(i, c);
	last_m = get_elm(i, c);
	while (n < SEL_THRESH - 1 && i<= high)
	{
		while (i <= high)
		{
			if (m < get_elm(i, c) && m > last_m)
			{
				m = get_elm(i, c);
				mi = i;
			}
			i++;
		}
		last_m = m;
		n++;
	}
	return (last_m);
}

static size_t	partition(t_ctx *c, size_t low, size_t high)
{
	t_elm	partition;

	//partition = get_elm((low + high) / 2, c);
	partition = get_partition(c, low, high);
	ft_debug_printf("[partition(%d, %d): partitoin=%d]\n", low, high, partition);
	ft_debug_printf("[partition b to a]\n");
	while (len_b(c) > 0)
		pa(c);
	ft_debug_printf("[filter_a2b a to b]\n");
	filter_a2b(c, high, partition);
	debug_print_ctx(c);
	return (len_b(c) - 1);
}

void	rule_sort(t_ctx *c, size_t low, size_t high)
{
	ft_debug_printf("[rule_sort(%d, %d)]\n", low, high);
	while (len_b(c) > 0)
		pa(c);
	if (high - low == 1)
	{
		ft_debug_printf("[rule_sort: num sor = 2]\n", low, high);
		while (len_b(c) < low)
			pb(c);
		if (get_elm(low, c) > get_elm(high, c))
			sa(c);
	}
	else if (low >= len_p(c) - 3)
	{
		ft_debug_printf("a: [rule_sort: num sor = 2]\n", low, high);
		while (len_a(c) > 3)
			pb(c);
		while (len_a(c) < 3)
			pa(c);
		t_elm l, m, r;
		l = get_elm(len_p(c) - 1, c);
		m = get_elm(len_p(c) - 2, c);
		r = get_elm(len_p(c) - 3, c);
		// a: 1, 2, 3 -> sa rra
		// a: 1, 3, 2 -> rra
		// a: 2, 3, 1 -> sa rb
		// a: 2, 1, 3 -> ra
		// a: 3, 1, 2 -> sa
		// a: 3, 2, 1 -> 
		if (l < m && m < r)
		{
			sa(c);
			rra(c);
		}
		else if (l < r && r < m)
		{
			rra(c);
		}
		else if (r < l && l < m)
		{
			sa(c);
			ra(c);
		}
		else if (m < l && l < r)
		{
			ra(c);
		}
		else if (m < r && r < l)
		{
			sa(c);
		}
		else if (r < m && m < l)
		{
		}
	}
	else if (high < 3)
	{
		ft_debug_printf("b: [rule_sort: num sor = 2]\n", low, high);
		while (len_b(c) > 3)
			pa(c);
		while (len_b(c) < 3)
			pb(c);
		t_elm l, m, r;
		l = get_elm(2, c);
		m = get_elm(1, c);
		r = get_elm(0, c);
		// 1, 2, 3: b -> sb rrb
		// 1, 3, 2: b -> rb
		// 2, 3, 1: b -> sb
		// 2, 1, 3: b -> rrb
		// 3, 1, 2: b -> sb rb
		// 3, 2, 1: b -> 
		if (l < m && m < r)
		{
			sb(c);
			rrb(c);
		}
		else if (l < r && r < m)
		{
			rb(c);
		}
		else if (r < l && l < m)
		{
			sb(c);
		}
		else if (m < l && l < r)
		{
			rrb(c);
		}
		else if (m < r && r < l)
		{
			sb(c);
			rb(c);
		}
		else if (r < m && m < l)
		{
		}
	}
}

static void	mini_selection_sort(t_ctx *c, size_t low, size_t high)
{
	size_t	i;
	size_t	mi;
	t_elm	m;

	while (low <= high)
	{
		i = low;
		mi = low;
		m = get_elm(i, c);
		while (i <= high)
		{
			ft_debug_printf("[mini(%d, %d), i: %d, min: %d, mi: %d]\n", low, high, i, m, mi);
			if (get_elm(i, c) < m)
			{
				m = get_elm(i, c);
				mi = i;
			}
			i++;
		}
		ft_debug_printf("[mini(%d, %d), min: %d, mi: %d]\n", low, high, m, mi);
		while (len_b(c) > low)
			pa(c);
		while (len_b(c) < low)
			pb(c);
		i = low;
		while (i < mi)
		{
			ra(c);
			i++;
		}
		pb(c);
		while (i > low)
		{
			rra(c);
			i--;
		}
		low++;
	}

}

void	quick_sort(t_ctx *c, size_t low, size_t high)
{
	size_t	pi;

	ft_debug_printf("[quick_sort(%d, %d)]\n", low, high);
	if (low < high)
	{
		if (high - low == 1)
			rule_sort(c, low, high);
		else if (high < 3 || len_p(c) - 3 < low)
			rule_sort(c, low, high);
		else if (high - low < SEL_THRESH)
			mini_selection_sort(c, low, high);
		else
		{
			pi = partition(c, low, high);
			ft_debug_printf("[pi = %d]\n", pi);
			if (low + 1 < pi)
				quick_sort(c, low, pi - 1);
			quick_sort(c, pi + 1, high);
		}
		debug_print_ctx(c);
	}
	if (low == 0 && high == len_p(c) - 1)
	{
		while (len_b(c) > 0)
			pa(c);
		opflush(c);
	}
}
