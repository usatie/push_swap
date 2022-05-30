/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 00:47:16 by susami            #+#    #+#             */
/*   Updated: 2022/05/31 01:18:04 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

void	insert_sort(t_stack *a, t_stack *b)
{
	size_t	i;
	size_t	min_i;

	while (a->len > 0)
	{
		i = 0;
		min_i = 0;
		while (i < a->len)
		{
			if (a->arr[min_i] > a->arr[i])
				min_i = i;
			i++;
		}
		i = a->len - 1;
		while (i > min_i)
		{
			ft_printf("ra\n");
			ra(a, b);
			i--;
		}
		ft_printf("pb\n");
		pb(a, b);
	}
	while (b->len > 0)
	{
		ft_printf("pa\n");
		pa(a, b);
	}
}
