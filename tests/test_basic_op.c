/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_basic_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:41:26 by susami            #+#    #+#             */
/*   Updated: 2022/05/31 00:31:12 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	main(void)
{
	t_machine	*m;

	m = init_machine(6);
	printf("-----------------------------------------------------------------------\n");
	printf("Init a and b\n");
	push(m->a, 8);
	push(m->a, 5);
	push(m->a, 6);
	push(m->a, 3);
	push(m->a, 1);
	push(m->a, 2);
	print_machine(m);
	printf("-----------------------------------------------------------------------\n");
	printf("Exec sa\n");
	sa(m->a, m->b);
	print_machine(m);
	printf("-----------------------------------------------------------------------\n");
	printf("Exec pb pb pb\n");
	pb(m->a, m->b);
	pb(m->a, m->b);
	pb(m->a, m->b);
	print_machine(m);
	printf("-----------------------------------------------------------------------\n");
	printf("Exec ra rb\n");
	ra(m->a, m->b);
	rb(m->a, m->b);
	print_machine(m);
	printf("-----------------------------------------------------------------------\n");
	printf("Exec rra rrb\n");
	rra(m->a, m->b);
	rrb(m->a, m->b);
	print_machine(m);
	printf("-----------------------------------------------------------------------\n");
	printf("Exec sa\n");
	sa(m->a, m->b);
	printf("-----------------------------------------------------------------------\n");
	printf("Exec pa pa pa\n");
	pa(m->a, m->b);
	pa(m->a, m->b);
	pa(m->a, m->b);
	print_machine(m);
}
