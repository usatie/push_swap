/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:34:05 by susami            #+#    #+#             */
/*   Updated: 2022/06/16 09:10:59 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ctx *c)
{
	if (c->a->len < 2)
		return ;
	swap(c->a);
	ctx_append(OP_SA, c);
}

void	sb(t_ctx *c)
{
	if (c->b->len < 2)
		return ;
	swap(c->b);
	ctx_append(OP_SB, c);
}

void	ss(t_ctx *c)
{
	if (c->a->len < 2)
		sb(c);
	else if (c->b->len < 2)
		sa(c);
	else
	{
		swap(c->a);
		swap(c->b);
		ctx_append(OP_SS, c);
	}
}
