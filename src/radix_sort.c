/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:37:33 by susami            #+#    #+#             */
/*   Updated: 2022/06/09 16:51:41 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_ctx *c)
{
	size_t	i;
	size_t	r;
	size_t	total;

	r = 0;
	total = 1;
	while (total < len_p(c))
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
		total *= 2;
	}
}
