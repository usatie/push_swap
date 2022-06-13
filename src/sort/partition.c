/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:04:19 by susami            #+#    #+#             */
/*   Updated: 2022/06/13 17:03:51 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_debug.h"
#include "push_swap.h"

#define SEL_THRESHOLD 40
#define SIZE_BASE 100
#define SIZE_EXTRA 150

size_t	part_total(t_ctx *c)
{
	return (max(5, len_p(c) / SEL_THRESHOLD / 2 * 2 + 1));
}

size_t	lower_bound(size_t partition, t_ctx *c)
{
	size_t	i;
	size_t	n_phase;
	size_t	sum;
	size_t	sum_lower;

	n_phase = part_total(c) / 2;
	sum = 0;
	sum_lower = 0;
	i = 0;
	while (i < part_total(c))
	{
		if (i <= n_phase)
			sum += SIZE_BASE
				+ SIZE_EXTRA * i / n_phase;
		else
			sum += SIZE_BASE
				+ SIZE_EXTRA * (part_total(c) - i - 1) / n_phase;
		if (i < partition)
			sum_lower = sum;
		i++;
	}
	return (len_p(c) * sum_lower / sum);
}

size_t	upper_bound(size_t partition, t_ctx *c)
{
	return (lower_bound(partition + 1, c) - 1);
}

BOOL	part_contains(size_t e, size_t partition, t_ctx *c)
{
	if (lower_bound(partition, c) <= e && e <= upper_bound(partition, c))
		return (TRUE);
	else
		return (FALSE);
}

void	part_a2b(t_ctx *c, size_t part_pb, size_t part_pbrb)
{
	size_t	i;

	ft_debug_printf("[part_a2b(%d, %d)] start\n",
		part_pb, part_pbrb);
	ft_debug_printf("[partition(%d) lower = %d, upper = %d]\n",
		part_pb, lower_bound(part_pb, c), upper_bound(part_pb, c));
	ft_debug_printf("[partition(%d) lower = %d, upper = %d]\n",
		part_pbrb, lower_bound(part_pbrb, c), upper_bound(part_pbrb, c));
	i = 0;
	while (i < len_p(c))
	{
		if (part_contains(top_a(c), part_pb, c))
			pb(c);
		else if (part_contains(top_a(c), part_pbrb, c))
		{
			pb(c);
			rb(c);
		}
		else
			ra(c);
		i++;
	}
	ft_debug_printf("[part_a2b(%d, %d)] end\n",
		part_pb, part_pbrb);
}
