/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:54:45 by susami            #+#    #+#             */
/*   Updated: 2022/06/05 22:41:07 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

// a: [100,99,98,10] [5,9,4,7,8,6] [3,2,1] :b
// b: [1,2,3] [6,8,7,4,9,4] [10,98,99,100] :a

static size_t	partition(t_ctx *c, size_t low, size_t high)
{
	size_t	i;
	size_t	pi;
	size_t	num_rb;
	size_t	num_ra;
	t_elm	partition;

	num_ra = 0;
	num_rb = 0;
	pi = 0;
	i = (low + high) / 2;
	partition = get_elm(i, c);
	if (VERBOSE)
		ft_printf("[partition(%d, %d): i=%d, partitoin=%d]\n", low, high, i, partition);
	if (VERBOSE)
		ft_printf("[partition b to a]\n");
	while (len_b(c) - num_rb > low)
	{
		if (top_b(c) < partition)
		{
			rb(c);
			num_rb++;
		}
		else if (top_b(c) > partition)
		{
			pa(c);
			// [10,9,8][7,6,5,4][3,2,1]
			if (len_a(c) > num_ra + (len_p(c) - 1 - high))
			{
				ra(c);
				num_ra++;
			}
		}
		else if (top_b(c) == partition)
			pa(c);
	}
	if (VERBOSE)
		ft_printf("[partition a to b]\n");
	while (len_a(c) - num_ra > len_p(c) - 1 - high)
	{
		if (top_a(c) < partition)
		{
			pb(c);
			if (len_b(c) > num_rb + low)
			{
				rb(c);
				num_rb++;
			}
		}
		else if (top_a(c) > partition)
		{
			ra(c);
			num_ra++;
		}
		else if (top_a(c) == partition)
			pb(c);
	}
	if (VERBOSE)
		ft_printf("[partition reverse a(num_ra = %d)]\n", num_ra);
	while (num_ra > 0)
	{
		if (VERBOSE)
			ft_printf("[top a=%d]\n", top_a(c));
		if (top_a(c) == partition)
			pb(c);
		rra(c);
		num_ra--;
	}
	if (VERBOSE)
		ft_printf("[partition reverse b(num_rb = %d)]\n", num_rb);
	while (num_rb > 0)
	{
		if (VERBOSE)
			ft_printf("[top b=%d]\n", top_b(c));
		if (top_b(c) == partition)
			pa(c);
		else
		{
			rrb(c);
			num_rb--;
		}
	}
	if (top_b(c) == partition)
		pa(c);
	pi = len_b(c);
	print_ctx(c);
	if (VERBOSE)
		ft_printf("[partition pi = %d]\n", pi);
	return (pi);
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

