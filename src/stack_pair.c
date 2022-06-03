/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:27:19 by susami            #+#    #+#             */
/*   Updated: 2022/06/03 18:44:42 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "push_swap.h"

t_stack_pair	*init_stack_pair(size_t cap)
{
	t_stack_pair	*p;

	p = ft_calloc(1, sizeof(t_stack_pair));
	if (p == NULL)
		return (NULL);
	p->a = init_stack(cap);
	if (p->a == NULL)
	{
		deinit_stack_pair(p);
		return (NULL);
	}
	p->b = init_stack(cap);
	if (p->b == NULL)
	{
		deinit_stack_pair(p);
		return (NULL);
	}
	return (p);
}

void	deinit_stack_pair(t_stack_pair *p)
{
	if (p)
	{
		deinit_stack(p->a);
		deinit_stack(p->b);
		free(p);
	}
}

void	print_stack_pair(t_stack_pair *p)
{
	size_t	i;

	if (VERBOSE)
	{
		i = max(p->a->len, p->b->len);
		while (i-- > 0)
		{
			if (i < p->a->len)
				ft_dprintf(p->fd, "%10d", p->a->arr[i]);
			else
				ft_dprintf(p->fd, "          ");
			ft_dprintf(p->fd, " ");
			if (i < p->b->len)
				ft_dprintf(p->fd, "%-10d", p->b->arr[i]);
			else
				ft_dprintf(p->fd, " ");
			ft_dprintf(p->fd, "\n");
		}
		ft_dprintf(p->fd, "---------- -----------\n         a b\n");
	}
}
