/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:27:19 by susami            #+#    #+#             */
/*   Updated: 2022/06/10 16:41:03 by susami           ###   ########.fr       */
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

void	ctx_deinit_all(t_ctx **arr, size_t n)
{
	while (n-- > 0)
		ctx_deinit(arr[n]);
}
