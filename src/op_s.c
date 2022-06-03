/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:34:05 by susami            #+#    #+#             */
/*   Updated: 2022/06/03 18:34:21 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
