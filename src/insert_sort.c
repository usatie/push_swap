/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 00:47:16 by susami            #+#    #+#             */
/*   Updated: 2022/06/03 19:05:57 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_sort(t_stack_pair *p)
{
	size_t	i;
	size_t	min_i;

	while (len_a(p) > 0)
	{
		i = 0;
		min_i = 0;
		while (i < len_a(p))
		{
			if (p->a->arr[min_i] > p->a->arr[i])
				min_i = i;
			i++;
		}
		i = len_a(p) - 1;
		while (i > min_i)
		{
			ra(p);
			i--;
		}
		pb(p);
	}
	while (len_b(p) > 0)
		pa(p);
	opflush(p);
}
