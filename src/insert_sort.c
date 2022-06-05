/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 00:47:16 by susami            #+#    #+#             */
/*   Updated: 2022/06/05 20:12:56 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_sort(t_ctx *c)
{
	size_t	i;
	size_t	min_i;

	while (len_a(c) > 0)
	{
		i = 0;
		min_i = 0;
		while (i < len_a(c))
		{
			if (c->a->arr[min_i] > c->a->arr[i])
				min_i = i;
			i++;
		}
		i = len_a(c) - 1;
		while (i > min_i)
		{
			ra(c);
			i--;
		}
		pb(c);
	}
	while (len_b(c) > 0)
		pa(c);
	opflush(c);
}
