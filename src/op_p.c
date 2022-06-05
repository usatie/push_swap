/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:36:00 by susami            #+#    #+#             */
/*   Updated: 2022/06/05 16:20:18 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_ps_ctx *c)
{
	opflush_r(c);
	opflush_rr(c);
	opflush_s(c);
	if (c->pb > 0)
		c->pb--;
	else if (c->b->len > c->pa)
		c->pa++;
}

void	pb(t_ps_ctx *c)
{
	opflush_r(c);
	opflush_rr(c);
	opflush_s(c);
	if (c->pa > 0)
		c->pa--;
	else if (c->a->len > c->pb)
		c->pb++;
}
