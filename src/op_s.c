/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:34:05 by susami            #+#    #+#             */
/*   Updated: 2022/05/30 23:35:17 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, t_stack *b)
{
	(void)b;
	swap(a);
}

void	sb(t_stack *a, t_stack *b)
{
	(void)a;
	swap(b);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, b);
	sb(a, b);
}
