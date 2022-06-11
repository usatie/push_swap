/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_sort2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:05:21 by susami            #+#    #+#             */
/*   Updated: 2022/06/11 17:05:57 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#define SEL_THRESHOLD 30

static size_t	total_chunks(t_ctx *c)
{
	return (len_p(c) / SEL_THRESHOLD / 2 * 2 + 1);
}

static BOOL	chunk_contains(size_t e, size_t chunk, t_ctx *c)
{
	size_t	lower_border;
	size_t	upper_border;

	lower_border = len_p(c) * chunk / total_chunks(c);
	upper_border = len_p(c) * (chunk + 1) / total_chunks(c) - 1;
	if (lower_border <= e && e <= upper_border)
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

void	custom_sort2(t_ctx *c, size_t low, size_t high)
{
	if (high > low)
	{
		partition(c);
	}
	if (low == 0 && high + 1 == len_p(c))
	{
		ft_debug_printf("post process\n");
		while (len_b(c) > 0)
			pa(c);
	}
}
