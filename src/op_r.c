/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:38:07 by susami            #+#    #+#             */
/*   Updated: 2022/06/06 19:36:46 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ctx *c)
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
		if (*rrp > 0)
			*rrp -= 1;
		else
			*rp += 1;
		*rp %= len;
		if (*rp > 0 && (len - *rp) < *rp)
		{
			*rrp = len - *rp;
			*rp = 0;
		}
	}
	if (OPTIMIZE)
		return ;
	opflush(c);
}

void	rb(t_ctx *c)
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
		if (*rrp > 0)
			*rrp -= 1;
		else
			*rp += 1;
		*rp %= len;
		if (*rp > 0 && (len - *rp) < *rp)
		{
			*rrp = len - *rp;
			*rp = 0;
		}
	}
	if (OPTIMIZE)
		return ;
	opflush(c);
}

void	rr(t_ctx *c)
{
	ra(c);
	rb(c);
}
