/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:05:07 by susami            #+#    #+#             */
/*   Updated: 2022/06/09 16:05:13 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_pa(t_ctx *c)
{
	opflush_r(c);
	opflush_rr(c);
	opflush_s(c);
	if (c->pb > 0)
		c->pb--;
	else if (c->b->len > c->pa)
		c->pa++;
}

void	optimize_pb(t_ctx *c)
{
	opflush_r(c);
	opflush_rr(c);
	opflush_s(c);
	if (c->pa > 0)
		c->pa--;
	else if (c->a->len > c->pb)
		c->pb++;
}
