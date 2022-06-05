/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:36:00 by susami            #+#    #+#             */
/*   Updated: 2022/06/05 22:24:00 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_ctx *c)
{
	opflush_r(c);
	opflush_rr(c);
	opflush_s(c);
	if (c->pb > 0)
		c->pb--;
	else if (c->b->len > c->pa)
		c->pa++;
	if (NOOPTIMIZE)
		opflush(c);
}

void	pb(t_ctx *c)
{
	opflush_r(c);
	opflush_rr(c);
	opflush_s(c);
	if (c->pa > 0)
		c->pa--;
	else if (c->a->len > c->pb)
		c->pb++;
	if (NOOPTIMIZE)
		opflush(c);
}
