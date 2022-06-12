/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_sort2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:05:21 by susami            #+#    #+#             */
/*   Updated: 2022/06/12 16:59:05 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_debug.h"

static void	partition(t_ctx *c)
{
	size_t	i;

	ft_debug_printf("[partitoin] start\n");
	i = 0;
	while (i < partition_total(c) / 2)
	{
		create_partition(c, partition_total(c) / 2 - i,
			partition_total(c) / 2 + 1 + i);
		debug_print_ctx(c);
		i++;
	}
	ft_debug_printf("[partition] end\n");
}

static void	selection(t_ctx *c, size_t partition)
{
	size_t	i;
	size_t	high;

	ft_debug_printf("[selection(%d)] start\n", partition);
	high = upper_bound(partition, c);
	i = lower_bound(partition, c);
	while (i <= high)
	{
		if (len_a(c) > 0 && top_a(c) == (t_elm)i)
		{
			ra(c);
			i++;
		}
		else if (len_a(c) > 1 && get_elm(len_b(c) + 1, c) >= (t_elm)i && top_a(c) > get_elm(len_b(c) + 1, c))
			sa(c);
		else if (len_b(c) > 0 && partition_contains(top_b(c), partition, c) == TRUE)
		{
			if (len_b(c) > 0 && top_b(c) == (t_elm)i)
				pa(c);
			else if (len_a(c) < 2)
				pa(c);
			else if (partition_contains(top_a(c), partition, c) == FALSE)
				pa(c);
			else if (partition_contains(get_elm(len_b(c) + 1, c), partition, c) == FALSE)
				pa(c);
			else if (top_b(c) < top_a(c))
				pa(c);
			else if (top_b(c) < get_elm(len_b(c) + 1, c))
				pa(c);
			else if (get_index(i, c) < len_b(c) / 2)
				rrb(c);
			else
				rb(c);
		}
		else
			rrb(c);
	}
	ft_debug_printf("[selection] end\n");
}

void	custom_sort2(t_ctx *c)
{
	size_t	i;

	if (len_p(c) <= 6)
	{
		small_sort(c);
		return ;
	}
	partition(c);
	while (len_a(c) > 0)
		pb(c);
	i = 0;
	while (i < partition_total(c))
	{
		selection(c, i);
		i++;
	}
}
