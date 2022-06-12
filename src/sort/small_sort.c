/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:41:51 by susami            #+#    #+#             */
/*   Updated: 2022/06/12 15:29:12 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_debug.h"
#include "push_swap.h"

static void	small_sort_2(t_ctx *c)
{
	if (get_elm(0, c) > get_elm(1, c))
		sa(c);
}

static void	small_sort_3(t_ctx *c)
{
	ft_debug_printf("small_sort_3\n");
	if (top_a(c) == max_a(c))
	{
		ra(c);
		if (top_a(c) != min_a(c))
			sa(c);
	}
	else if (top_a(c) == min_a(c))
	{
		if (get_elm(len_p(c) - 1, c) != max_a(c))
		{
			rra(c);
			sa(c);
		}
	}
	else
	{
		if (get_elm(len_p(c) - 2, c) == max_a(c))
			rra(c);
		else
			sa(c);
	}
}

void	small_sort(t_ctx *c)
{
	if (len_p(c) < 2)
		return ;
	else if (len_p(c) == 2)
		small_sort_2(c);
	else if (len_p(c) == 3)
		small_sort_3(c);
	else
	{
		ft_debug_printf("more than 3\n");
		while (len_a(c) > 3)
		{
			if (top_a(c) == min_a(c))
				pb(c);
			else
				ra(c);
		}
		small_sort_3(c);
		ft_debug_printf("last pa 3\n");
		while (len_b(c) > 0)
			pa(c);
	}
}
