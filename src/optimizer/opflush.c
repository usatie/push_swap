/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opflush.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:00:43 by susami            #+#    #+#             */
/*   Updated: 2022/06/12 15:31:16 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		c->pa--;
		pa(c);
	}
	while (c->pb > 0)
	{
		c->pb--;
		pb(c);
	}
}

// ra and rb and rr
void	opflush_r(t_ctx *c)
{
	while (c->ra > 0 && c->rb > 0)
	{
		c->ra--;
		c->rb--;
		rr(c);
	}
	while (c->ra > 0)
	{
		c->ra--;
		ra(c);
	}
	while (c->rb > 0)
	{
		c->rb--;
		rb(c);
	}
}

// rra and rrb and rrr
void	opflush_rr(t_ctx *c)
{
	while (c->rra > 0 && c->rrb > 0)
	{
		c->rra--;
		c->rrb--;
		rrr(c);
	}
	while (c->rra > 0)
	{
		c->rra--;
		rra(c);
	}
	while (c->rrb > 0)
	{
		c->rrb--;
		rrb(c);
	}
}

// sa and sb and ss
void	opflush_s(t_ctx *c)
{
	while (c->sa > 0 && c->sb > 0)
	{
		c->sa--;
		c->sb--;
		ss(c);
	}
	while (c->sa > 0)
	{
		c->sa--;
		sa(c);
	}
	while (c->sb > 0)
	{
		c->sb--;
		sb(c);
	}
}
