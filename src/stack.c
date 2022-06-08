/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:26:30 by susami            #+#    #+#             */
/*   Updated: 2022/06/08 17:04:13 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

t_stack	*stack_init(size_t cap)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (s == NULL)
		return (NULL);
	s->len = 0;
	s->cap = cap;
	s->arr = ft_calloc(sizeof(t_elm), cap);
	if (s->arr == NULL)
		return (NULL);
	return (s);
}

void	stack_deinit(t_stack *s)
{
	if (s)
		free(s->arr);
	free(s);
}

BOOL	stack_contains(t_elm e, t_stack *s)
{
	size_t	i;

	i = 0;
	while (i < s->len)
	{
		if (s->arr[i] == e)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_stack	*stack_dup(t_stack *src)
{
	t_stack	*dup;

	dup = stack_init(src->cap);
	if (dup == NULL)
		return (NULL);
	dup->len = src->len;
	ft_memcpy(dup->arr, src->arr, sizeof(t_elm) * src->len);
	return (dup);
}
