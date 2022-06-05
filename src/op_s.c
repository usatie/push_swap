/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:34:05 by susami            #+#    #+#             */
/*   Updated: 2022/06/05 20:11:21 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ctx *c)
{
	if (c->a->len < 3)
		ra(c);
	else
	{
		opflush_r(c);
		opflush_rr(c);
		opflush_p(c);
		c->sa++;
		c->sa %= 2;
	}
}

void	sb(t_ctx *c)
{
	if (c->b->len < 3)
		rb(c);
	else
	{
		opflush_r(c);
		opflush_rr(c);
		opflush_p(c);
		c->sb++;
		c->sb %= 2;
	}
}

void	ss(t_ctx *c)
{
	sa(c);
	sb(c);
}
