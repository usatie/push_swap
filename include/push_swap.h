/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:51:01 by susami            #+#    #+#             */
/*   Updated: 2022/06/05 16:00:22 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

# ifndef VERBOSE
#  define VERBOSE FALSE
# endif
typedef struct s_stack {
	int		*arr;
	size_t	len;
	size_t	cap;
}	t_stack;

typedef struct s_stack_pair {
	t_stack	*a;
	t_stack	*b;
	size_t	sa;
	size_t	sb;
	size_t	pa;
	size_t	pb;
	size_t	ra;
	size_t	rb;
	size_t	rra;
	size_t	rrb;
	size_t	n_op;
	BOOL	dry;
}	t_stack_pair;

typedef long	t_elm;

size_t			max(size_t a, size_t b);
size_t			min(size_t a, size_t b);

size_t			len_p(t_stack_pair *p);
size_t			len_a(t_stack_pair *p);
size_t			len_b(t_stack_pair *p);

t_elm			get_elm(size_t i, t_stack_pair *p);

t_elm			min_p(t_stack_pair *p);
t_elm			min_a(t_stack_pair *p);
t_elm			min_b(t_stack_pair *p);

t_elm			max_p(t_stack_pair *p);
t_elm			max_a(t_stack_pair *p);
t_elm			max_b(t_stack_pair *p);

// stack.c
t_stack			*init_stack(size_t cap);
void			deinit_stack(t_stack *s);
BOOL			contains(t_elm e, t_stack *s);

// stack_pair.c
t_stack_pair	*init_stack_pair(size_t cap);
void			deinit_stack_pair(t_stack_pair *m);
void			print_stack_pair(t_stack_pair *m);
void			dryprint(char *op, t_stack_pair *p);

// op_basic.c
// Returns 0 on success, -1 on error
void			swap(t_stack *s);
t_elm			pop(t_stack *s);
void			push(t_stack *s, t_elm e);
void			rotate(t_stack *s);
void			reverse_rotate(t_stack *s);

void			opflush(t_stack_pair *p);
void			opflush_r(t_stack_pair *p);
void			opflush_rr(t_stack_pair *p);
void			opflush_p(t_stack_pair *p);
void			opflush_s(t_stack_pair *p);

// op_s.c
void			sa(t_stack_pair *p);
void			sb(t_stack_pair *p);
void			ss(t_stack_pair *p);

// op_p.c
void			pa(t_stack_pair *p);
void			pb(t_stack_pair *p);

// op_r.c
void			ra(t_stack_pair *p);
void			rb(t_stack_pair *p);
void			rr(t_stack_pair *p);

// op_rr.c
void			rra(t_stack_pair *p);
void			rrb(t_stack_pair *p);
void			rrr(t_stack_pair *p);

void			insert_sort(t_stack_pair *p);
#endif
