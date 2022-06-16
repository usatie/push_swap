/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:37:33 by susami            #+#    #+#             */
/*   Updated: 2022/06/16 19:46:43 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_debug.h"
#include "push_swap.h"

void	radix_sort(t_ctx *c)
{
	size_t	i;
	size_t	r;
	size_t	pow;

	r = 0;
	pow = 1;
	while (pow < len_p(c))
	{
		i = 0;
		while (i < len_p(c))
		{
			if ((top_a(c) >> r) & 1)
				ra(c);
			else
				pb(c);
			i++;
		}
		while (len_b(c) > 0)
			pa(c);
		r++;
		pow *= 2;
	}
}

static void	radix3_partition(size_t pow, t_ctx *c)
{
	size_t	i;
	size_t	r;

	i = 0;
	while (i++ < len_p(c))
	{
		r = (top_a(c) / pow) % 3;
		if (r == 2)
			ra(c);
		else if (r == 1)
			pb(c);
		else
		{
			pb(c);
			rb(c);
		}
	}
	while (len_b(c) > 0)
	{
		r = ((top_b(c) / pow) % 3);
		if (r == 0)
			rrb(c);
		pa(c);
	}
}

void	radix3_sort(t_ctx *c)
{
	size_t	pow;

	pow = 1;
	while (pow < len_p(c))
	{
		radix3_partition(pow, c);
		pow *= 3;
	}
}

static void	radix3_partition_rev(size_t pow, t_ctx *c)
{
	size_t	i;
	size_t	r;

	i = 0;
	while (i++ < len_p(c))
	{
		r = (top_a(c) / pow) % 3;
		if (r == 0)
			ra(c);
		else if (r == 1)
			pb(c);
		else
		{
			pb(c);
			rb(c);
		}
	}
	while (len_b(c) > 0)
	{
		r = ((top_b(c) / pow) % 3);
		if (r == 2)
			rrb(c);
		pa(c);
	}
}

void	radix3_sort_rev(t_ctx *c)
{
	size_t	pow;

	pow = 1;
	while (pow < len_p(c))
	{
		radix3_partition_rev(pow, c);
		pow *= 3;
	}
}
