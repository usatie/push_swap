/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:04:21 by susami            #+#    #+#             */
/*   Updated: 2022/06/05 20:12:36 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

size_t	max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

size_t	min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

size_t	len_p(t_ctx *c)
{
	return (c->a->len + c->b->len);
}

size_t	len_a(t_ctx *c)
{
	return (c->a->len - c->pb + c->pa);
}

size_t	len_b(t_ctx *c)
{
	return (c->b->len - c->pa + c->pb);
}

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
