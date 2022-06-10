/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:28:13 by susami            #+#    #+#             */
/*   Updated: 2022/06/10 16:28:29 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
