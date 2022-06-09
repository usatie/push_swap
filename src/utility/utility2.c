/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 23:31:49 by susami            #+#    #+#             */
/*   Updated: 2022/06/09 15:58:09 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

// pa/pb buffering: doesn't matter
// sa/sb buffering: swap (len-1) and (len-2)
// ra/rra/rb/rrb buffering: (i + r - rr) % len
//

t_elm	top_a(t_ctx *c)
{
	return (get_elm(len_b(c), c));
}

t_elm	top_b(t_ctx *c)
{
	return (get_elm(len_b(c) - 1, c));
}

t_elm	get_elm(size_t i, t_ctx *c)
{
	t_elm	*arr;

	if (i < c->b->len)
		arr = c->b->arr;
	else
	{
		i = len_p(c) - 1 - i;
		arr = c->a->arr;
	}
	return (arr[i]);
}

size_t	n_op(t_ctx *c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (i < c->ops->len)
	{
		if (c->ops->arr[i] > 0)
			n++;
		i++;
	}
	return (n);
}
