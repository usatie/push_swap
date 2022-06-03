/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:34:05 by susami            #+#    #+#             */
/*   Updated: 2022/06/03 16:28:59 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	opflush_s(t_stack_pair *p)
{
	while (p->sa > 0 && p->sb > 0)
	{
		ft_dprintf(p->fd, "ss\n");
		swap(p->a);
		swap(p->b);
		p->sa--;
		p->sb--;
	}
	while (p->sa > 0)
	{
		ft_dprintf(p->fd, "sa\n");
		swap(p->a);
		p->sa--;
	}
	while (p->sb > 0)
	{
		ft_dprintf(p->fd, "sb\n");
		swap(p->b);
		p->sb--;
	}
}

void	sa(t_stack_pair *p)
{
	if (p->a->len < 3)
		ra(p);
	else
	{
		opflush_r(p);
		opflush_rr(p);
		opflush_p(p);
		p->sa++;
		p->sa %= 2;
	}
}

void	sb(t_stack_pair *p)
{
	if (p->b->len < 3)
		rb(p);
	else
	{
		opflush_r(p);
		opflush_rr(p);
		opflush_p(p);
		p->sb++;
		p->sb %= 2;
	}
}

void	ss(t_stack_pair *p)
{
	sa(p);
	sb(p);
}
