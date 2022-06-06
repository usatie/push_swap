/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:39:27 by susami            #+#    #+#             */
/*   Updated: 2022/06/06 19:37:06 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_ctx *c)
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
	if (OPTIMIZE)
		return ;
	opflush(c);
}

void	rrb(t_ctx *c)
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
	if (OPTIMIZE)
		return ;
	opflush(c);
}

void	rrr(t_ctx *c)
{
	rra(c);
	rrb(c);
}
