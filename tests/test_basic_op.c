/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_basic_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:41:26 by susami            #+#    #+#             */
/*   Updated: 2022/06/03 14:16:06 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	main(void)
{
	t_stack_pair	*p;

	p = init_stack_pair(6);
	printf("-----------------------------------------------------------------------\n");
	printf("Init a and b\n");
	push(p->a, 8);
	push(p->a, 5);
	push(p->a, 6);
	push(p->a, 3);
	push(p->a, 1);
	push(p->a, 2);
	print_stack_pair(p);
	printf("-----------------------------------------------------------------------\n");
	printf("Exec sa\n");
	sa(p);
	print_stack_pair(p);
	printf("-----------------------------------------------------------------------\n");
	printf("Exec pb pb pb\n");
	pb(p);
	pb(p);
	pb(p);
	print_stack_pair(p);
	printf("-----------------------------------------------------------------------\n");
	printf("Exec ra rb\n");
	ra(p);
	rb(p);
	print_stack_pair(p);
	printf("-----------------------------------------------------------------------\n");
	printf("Exec rra rrb\n");
	rra(p);
	rrb(p);
	print_stack_pair(p);
	printf("-----------------------------------------------------------------------\n");
	printf("Exec sa\n");
	sa(p);
	printf("-----------------------------------------------------------------------\n");
	printf("Exec pa pa pa\n");
	pa(p);
	pa(p);
	pa(p);
	print_stack_pair(p);
}
