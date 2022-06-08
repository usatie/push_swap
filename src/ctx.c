/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:27:19 by susami            #+#    #+#             */
/*   Updated: 2022/06/08 15:57:37 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "push_swap.h"

t_ctx	*init_ctx(size_t cap)
{
	t_ctx	*c;

	c = ft_calloc(1, sizeof(t_ctx));
	if (c == NULL)
		return (NULL);
	c->a = init_stack(cap);
	if (c->a == NULL)
	{
		deinit_ctx(c);
		return (NULL);
	}
	c->b = init_stack(cap);
	if (c->b == NULL)
	{
		deinit_ctx(c);
		return (NULL);
	}
	c->ops = init_stack(0);
	if (c->ops == NULL)
	{
		deinit_ctx(c);
		return (NULL);
	}
	return (c);
}

void	deinit_ctx(t_ctx *c)
{
	if (c)
	{
		deinit_stack(c->a);
		deinit_stack(c->b);
		free(c);
	}
}
