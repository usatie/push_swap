/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 00:47:16 by susami            #+#    #+#             */
/*   Updated: 2022/06/03 14:00:54 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

void	insert_sort(t_stack_pair *p)
{
	size_t	i;
	size_t	min_i;

	while (p->a->len > 0)
	{
		i = 0;
		min_i = 0;
		while (i < p->a->len)
		{
			if (p->a->arr[min_i] > p->a->arr[i])
				min_i = i;
			i++;
		}
		i = p->a->len - 1;
		while (i > min_i)
		{
			ft_printf("ra\n");
			ra(p);
			i--;
		}
		ft_printf("pb\n");
		pb(p);
	}
	while (p->b->len > 0)
	{
		ft_printf("pa\n");
		pa(p);
	}
}
