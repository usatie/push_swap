/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opflush.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:00:43 by susami            #+#    #+#             */
/*   Updated: 2022/06/05 16:02:16 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		dryprint("pa", p);
		push(p->a, pop(p->b));
		p->pa--;
		print_stack_pair(p);
	}
	while (p->pb > 0)
	{
		dryprint("pb", p);
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
		dryprint("rr", p);
		rotate(p->a);
		rotate(p->b);
		p->ra--;
		p->rb--;
		print_stack_pair(p);
	}
	while (p->ra > 0)
	{
		dryprint("ra", p);
		rotate(p->a);
		p->ra--;
		print_stack_pair(p);
	}
	while (p->rb > 0)
	{
		dryprint("rb", p);
		rotate(p->b);
		p->rb--;
		print_stack_pair(p);
	}
}

void	opflush_rr(t_stack_pair *p)
{
	while (p->rra > 0 && p->rrb > 0)
	{
		dryprint("rrr", p);
		reverse_rotate(p->a);
		reverse_rotate(p->b);
		p->rra--;
		p->rrb--;
		print_stack_pair(p);
	}
	while (p->rra > 0)
	{
		dryprint("rra", p);
		reverse_rotate(p->a);
		p->rra--;
		print_stack_pair(p);
	}
	while (p->rrb > 0)
	{
		dryprint("rrb", p);
		reverse_rotate(p->b);
		p->rrb--;
		print_stack_pair(p);
	}
}

void	opflush_s(t_stack_pair *p)
{
	while (p->sa > 0 && p->sb > 0)
	{
		dryprint("ss", p);
		swap(p->a);
		swap(p->b);
		p->sa--;
		p->sb--;
		print_stack_pair(p);
	}
	while (p->sa > 0)
	{
		dryprint("sa", p);
		swap(p->a);
		p->sa--;
		print_stack_pair(p);
	}
	while (p->sb > 0)
	{
		dryprint("sb", p);
		swap(p->b);
		p->sb--;
		print_stack_pair(p);
	}
}
