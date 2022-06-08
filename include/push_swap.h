/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:51:01 by susami            #+#    #+#             */
/*   Updated: 2022/06/08 14:29:55 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

# ifndef DEBUG
#  define DEBUG 0
# endif

# ifndef OPTIMIZE
#  define OPTIMIZE 1
# endif

# define OP_PA 1
# define OP_PB 2
# define OP_SA 3
# define OP_SB 4
# define OP_SS 5
# define OP_RA 6
# define OP_RB 7
# define OP_RR 8
# define OP_RRA 9
# define OP_RRB 10
# define OP_RRR 11

typedef int	t_elm;

typedef struct s_stack {
	t_elm	*arr;
	size_t	len;
	size_t	cap;
}	t_stack;

typedef struct s_ctx {
	t_stack	*a;
	t_stack	*b;
	t_stack	*ops;
	size_t	sa;
	size_t	sb;
	size_t	pa;
	size_t	pb;
	size_t	ra;
	size_t	rb;
	size_t	rra;
	size_t	rrb;
}	t_ctx;

size_t			n_op(t_ctx *c);
size_t			max(size_t a, size_t b);
size_t			min(size_t a, size_t b);

size_t			len_p(t_ctx *c);
size_t			len_a(t_ctx *c);
size_t			len_b(t_ctx *c);

t_elm			get_elm(size_t i, t_ctx *c);
t_elm			top_a(t_ctx *c);
t_elm			top_b(t_ctx *c);

t_elm			min_p(t_ctx *c);
t_elm			min_a(t_ctx *c);
t_elm			min_b(t_ctx *c);

t_elm			max_p(t_ctx *c);
t_elm			max_a(t_ctx *c);
t_elm			max_b(t_ctx *c);

// stack.c
t_stack			*init_stack(size_t cap);
void			deinit_stack(t_stack *s);
BOOL			contains(t_elm e, t_stack *s);

// stack_pair.c
t_ctx			*init_ctx(size_t cap);
void			deinit_ctx(t_ctx *m);
void			print_ctx(t_ctx *m);
void			dryprint(char *op, t_ctx *c);

// op_basic.c
// Returns 0 on success, -1 on error
void			swap(t_stack *s);
t_elm			pop(t_stack *s);
void			push(t_stack *s, t_elm e);
void			rotate(t_stack *s);
void			reverse_rotate(t_stack *s);

void			opflush(t_ctx *c);
void			opflush_r(t_ctx *c);
void			opflush_rr(t_ctx *c);
void			opflush_p(t_ctx *c);
void			opflush_s(t_ctx *c);

// op_s.c
void			sa(t_ctx *c);
void			sb(t_ctx *c);
void			ss(t_ctx *c);

// op_p.c
void			pa(t_ctx *c);
void			pb(t_ctx *c);

// op_r.c
void			ra(t_ctx *c);
void			rb(t_ctx *c);
void			rr(t_ctx *c);

// op_rr.c
void			rra(t_ctx *c);
void			rrb(t_ctx *c);
void			rrr(t_ctx *c);

void			insert_sort(t_ctx *c);
void			quick_sort(t_ctx *c, size_t low, size_t high);
#endif
