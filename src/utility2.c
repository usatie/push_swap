/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 23:31:49 by susami            #+#    #+#             */
/*   Updated: 2022/06/05 23:32:13 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pa/pb buffering: doesn't matter
// sa/sb buffering: swap (len-1) and (len-2)
// ra/rra/rb/rrb buffering: (i + r - rr) % len
//

t_elm	top_a(t_ctx *c)
{
	return (get_elm(c->b->len - 1 + c->pb - c->pa + 1, c));
}

t_elm	top_b(t_ctx *c)
{
	return (get_elm(c->b->len - 1 + c->pb - c->pa, c));
}

t_elm	get_elm(size_t i, t_ctx *c)
{
	t_elm	*arr;

	if (i < c->b->len)
	{
		if (c->sb && i == c->b->len - 1)
			i = c->b->len - 2;
		else if (c->sb && i == c->b->len - 2)
			i = c->b->len - 1;
		i = (i - c->rb + c->rrb) % c->b->len;
		arr = c->b->arr;
	}
	else
	{
		i = (c->a->len - 1) - (i - c->b->len);
		if (c->sa > 0 && i == c->a->len - 1)
			i = c->a->len - 2;
		else if (c->sa > 0 && i == c->a->len - 2)
			i = c->a->len - 1;
		i = (i - c->ra + c->rra) % c->a->len;
		arr = c->a->arr;
	}
	return (arr[i]);
}
