/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:31:01 by susami            #+#    #+#             */
/*   Updated: 2022/06/10 16:56:52 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elm	top_a(t_ctx *c)
{
	return (get_elm(len_b(c), c));
}

t_elm	top_b(t_ctx *c)
{
	return (get_elm(len_b(c) - 1, c));
}

t_elm	get_elm(size_t i, t_ctx *c)
{
	t_elm	*arr;

	if (i < c->b->len)
		arr = c->b->arr;
	else
	{
		i = len_p(c) - 1 - i;
		arr = c->a->arr;
	}
	return (arr[i]);
}

size_t	n_op(t_ctx *c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (i < c->ops->len)
	{
		if (c->ops->arr[i] > 0)
			n++;
		i++;
	}
	return (n);
}
