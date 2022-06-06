/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:54:45 by susami            #+#    #+#             */
/*   Updated: 2022/06/06 18:35:32 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

// a: [100,99,98,10] [5,9,4,7,8,6] [3,2,1] :b
// b: [1,2,3] [6,8,7,4,9,4] [10,98,99,100] :a

static size_t	partition(t_ctx *c, size_t low, size_t high)
{
	size_t	pi;
	size_t	num_rb;
	size_t	num_ra;
	t_elm	partition;

	num_ra = 0;
	num_rb = 0;
	pi = (low + high) / 2;
	partition = get_elm(pi, c);
	ft_debug_printf("[partition(%d, %d): pi=%d, partitoin=%d]\n",
		low, high, pi, partition);
	ft_debug_printf("[partition b to a]\n");
	while (len_a(c) > 0)
		pb(c);
	while (len_b(c) - num_rb > low)
	{
		if (top_b(c) < partition)
		{
			rb(c);
			num_rb++;
		}
		else if (top_b(c) > partition)
			pa(c);
		else if (top_b(c) == partition)
		{
			pa(c);
			ra(c);
		}
	}
	ft_debug_printf("[partition reverse a(num_ra = %d)]\n", num_ra);
	rra(c);
	ft_debug_printf("[partition reverse b(num_rb = %d)]\n", num_rb);
	while (num_rb > 0)
	{
		rrb(c);
		num_rb--;
	}
	pi = len_b(c);
	print_ctx(c);
	ft_debug_printf("[partition pi = %d]\n", pi);
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
