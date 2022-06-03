/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:36:00 by susami            #+#    #+#             */
/*   Updated: 2022/06/03 16:29:03 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	opflush_p(t_stack_pair *p)
{
	while (p->pa > 0)
	{
		ft_dprintf(p->fd, "pa\n");
		push(p->a, pop(p->b));
		p->pa--;
	}
	while (p->pb > 0)
	{
		ft_dprintf(p->fd, "pb\n");
		push(p->b, pop(p->a));
		p->pb--;
	}
}

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
