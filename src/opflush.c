/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opflush.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:00:43 by susami            #+#    #+#             */
/*   Updated: 2022/06/08 16:47:28 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

void	opflush(t_ctx *c)
{
	opflush_r(c);
	opflush_rr(c);
	opflush_p(c);
	opflush_s(c);
}

// pa and pb
void	opflush_p(t_ctx *c)
{
	while (c->pa > 0)
	{
		push(c->a, pop(c->b));
		c->pa--;
		ctx_append(OP_PA, c);
	}
	while (c->pb > 0)
	{
		push(c->b, pop(c->a));
		c->pb--;
		ctx_append(OP_PB, c);
	}
}

// ra and rb and rr
void	opflush_r(t_ctx *c)
{
	while (c->ra > 0 && c->rb > 0)
	{
		rotate(c->a);
		rotate(c->b);
		c->ra--;
		c->rb--;
		ctx_append(OP_RR, c);
	}
	while (c->ra > 0)
	{
		rotate(c->a);
		c->ra--;
		ctx_append(OP_RA, c);
	}
	while (c->rb > 0)
	{
		rotate(c->b);
		c->rb--;
		ctx_append(OP_RB, c);
	}
}

// rra and rrb and rrr
void	opflush_rr(t_ctx *c)
{
	while (c->rra > 0 && c->rrb > 0)
	{
		reverse_rotate(c->a);
		reverse_rotate(c->b);
		c->rra--;
		c->rrb--;
		ctx_append(OP_RRR, c);
	}
	while (c->rra > 0)
	{
		reverse_rotate(c->a);
		c->rra--;
		ctx_append(OP_RRA, c);
	}
	while (c->rrb > 0)
	{
		reverse_rotate(c->b);
		c->rrb--;
		ctx_append(OP_RRB, c);
	}
}

// sa and sb and ss
void	opflush_s(t_ctx *c)
{
	while (c->sa > 0 && c->sb > 0)
	{
		swap(c->a);
		swap(c->b);
		c->sa--;
		c->sb--;
		ctx_append(OP_SS, c);
	}
	while (c->sa > 0)
	{
		swap(c->a);
		c->sa--;
		ctx_append(OP_SA, c);
	}
	while (c->sb > 0)
	{
		swap(c->b);
		c->sb--;
		ctx_append(OP_SB, c);
	}
}
