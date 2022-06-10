/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:39:21 by susami            #+#    #+#             */
/*   Updated: 2022/06/10 16:48:52 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

void	ctx_append(t_elm op, t_ctx *c)
{
	ft_debug_printf("%s\n", op_name(op));
	push(c->ops, op);
	debug_print_ctx(c);
}
