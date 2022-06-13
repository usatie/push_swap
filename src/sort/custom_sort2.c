/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_sort2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:05:21 by susami            #+#    #+#             */
/*   Updated: 2022/06/13 17:03:16 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_debug.h"

static void	partition(t_ctx *c)
{
	size_t	i;

	ft_debug_printf("[partitoin] start\n");
	i = 0;
	while (i < part_total(c) / 2)
	{
		part_a2b(c, part_total(c) / 2 - i,
			part_total(c) / 2 + 1 + i);
		debug_print_ctx(c);
		i++;
	}
	while (len_a(c) > 0)
		pb(c);
	ft_debug_printf("[partition] end\n");
}

// Returns true if ra(means sorted)
static BOOL	selectionsort_op(size_t i, size_t partition, t_ctx *c)
{
	if (len_a(c) > 0 && top_a(c) == (t_elm)i)
	{
		ra(c);
		return (TRUE);
	}
	else if (len_a(c) > 1 && top_a2(c) >= (t_elm)i && top_a(c) > top_a2(c))
		sa(c);
	else if (part_contains(top_b(c), partition, c) == TRUE)
	{
		if ((top_b(c) == (t_elm)i) || (len_a(c) < 2)
			|| (part_contains(top_a(c), partition, c) == FALSE)
			|| (part_contains(top_a2(c), partition, c) == FALSE)
			|| (top_b(c) < top_a(c))
			|| (top_b(c) < top_a2(c)))
			pa(c);
		else if (get_index(i, c) < len_b(c) / 2)
			rrb(c);
		else
			rb(c);
	}
	else if (get_index(i, c) < len_b(c) / 2)
		rrb(c);
	else
		rb(c);
	return (FALSE);
}

static void	selectionsort_part(t_ctx *c, size_t partition)
{
	size_t	i;

	ft_debug_printf("[selectionsort_part(%d)] start\n", partition);
	i = lower_bound(partition, c);
	while (i <= upper_bound(partition, c))
	{
		if (selectionsort_op(i, partition, c))
			i++;
	}
	ft_debug_printf("[selectionsort_part] end\n");
}

void	custom_sort2(t_ctx *c)
{
	size_t	i;

	if (len_p(c) <= 6)
		small_sort(c);
	else
	{
		partition(c);
		i = 0;
		while (i < part_total(c))
			selectionsort_part(c, i++);
	}
}
