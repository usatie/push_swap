/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:04:21 by susami            #+#    #+#             */
/*   Updated: 2022/06/05 16:22:36 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

size_t	min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

size_t	len_p(t_ps_ctx *c)
{
	return (c->a->len + c->b->len);
}

size_t	len_a(t_ps_ctx *c)
{
	return (c->a->len - c->pb + c->pa);
}

size_t	len_b(t_ps_ctx *c)
{
	return (c->b->len - c->pa + c->pb);
}

t_elm	get_elm(size_t i, t_ps_ctx *c)
{
	(void)i;
	(void)c;
	return (0);
}
