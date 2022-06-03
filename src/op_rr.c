/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:39:27 by susami            #+#    #+#             */
/*   Updated: 2022/06/03 14:08:19 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack_pair *p)
{
	reverse_rotate(p->a);
}

void	rrb(t_stack_pair *p)
{
	reverse_rotate(p->b);
}

void	rrr(t_stack_pair *p)
{
	reverse_rotate(p->a);
	reverse_rotate(p->b);
}
