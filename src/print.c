/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:57:44 by susami            #+#    #+#             */
/*   Updated: 2022/06/08 16:01:11 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

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
