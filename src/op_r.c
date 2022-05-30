/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:38:07 by susami            #+#    #+#             */
/*   Updated: 2022/05/30 23:39:18 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, t_stack *b)
{
	(void)b;
	rotate(a);
}

void	rb(t_stack *a, t_stack *b)
{
	(void)a;
	rotate(b);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a, b);
	rb(a, b);
}
