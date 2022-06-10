/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_minmax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:11:26 by susami            #+#    #+#             */
/*   Updated: 2022/06/10 21:14:06 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elm	min_a(t_ctx *c)
{
	t_elm	min;
	size_t	i;

	min = c->a->arr[0];
	i = 0;
	while (++i < c->a->len)
		if (min > c->a->arr[i])
			min = c->a->arr[i];
	return (min);
}

t_elm	max_a(t_ctx *c)
{
	t_elm	max;
	size_t	i;

	max = c->a->arr[0];
	i = 0;
	while (++i < c->a->len)
		if (max < c->a->arr[i])
			max = c->a->arr[i];
	return (max);
}

t_elm	min_b(t_ctx *c)
{
	t_elm	min;
	size_t	i;

	min = c->b->arr[0];
	i = 0;
	while (++i < c->b->len)
		if (min > c->b->arr[i])
			min = c->b->arr[i];
	return (min);
}

t_elm	max_b(t_ctx *c)
{
	t_elm	max;
	size_t	i;

	max = c->b->arr[0];
	i = 0;
	while (++i < c->b->len)
		if (max < c->b->arr[i])
			max = c->b->arr[i];
	return (max);
}
/*
t_elm	min_b(t_ctx *c)
{
	size_t	i;
	t_elm	m;

	if (len_b(c) == 1)
		return (get_elm(0, c));
	m = get_elm(0, c);
	i = 1;
	while (i < len_b(c))
	{
		if (get_elm(i, c) < m)
			m = get_elm(i, c);
		i++;
	}
	return (m);
}

t_elm	max_b(t_ctx *c)
{
	size_t	i;
	t_elm	m;

	if (len_b(c) == 1)
		return (get_elm(0, c));
	m = get_elm(0, c);
	i = 1;
	while (i < len_b(c))
	{
		if (get_elm(i, c) > m)
			m = get_elm(i, c);
		i++;
	}
	return (m);
}
*/
