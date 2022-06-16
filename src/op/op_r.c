/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:38:07 by susami            #+#    #+#             */
/*   Updated: 2022/06/16 09:12:31 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ctx *c)
{
	if (c->a->len < 2)
		return ;
	rotate(c->a);
	ctx_append(OP_RA, c);
}

void	rb(t_ctx *c)
{
	if (c->b->len < 2)
		return ;
	rotate(c->b);
	ctx_append(OP_RB, c);
}

void	rr(t_ctx *c)
{
	if (c->a->len < 2)
		rb(c);
	else if (c->b->len < 2)
		ra(c);
	else
	{
		rotate(c->a);
		rotate(c->b);
		ctx_append(OP_RR, c);
	}
}
