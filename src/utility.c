/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:04:21 by susami            #+#    #+#             */
/*   Updated: 2022/06/05 15:30:22 by susami           ###   ########.fr       */
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

size_t	len_p(t_stack_pair *p)
{
	return (p->a->len + p->b->len);
}

size_t	len_a(t_stack_pair *p)
{
	return (p->a->len - p->pb + p->pa);
}

size_t	len_b(t_stack_pair *p)
{
	return (p->b->len - p->pa + p->pb);
}

t_elm	get_elm(size_t i, t_stack_pair *p)
{
	return (0);
}
