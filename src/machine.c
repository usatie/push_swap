/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:27:19 by susami            #+#    #+#             */
/*   Updated: 2022/05/31 00:13:24 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "push_swap.h"

t_machine	*init_machine(size_t cap)
{
	t_machine	*m;

	m = malloc(sizeof(t_machine));
	if (m == NULL)
		return (NULL);
	m->a = init_stack(cap);
	if (m->a == NULL)
	{
		deinit_machine(m);
		return (NULL);
	}
	m->b = init_stack(cap);
	if (m->b == NULL)
	{
		deinit_machine(m);
		return (NULL);
	}
	return (m);
}

void	deinit_machine(t_machine *m)
{
	if (m)
	{
		deinit_stack(m->a);
		deinit_stack(m->b);
		free(m);
	}
}

static size_t	max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	print_machine(t_machine *m)
{
	size_t	i;

	ft_printf("-----------------------------------------------------------------------\n");
	i = max(m->a->len, m->b->len);
	while (i-- > 0)
	{
		if (i < m->a->len)
			ft_printf("%d", m->a->arr[i]);
		ft_printf(" ");
		if (i < m->b->len)
			ft_printf("%d", m->b->arr[i]);
		ft_printf("\n");
	}
	ft_printf("- -\na b\n");
}
