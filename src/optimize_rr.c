/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:06:16 by susami            #+#    #+#             */
/*   Updated: 2022/06/09 16:06:20 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_rra(t_ctx *c)
{
	size_t	len;
	size_t	*rp;
	size_t	*rrp;

	opflush_p(c);
	opflush_s(c);
	len = c->a->len;
	rp = &(c->ra);
	rrp = &(c->rra);
	if (len > 0)
	{
		if (*rp > 0)
			*rp -= 1;
		else
			*rrp += 1;
		*rrp %= len;
		if (*rrp > 0 && (len - *rrp) < *rrp)
		{
			*rp = len - *rrp;
			*rrp = 0;
		}
	}
}

void	optimize_rrb(t_ctx *c)
{
	size_t	len;
	size_t	*rp;
	size_t	*rrp;

	opflush_p(c);
	opflush_s(c);
	len = c->b->len;
	rp = &(c->rb);
	rrp = &(c->rrb);
	if (len > 0)
	{
		if (*rp > 0)
			*rp -= 1;
		else
			*rrp += 1;
		*rrp %= len;
		if (*rrp > 0 && (len - *rrp) < *rrp)
		{
			*rp = len - *rrp;
			*rrp = 0;
		}
	}
}

void	optimize_rrr(t_ctx *c)
{
	optimize_rra(c);
	optimize_rrb(c);
}
