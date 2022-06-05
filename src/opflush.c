/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opflush.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:00:43 by susami            #+#    #+#             */
/*   Updated: 2022/06/05 20:12:46 by susami           ###   ########.fr       */
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

void	opflush_p(t_ctx *c)
{
	while (c->pa > 0)
	{
		dryprint("pa", c);
		push(c->a, pop(c->b));
		c->pa--;
		print_ctx(c);
	}
	while (c->pb > 0)
	{
		dryprint("pb", c);
		push(c->b, pop(c->a));
		c->pb--;
		print_ctx(c);
	}
}

// ra and rra
void	opflush_r(t_ctx *c)
{
	while (c->ra > 0 && c->rb > 0)
	{
		dryprint("rr", c);
		rotate(c->a);
		rotate(c->b);
		c->ra--;
		c->rb--;
		print_ctx(c);
	}
	while (c->ra > 0)
	{
		dryprint("ra", c);
		rotate(c->a);
		c->ra--;
		print_ctx(c);
	}
	while (c->rb > 0)
	{
		dryprint("rb", c);
		rotate(c->b);
		c->rb--;
		print_ctx(c);
	}
}

void	opflush_rr(t_ctx *c)
{
	while (c->rra > 0 && c->rrb > 0)
	{
		dryprint("rrr", c);
		reverse_rotate(c->a);
		reverse_rotate(c->b);
		c->rra--;
		c->rrb--;
		print_ctx(c);
	}
	while (c->rra > 0)
	{
		dryprint("rra", c);
		reverse_rotate(c->a);
		c->rra--;
		print_ctx(c);
	}
	while (c->rrb > 0)
	{
		dryprint("rrb", c);
		reverse_rotate(c->b);
		c->rrb--;
		print_ctx(c);
	}
}

void	opflush_s(t_ctx *c)
{
	while (c->sa > 0 && c->sb > 0)
	{
		dryprint("ss", c);
		swap(c->a);
		swap(c->b);
		c->sa--;
		c->sb--;
		print_ctx(c);
	}
	while (c->sa > 0)
	{
		dryprint("sa", c);
		swap(c->a);
		c->sa--;
		print_ctx(c);
	}
	while (c->sb > 0)
	{
		dryprint("sb", c);
		swap(c->b);
		c->sb--;
		print_ctx(c);
	}
}
