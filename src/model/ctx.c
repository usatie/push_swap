/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:27:19 by susami            #+#    #+#             */
/*   Updated: 2022/06/09 18:49:54 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "push_swap.h"

t_ctx	*ctx_init(size_t cap)
{
	t_ctx	*c;

	c = ft_calloc(1, sizeof(t_ctx));
	if (c == NULL)
		return (NULL);
	c->a = stack_init(cap);
	if (c->a == NULL)
	{
		ctx_deinit(c);
		return (NULL);
	}
	c->b = stack_init(cap);
	if (c->b == NULL)
	{
		ctx_deinit(c);
		return (NULL);
	}
	c->ops = stack_init(0);
	if (c->ops == NULL)
	{
		ctx_deinit(c);
		return (NULL);
	}
	return (c);
}

void	ctx_deinit(t_ctx *c)
{
	if (c)
	{
		stack_deinit(c->a);
		stack_deinit(c->b);
		stack_deinit(c->ops);
		free(c);
	}
}

void	ctx_append(t_elm op, t_ctx *c)
{
	ft_debug_printf("%s\n", op_name(op));
	push(c->ops, op);
	debug_print_ctx(c);
}

void	ctx_deinit_all(t_ctx **c, size_t n)
{
	while (n-- > 0)
		ctx_deinit(c[n]);
}

void	ctx_print_best(t_ctx **c, size_t n)
{
	size_t	best;
	size_t	best_i;

	best = -1;
	while (n-- > 0)
	{
		if (best > n_op(c[n]))
		{
			best = n_op(c[n]);
			best_i = n;
		}
	}
	print_ops(c[best_i]);
}
