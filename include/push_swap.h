/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:51:01 by susami            #+#    #+#             */
/*   Updated: 2022/06/05 16:14:30 by susami           ###   ########.fr       */
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

typedef struct s_ps_ctx {
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
}	t_ps_ctx;

typedef long	t_elm;

size_t			max(size_t a, size_t b);
size_t			min(size_t a, size_t b);

size_t			len_p(t_ps_ctx *c);
size_t			len_a(t_ps_ctx *c);
size_t			len_b(t_ps_ctx *c);

t_elm			get_elm(size_t i, t_ps_ctx *c);

t_elm			min_p(t_ps_ctx *c);
t_elm			min_a(t_ps_ctx *c);
t_elm			min_b(t_ps_ctx *c);

t_elm			max_p(t_ps_ctx *c);
t_elm			max_a(t_ps_ctx *c);
t_elm			max_b(t_ps_ctx *c);

// stack.c
t_stack			*init_stack(size_t cap);
void			deinit_stack(t_stack *s);
BOOL			contains(t_elm e, t_stack *s);

// stack_pair.c
t_ps_ctx		*init_ctx(size_t cap);
void			deinit_ctx(t_ps_ctx *m);
void			print_ctx(t_ps_ctx *m);
void			dryprint(char *op, t_ps_ctx *c);

// op_basic.c
// Returns 0 on success, -1 on error
void			swap(t_stack *s);
t_elm			pop(t_stack *s);
void			push(t_stack *s, t_elm e);
void			rotate(t_stack *s);
void			reverse_rotate(t_stack *s);

void			opflush(t_ps_ctx *c);
void			opflush_r(t_ps_ctx *c);
void			opflush_rr(t_ps_ctx *c);
void			opflush_p(t_ps_ctx *c);
void			opflush_s(t_ps_ctx *c);

// op_s.c
void			sa(t_ps_ctx *c);
void			sb(t_ps_ctx *c);
void			ss(t_ps_ctx *c);

// op_p.c
void			pa(t_ps_ctx *c);
void			pb(t_ps_ctx *c);

// op_r.c
void			ra(t_ps_ctx *c);
void			rb(t_ps_ctx *c);
void			rr(t_ps_ctx *c);

// op_rr.c
void			rra(t_ps_ctx *c);
void			rrb(t_ps_ctx *c);
void			rrr(t_ps_ctx *c);

void			insert_sort(t_ps_ctx *c);
#endif
