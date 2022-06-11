/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_sort2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:05:21 by susami            #+#    #+#             */
/*   Updated: 2022/06/11 22:22:33 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#define SEL_THRESHOLD 50

static size_t	total_chunks(t_ctx *c)
{
	return (max(5, len_p(c) / SEL_THRESHOLD / 2 * 2 + 1));
}

static size_t	lower_bound(size_t chunk, t_ctx *c)
{
	return (len_p(c) * chunk / total_chunks(c));
}

static size_t	upper_bound(size_t chunk, t_ctx *c)
{
	return (len_p(c) * (chunk + 1) / total_chunks(c) - 1);
}

static BOOL	chunk_contains(size_t e, size_t chunk, t_ctx *c)
{
	size_t	lower_bound;
	size_t	upper_bound;

	lower_bound = len_p(c) * chunk / total_chunks(c);
	upper_bound = len_p(c) * (chunk + 1) / total_chunks(c) - 1;
	if (lower_bound <= e && e <= upper_bound)
		return (TRUE);
	else
		return (FALSE);
}

static void	create_chunk(t_ctx *c,
	size_t pb_chunk, size_t pbrb_chunk)
{
	size_t	i;

	ft_debug_printf("[partition_a2b(%d, %d)] start\n",
		pb_chunk, pbrb_chunk);
	i = 0;
	while (i < len_p(c))
	{
		if (chunk_contains(top_a(c), pb_chunk, c))
			pb(c);
		else if (chunk_contains(top_a(c), pbrb_chunk, c))
		{
			pb(c);
			rb(c);
		}
		else
			ra(c);
		i++;
	}
	ft_debug_printf("[partition_a2b(%d, %d)] end\n",
		pb_chunk, pbrb_chunk);
}

static void	partition(t_ctx *c)
{
	size_t	i;

	ft_debug_printf("[partitoin] start\n");
	i = 0;
	while (i < total_chunks(c) / 2)
	{
		create_chunk(c, total_chunks(c) / 2 - i,
			total_chunks(c) / 2 + 1 + i);
		debug_print_ctx(c);
		i++;
	}
	ft_debug_printf("[partition] end\n");
}

// b: 0 1 2
// 3 / 2 = 1
//
// b: 0 1 2 3
// 4 / 2 = 2
static t_op_function	nearest_b_op(size_t e, t_ctx *c)
{
	size_t	i;

	i = 0;
	while (i < len_b(c))
	{
		if (get_elm(i, c) == (t_elm)e)
			break ;
		i++;
	}
	if (i < len_b(c) / 2)
		return (rrb);
	else
		return (rb);
}

static void	selection(t_ctx *c, size_t chunk)
{
	size_t	i;
	size_t	low;
	size_t	high;

	ft_debug_printf("[selection(%d)] start\n", chunk);
	low = lower_bound(chunk, c);
	high = upper_bound(chunk, c);
	i = low;
	while (i <= high)
	{
		if (len_a(c) > 0 && top_a(c) == (t_elm)i)
		{
			ra(c);
			i++;
		}
		else if (len_b(c) > 0 && chunk_contains(top_b(c), chunk, c) == TRUE)
		{
			if (len_b(c) > 0 && top_b(c) == (t_elm)i)
				pa(c);
			else if (len_a(c) == 0)
				pa(c);
			else if (chunk_contains(top_a(c), chunk, c) == FALSE)
				pa(c);
			else if (top_b(c) < top_a(c))
				pa(c);
			else
				nearest_b_op(i, c)(c);
		}
		else
			rrb(c);
	}
	ft_debug_printf("[selection] end\n");
}

void	custom_sort2(t_ctx *c, size_t low, size_t high)
{
	size_t	chunk;

	if (len_p(c) <= 6)
	{
		small_sort(c);
		return ;
	}
	partition(c);
	while (len_a(c) > 0)
		pb(c);
	chunk = 0;
	while (chunk < total_chunks(c))
	{
		selection(c, chunk);
		chunk++;
	}
	if (low == 0 && high + 1 == len_p(c))
	{
		ft_debug_printf("post process\n");
		while (len_b(c) > 0)
			pa(c);
	}
}
