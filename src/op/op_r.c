/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:38:07 by susami            #+#    #+#             */
/*   Updated: 2022/06/09 16:05:53 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ctx *c)
{
	rotate(c->a);
	ctx_append(OP_RA, c);
}

void	rb(t_ctx *c)
{
	rotate(c->b);
	ctx_append(OP_RB, c);
}

void	rr(t_ctx *c)
{
	rotate(c->a);
	rotate(c->b);
	ctx_append(OP_RR, c);
}
