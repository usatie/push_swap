/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:52:07 by susami            #+#    #+#             */
/*   Updated: 2022/06/10 16:13:38 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "push_swap.h"

void	push(t_stack *s, t_elm e)
{
	if (s->arr == NULL)
	{
		s->cap = 256;
		s->arr = malloc(sizeof(t_elm) * s->cap);
	}
	if (s->len == s->cap)
	{
		s->cap *= 2;
		if (s->cap == 0)
			s->cap = 256;
		s->arr = reallocf(s->arr, sizeof(t_elm) * s->cap);
	}
	s->arr[s->len] = e;
	s->len += 1;
}

void	swap(t_stack *s)
{
	t_elm	e;

	if (s->len < 2)
		return ;
	e = s->arr[s->len - 1];
	s->arr[s->len - 1] = s->arr[s->len - 2];
	s->arr[s->len - 2] = e;
}

// s->len must be checked before call. The len must be >= 1.
t_elm	pop(t_stack *s)
{
	t_elm	e;

	e = s->arr[s->len - 1];
	s->len -= 1;
	return (e);
}

void	rotate(t_stack *s)
{
	size_t	i;
	t_elm	top;

	if (s->len == 0)
		return ;
	top = s->arr[s->len - 1];
	i = s->len - 1;
	while (i > 0)
	{
		s->arr[i] = s->arr[i - 1];
		i--;
	}
	s->arr[0] = top;
}

void	reverse_rotate(t_stack *s)
{
	size_t	i;
	t_elm	bottom;

	if (s->len == 0)
		return ;
	bottom = s->arr[0];
	i = 0;
	while (i + 1 < s->len)
	{
		s->arr[i] = s->arr[i + 1];
		i++;
	}
	s->arr[s->len - 1] = bottom;
}
