/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:38:07 by susami            #+#    #+#             */
/*   Updated: 2022/06/03 14:07:47 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack_pair *p)
{
	rotate(p->a);
}

void	rb(t_stack_pair *p)
{
	rotate(p->b);
}

void	rr(t_stack_pair *p)
{
	rotate(p->a);
	rotate(p->b);
}
