/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:38:07 by susami            #+#    #+#             */
/*   Updated: 2022/06/03 16:28:49 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

// ra and rra
void	opflush_r(t_stack_pair *p)
{
	while (p->ra > 0 && p->rb > 0)
	{
		ft_dprintf(p->fd, "rr\n");
		rotate(p->a);
		rotate(p->b);
		p->ra--;
		p->rb--;
	}
	while (p->ra > 0)
	{
		ft_dprintf(p->fd, "ra\n");
		rotate(p->a);
		p->ra--;
	}
	while (p->rb > 0)
	{
		ft_dprintf(p->fd, "rb\n");
		rotate(p->b);
		p->rb--;
	}
}

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
