/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:27:19 by susami            #+#    #+#             */
/*   Updated: 2022/06/08 12:43:39 by susami           ###   ########.fr       */
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

void	print_ctx(t_ctx *c)
{
	size_t	i;

	if (DEBUG)
	{
		i = max(c->a->len, c->b->len);
		while (i-- > 0)
		{
			if (i < c->a->len)
				ft_debug_printf("%10d", c->a->arr[i]);
			else
				ft_debug_printf("          ");
			ft_debug_printf(" ");
			if (i < c->b->len)
				ft_debug_printf("%-10d", c->b->arr[i]);
			else
				ft_debug_printf(" ");
			ft_debug_printf("\n");
		}
		ft_debug_printf("---------- -----------\n         a b\n");
	}
}

void	dryprint(char *op, t_ctx *c)
{
	if (ft_strcmp(op, "pa") == 0)
		push(c->ops, OP_PA);
	else if (ft_strcmp(op, "pb") == 0)
		push(c->ops, OP_PB);
	else if (ft_strcmp(op, "sa") == 0)
		push(c->ops, OP_SA);
	else if (ft_strcmp(op, "sb") == 0)
		push(c->ops, OP_SB);
	else if (ft_strcmp(op, "ss") == 0)
		push(c->ops, OP_SS);
	else if (ft_strcmp(op, "ra") == 0)
		push(c->ops, OP_RA);
	else if (ft_strcmp(op, "rb") == 0)
		push(c->ops, OP_RB);
	else if (ft_strcmp(op, "rr") == 0)
		push(c->ops, OP_RR);
	else if (ft_strcmp(op, "rra") == 0)
		push(c->ops, OP_RRA);
	else if (ft_strcmp(op, "rrb") == 0)
		push(c->ops, OP_RRB);
	else if (ft_strcmp(op, "rrr") == 0)
		push(c->ops, OP_RRR);
	else
		ft_debug_printf("Unexpected Op: %s\n", op);
	ft_debug_printf("%s\n", op);
}
