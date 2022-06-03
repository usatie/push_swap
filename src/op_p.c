/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:36:00 by susami            #+#    #+#             */
/*   Updated: 2022/06/03 18:34:34 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack_pair *p)
{
	opflush_r(p);
	opflush_rr(p);
	opflush_s(p);
	if (p->pb > 0)
		p->pb--;
	else if (p->b->len > p->pa)
		p->pa++;
}

void	pb(t_stack_pair *p)
{
	opflush_r(p);
	opflush_rr(p);
	opflush_s(p);
	if (p->pa > 0)
		p->pa--;
	else if (p->a->len > p->pb)
		p->pb++;
}
