/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:51:01 by susami            #+#    #+#             */
/*   Updated: 2022/05/30 20:52:16 by susami           ###   ########.fr       */
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
BOOL		has_duplicate_elems(t_stack *s);

// machine.c
t_machine	*init_machine(size_t cap);
void		deinit_machine(t_machine *m);

// op_basic.c
void		swap(t_stack *s);
// Returns 0 on success, -1 on error
int			pop(t_stack *s, t_elm *e);
void		push(t_stack *s, t_elm e);
void		rotate(t_stack *s);
void		reverse_rotate(t_stack *s);

// op_s.c
void		sa(t_machine *m);
void		sb(t_machine *m);
void		ss(t_machine *m);

// op_p.c
void		pa(t_machine *m);
void		pb(t_machine *m);

// op_r.c
void		ra(t_machine *m);
void		rb(t_machine *m);
void		rr(t_machine *m);

// op_rr.c
void		rra(t_machine *m);
void		rrb(t_machine *m);
void		rrr(t_machine *m);
#endif
