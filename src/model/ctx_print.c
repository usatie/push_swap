/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:48:33 by susami            #+#    #+#             */
/*   Updated: 2022/06/10 16:49:20 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

void	debug_print_ctx(t_ctx *c)
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

void	print_ops(t_ctx *c)
{
	size_t	i;
	t_stack	*ops;

	ops = c->ops;
	i = 0;
	while (i < ops->len)
	{
		ft_printf("%s\n", op_name(ops->arr[i]));
		i++;
	}
}

void	ctx_print_best(t_ctx **arr, size_t n)
{
	size_t	best;
	size_t	best_i;

	best = -1;
	while (n-- > 0)
	{
		if (best > n_op(arr[n]))
		{
			best = n_op(arr[n]);
			best_i = n;
		}
	}
	print_ops(arr[best_i]);
}
