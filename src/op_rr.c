/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:39:27 by susami            #+#    #+#             */
/*   Updated: 2022/05/30 23:40:39 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a, t_stack *b)
{
	(void)b;
	reverse_rotate(a);
}

void	rrb(t_stack *a, t_stack *b)
{
	(void)a;
	reverse_rotate(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, b);
	rrb(a, b);
}
