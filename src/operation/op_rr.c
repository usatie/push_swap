/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:39:27 by susami            #+#    #+#             */
/*   Updated: 2022/06/09 16:06:53 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_ctx *c)
{
	if (c->a->len < 2)
		return ;
	reverse_rotate(c->a);
	ctx_append(OP_RRA, c);
}

void	rrb(t_ctx *c)
{
	if (c->b->len < 2)
		return ;
	reverse_rotate(c->b);
	ctx_append(OP_RRB, c);
}

void	rrr(t_ctx *c)
{
	if (c->a->len < 2)
		rrb(c);
	else if (c->b->len < 2)
		rra(c);
	else
	{
		reverse_rotate(c->a);
		reverse_rotate(c->b);
		ctx_append(OP_RRR, c);
	}
}
