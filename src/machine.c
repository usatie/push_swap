/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:27:19 by susami            #+#    #+#             */
/*   Updated: 2022/05/30 21:52:25 by susami           ###   ########.fr       */
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

void	print_machine(t_machine *m)
{
	size_t	i;

	ft_printf("-----------------------------------------------------------------------\n");
	i = 0;
	while (i < m->a->len || i < m->b->len)
	{
		if (i < m->a->len)
			ft_printf("%d", m->a->arr[i]);
		ft_printf(" ");
		if (i < m->b->len)
			ft_printf("%d", m->b->arr[i]);
		ft_printf("\n");
		i++;
	}
	ft_printf("- -\na b\n");
}
