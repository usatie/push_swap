/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:38:07 by susami            #+#    #+#             */
/*   Updated: 2022/06/03 18:33:54 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack_pair *p)
{
	size_t	len;
	size_t	*rp;
	size_t	*rrp;

	opflush_p(p);
	opflush_s(p);
	len = p->a->len;
	rp = &(p->ra);
	rrp = &(p->rra);
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
}

void	rb(t_stack_pair *p)
{
	size_t	len;
	size_t	*rp;
	size_t	*rrp;

	opflush_p(p);
	opflush_s(p);
	len = p->b->len;
	rp = &(p->rb);
	rrp = &(p->rrb);
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
}

void	rr(t_stack_pair *p)
{
	ra(p);
	rb(p);
}
