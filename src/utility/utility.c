/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:04:21 by susami            #+#    #+#             */
/*   Updated: 2022/06/09 15:55:03 by susami           ###   ########.fr       */
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

size_t	len_p(t_ctx *c)
{
	return (c->a->len + c->b->len);
}

size_t	len_a(t_ctx *c)
{
	return (c->a->len);
}

size_t	len_b(t_ctx *c)
{
	return (c->b->len);
}
