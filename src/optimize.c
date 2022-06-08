/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:10:06 by susami            #+#    #+#             */
/*   Updated: 2022/06/08 16:19:53 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

t_ctx	*optimize(int argc, char **argv, t_ctx *c)
{
	t_stack	*ops;
	size_t	i;

	ft_debug_printf("\n=====[OPTIMIZE START] (before = %d)=====\n\n", n_op(c));
	while (1)
	{
		ops = stack_dup(c->ops);
		if (ops == NULL)
			return (NULL);
		ctx_deinit(c);
		c = argparse_ctx(argc, argv);
		if (c == NULL)
			return (NULL);
		i = 0;
		while (i < ops->len)
			op_func(ops->arr[i++])(c);
		opflush(c);
		if (ops->len == n_op(c))
			break ;
	}
	ft_debug_printf("\n=====[OPTIMIZE END] (after = %d)=====\n\n", n_op(c));
	return (c);
}
