/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:27:19 by susami            #+#    #+#             */
/*   Updated: 2022/05/30 20:52:41 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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
