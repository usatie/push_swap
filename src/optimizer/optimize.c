/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:10:06 by susami            #+#    #+#             */
/*   Updated: 2022/06/12 15:27:27 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_debug.h"
#include "push_swap.h"

t_ctx	*optimize(int argc, char **argv, t_ctx *c)
{
	t_ctx	*prev;
	size_t	i;

	ft_debug_printf("\n=====[OPTIMIZE START] (before = %d)=====\n\n", opsize(c));
	while (1)
	{
		prev = c;
		c = argparse_ctx(argc, argv);
		if (c == NULL)
		{
			ctx_deinit(prev);
			return (NULL);
		}
		i = 0;
		while (i < prev->ops->len)
			op_func(prev->ops->arr[i++])(c);
		opflush(c);
		if (prev->ops->len == opsize(c))
			break ;
		ctx_deinit(prev);
	}
	ctx_deinit(prev);
	ft_debug_printf("\n=====[OPTIMIZE END] (after = %d)=====\n\n", opsize(c));
	return (c);
}
