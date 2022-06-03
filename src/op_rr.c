/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:39:27 by susami            #+#    #+#             */
/*   Updated: 2022/06/03 16:28:54 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	opflush_rr(t_stack_pair *p)
{
	while (p->rra > 0 && p->rrb > 0)
	{
		ft_dprintf(p->fd, "rrr\n");
		reverse_rotate(p->a);
		reverse_rotate(p->b);
		p->rra--;
		p->rrb--;
	}
	while (p->rra > 0)
	{
		ft_dprintf(p->fd, "rra\n");
		reverse_rotate(p->a);
		p->rra--;
	}
	while (p->rrb > 0)
	{
		ft_dprintf(p->fd, "rrb\n");
		reverse_rotate(p->b);
		p->rrb--;
	}
}

void	rra(t_stack_pair *p)
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

void	rrb(t_stack_pair *p)
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

void	rrr(t_stack_pair *p)
{
	rra(p);
	rrb(p);
}
