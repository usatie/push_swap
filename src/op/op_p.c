/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:36:00 by susami            #+#    #+#             */
/*   Updated: 2022/06/16 09:12:50 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_ctx *c)
{
	if (c->b->len < 1)
		return ;
	push(c->a, pop(c->b));
	ctx_append(OP_PA, c);
}

void	pb(t_ctx *c)
{
	if (c->a->len < 1)
		return ;
	push(c->b, pop(c->a));
	ctx_append(OP_PB, c);
}
