/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:51:01 by susami            #+#    #+#             */
/*   Updated: 2022/05/31 00:59:44 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
typedef struct s_stack {
	int		*arr;
	size_t	len;
	size_t	cap;
}	t_stack;

typedef struct s_machine {
	t_stack	*a;
	t_stack	*b;
}	t_machine;

typedef long	t_elm;

// stack.c
t_stack		*init_stack(size_t cap);
void		deinit_stack(t_stack *s);
BOOL		contains(t_elm e, t_stack *s);

// machine.c
t_machine	*init_machine(size_t cap);
void		deinit_machine(t_machine *m);
void		print_machine(t_machine *m);

// op_basic.c
void		swap(t_stack *s);
// Returns 0 on success, -1 on error
t_elm		pop(t_stack *s);
void		push(t_stack *s, t_elm e);
void		rotate(t_stack *s);
void		reverse_rotate(t_stack *s);

// op_s.c
void		sa(t_stack *a, t_stack *b);
void		sb(t_stack *a, t_stack *b);
void		ss(t_stack *a, t_stack *b);

// op_p.c
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);

// op_r.c
void		ra(t_stack *a, t_stack *b);
void		rb(t_stack *a, t_stack *b);
void		rr(t_stack *a, t_stack *b);

// op_rr.c
void		rra(t_stack *a, t_stack *b);
void		rrb(t_stack *a, t_stack *b);
void		rrr(t_stack *a, t_stack *b);

void		insert_sort(t_stack *a, t_stack *b);
#endif
