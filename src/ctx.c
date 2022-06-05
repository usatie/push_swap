/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:27:19 by susami            #+#    #+#             */
/*   Updated: 2022/06/05 20:11:09 by susami           ###   ########.fr       */
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

	if (VERBOSE)
	{
		i = max(c->a->len, c->b->len);
		while (i-- > 0)
		{
			if (i < c->a->len)
				ft_printf("%10d", c->a->arr[i]);
			else
				ft_printf("          ");
			ft_printf(" ");
			if (i < c->b->len)
				ft_printf("%-10d", c->b->arr[i]);
			else
				ft_printf(" ");
			ft_printf("\n");
		}
		ft_printf("---------- -----------\n         a b\n");
	}
}

void	dryprint(char *op, t_ctx *c)
{
	c->n_op++;
	if (c->dry == TRUE)
		return ;
	else
		ft_printf("%s\n", op);
}
