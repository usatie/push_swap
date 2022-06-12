/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:04:19 by susami            #+#    #+#             */
/*   Updated: 2022/06/12 16:16:39 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_debug.h"
#include "push_swap.h"

#define SEL_THRESHOLD 50

size_t	partition_total(t_ctx *c)
{
	return (max(5, len_p(c) / SEL_THRESHOLD / 2 * 2 + 1));
}

size_t	lower_bound(size_t partition, t_ctx *c)
{
	return (len_p(c) * partition / partition_total(c));
}

size_t	upper_bound(size_t partition, t_ctx *c)
{
	return (len_p(c) * (partition + 1) / partition_total(c) - 1);
}

BOOL	partition_contains(size_t e, size_t partition, t_ctx *c)
{
	if (lower_bound(partition, c) <= e && e <= upper_bound(partition, c))
		return (TRUE);
	else
		return (FALSE);
}

void	create_partition(t_ctx *c,
	size_t pb_partition, size_t pbrb_partition)
{
	size_t	i;

	ft_debug_printf("[partition_a2b(%d, %d)] start\n",
		pb_partition, pbrb_partition);
	i = 0;
	while (i < len_p(c))
	{
		if (partition_contains(top_a(c), pb_partition, c))
			pb(c);
		else if (partition_contains(top_a(c), pbrb_partition, c))
		{
			pb(c);
			rb(c);
		}
		else
			ra(c);
		i++;
	}
	ft_debug_printf("[partition_a2b(%d, %d)] end\n",
		pb_partition, pbrb_partition);
}
