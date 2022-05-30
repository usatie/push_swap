/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:52:07 by susami            #+#    #+#             */
/*   Updated: 2022/05/30 21:27:18 by susami           ###   ########.fr       */
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

// s->len must be checked before call. The len must be >= 2.
void	swap(t_stack *s)
{
	t_elm	e;

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
	t_elm	last;

	if (s->len == 0)
		return ;
	last = s->arr[s->len - 1];
	i = 0;
	while (i + 1 < s->len)
		s->arr[i + 1] = s->arr[i];
	s->arr[0] = last;
}

void	reverse_rotate(t_stack *s)
{
	size_t	i;
	t_elm	first;

	if (s->len == 0)
		return ;
	first = s->arr[0];
	i = 0;
	while (i + 1 < s->len)
		s->arr[i] = s->arr[i + 1];
	s->arr[s->len - 1] = first;
}
