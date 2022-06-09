/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:23:48 by susami            #+#    #+#             */
/*   Updated: 2022/06/09 16:35:23 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_elm(t_elm *a, t_elm *b)
{
	t_elm	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	sort(t_stack *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < s->len)
	{
		j = i + 1;
		while (j < s->len)
		{
			if (s->arr[i] > s->arr[j])
				swap_elm(&s->arr[i], &s->arr[j]);
			j++;
		}
		i++;
	}
}

int	simplify(t_stack *s)
{
	size_t	i;
	size_t	j;
	t_stack	*d;

	d = stack_dup(s);
	if (d == NULL)
		return (-1);
	sort(d);
	i = 0;
	while (i < s->len)
	{
		j = 0;
		while (j < d->len)
		{
			if (d->arr[j] == s->arr[i])
			{
				s->arr[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	return (0);
}
