/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:52:07 by susami            #+#    #+#             */
/*   Updated: 2022/05/30 19:05:21 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "push_swap.h"
#include "ft_printf.h"

void	push(t_stack *s, t_elm e)
{
	if (s->cap == 0 || s->arr == NULL)
	{
		s->cap = 256;
		s->arr = malloc(sizeof(t_elm) * s->cap);
	}
	if (s->len == s->cap)
	{
		s->cap *= 2;
		s->arr = reallocf(s->arr, sizeof(t_elm) * s->cap);
	}
	s->arr[s->len] = e;
	s->len += 1;
}
