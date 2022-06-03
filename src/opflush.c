/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opflush.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:00:43 by susami            #+#    #+#             */
/*   Updated: 2022/06/03 18:44:15 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	opflush(t_stack_pair *p)
{
	opflush_r(p);
	opflush_rr(p);
	opflush_p(p);
	opflush_s(p);
}

void	opflush_p(t_stack_pair *p)
{
	while (p->pa > 0)
	{
		ft_dprintf(p->fd, "pa\n");
		push(p->a, pop(p->b));
		p->pa--;
		print_stack_pair(p);
	}
	while (p->pb > 0)
	{
		ft_dprintf(p->fd, "pb\n");
		push(p->b, pop(p->a));
		p->pb--;
		print_stack_pair(p);
	}
}

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
		print_stack_pair(p);
	}
	while (p->ra > 0)
	{
		ft_dprintf(p->fd, "ra\n");
		rotate(p->a);
		p->ra--;
		print_stack_pair(p);
	}
	while (p->rb > 0)
	{
		ft_dprintf(p->fd, "rb\n");
		rotate(p->b);
		p->rb--;
		print_stack_pair(p);
	}
}

void	opflush_rr(t_stack_pair *p)
{
	while (p->rra > 0 && p->rrb > 0)
	{
		ft_dprintf(p->fd, "rrr\n");
		reverse_rotate(p->a);
		reverse_rotate(p->b);
		p->rra--;
		p->rrb--;
		print_stack_pair(p);
	}
	while (p->rra > 0)
	{
		ft_dprintf(p->fd, "rra\n");
		reverse_rotate(p->a);
		p->rra--;
		print_stack_pair(p);
	}
	while (p->rrb > 0)
	{
		ft_dprintf(p->fd, "rrb\n");
		reverse_rotate(p->b);
		p->rrb--;
		print_stack_pair(p);
	}
}

void	opflush_s(t_stack_pair *p)
{
	while (p->sa > 0 && p->sb > 0)
	{
		ft_dprintf(p->fd, "ss\n");
		swap(p->a);
		swap(p->b);
		p->sa--;
		p->sb--;
		print_stack_pair(p);
	}
	while (p->sa > 0)
	{
		ft_dprintf(p->fd, "sa\n");
		swap(p->a);
		p->sa--;
		print_stack_pair(p);
	}
	while (p->sb > 0)
	{
		ft_dprintf(p->fd, "sb\n");
		swap(p->b);
		p->sb--;
		print_stack_pair(p);
	}
}
