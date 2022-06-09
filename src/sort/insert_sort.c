/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:34:34 by susami            #+#    #+#             */
/*   Updated: 2022/06/09 02:22:34 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

/*
static int	xor(int a, int b)
{
	if (!a && b)
		return (1);
	else if (a && !b)
		return (1);
	else
		return (0);
}
*/

t_elm	min_b(t_ctx *c)
{
	size_t	i;
	t_elm	m;

	if (len_b(c) == 1)
		return (get_elm(0, c));
	m = get_elm(0, c);
	i = 1;
	while (i < len_b(c))
	{
		if (get_elm(i, c) < m)
			m = get_elm(i, c);
		i++;
	}
	return (m);
}

t_elm	max_b(t_ctx *c)
{
	size_t	i;
	t_elm	m;

	if (len_b(c) == 1)
		return (get_elm(0, c));
	m = get_elm(0, c);
	i = 1;
	while (i < len_b(c))
	{
		if (get_elm(i, c) > m)
			m = get_elm(i, c);
		i++;
	}
	return (m);
}

// a: 1 9 7 4 6 2 3 5 8 | : b
// a: 1 9 7 4 6 2 3 | 5 8 : b
// a: 1 9 7 4 6 2 3 | 8 5 : b
// a: 1 9 7 4 6 2 | 8 5 3 : b
void	insert_sort(t_ctx *c)
{
	t_elm	next;

	if (len_a(c) >= 2)
	{
		if (get_elm(0, c) > get_elm(1, c))
			sa(c);
		pb(c);
		pb(c);
	}
	while (len_a(c) > 0)
	{
		next = top_a(c);
		if (max_b(c) > next && next > min_b(c))
			while (!(top_b(c) < next && get_elm(0, c) > next))
				rb(c);
		pb(c);
		while (top_b(c) < get_elm(0, c))
			rb(c);
	}
	if (len_b(c) >= 2)
		while (top_b(c) < get_elm(0, c))
			rb(c);
	while (len_b(c) > 0)
		pa(c);
	opflush(c);
}
