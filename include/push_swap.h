/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:51:01 by susami            #+#    #+#             */
/*   Updated: 2022/06/09 18:27:54 by susami           ###   ########.fr       */
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

typedef int		t_elm;

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

typedef void	(*t_op_function)(t_ctx *);

char			*op_name(t_elm op);
t_op_function	op_func(t_elm op);

size_t			n_op(t_ctx *c);
size_t			max(size_t a, size_t b);
size_t			min(size_t a, size_t b);

size_t			len_p(t_ctx *c);
size_t			len_a(t_ctx *c);
size_t			len_b(t_ctx *c);

t_elm			get_elm(size_t i, t_ctx *c);
t_elm			top_a(t_ctx *c);
t_elm			top_b(t_ctx *c);

// stack.c
t_stack			*stack_init(size_t cap);
void			stack_deinit(t_stack *s);
BOOL			stack_contains(t_elm e, t_stack *s);
t_stack			*stack_dup(t_stack *src);

// ctx.c
t_ctx			*ctx_init(size_t cap);
void			ctx_deinit(t_ctx *c);
void			ctx_append(t_elm op, t_ctx *c);
void			ctx_deinit_n(t_ctx **c, size_t n);
void			ctx_print_best(t_ctx **c, size_t n);

// argparse.c
t_ctx			*argparse_ctx(int argc, char **argv);

// print.c
void			debug_print_ctx(t_ctx *m);
void			print_ops(t_ctx *c);

// op_basic.c
// Returns 0 on success, -1 on error
void			swap(t_stack *s);
t_elm			pop(t_stack *s);
void			push(t_stack *s, t_elm e);
void			rotate(t_stack *s);
void			reverse_rotate(t_stack *s);

// op_s.c
// op_p.c
// op_r.c
// op_rr.c
void			sa(t_ctx *c);
void			sb(t_ctx *c);
void			ss(t_ctx *c);
void			pa(t_ctx *c);
void			pb(t_ctx *c);
void			ra(t_ctx *c);
void			rb(t_ctx *c);
void			rr(t_ctx *c);
void			rra(t_ctx *c);
void			rrb(t_ctx *c);
void			rrr(t_ctx *c);

// optimize.c
t_ctx			*optimize(int argc, char **argv, t_ctx *c);

// opflush.c
void			opflush(t_ctx *c);
void			opflush_r(t_ctx *c);
void			opflush_rr(t_ctx *c);
void			opflush_p(t_ctx *c);
void			opflush_s(t_ctx *c);

void			optimize_sa(t_ctx *c);
void			optimize_sb(t_ctx *c);
void			optimize_ss(t_ctx *c);
void			optimize_pa(t_ctx *c);
void			optimize_pb(t_ctx *c);
void			optimize_ra(t_ctx *c);
void			optimize_rb(t_ctx *c);
void			optimize_rr(t_ctx *c);
void			optimize_rra(t_ctx *c);
void			optimize_rrb(t_ctx *c);
void			optimize_rrr(t_ctx *c);

void			selection_sort(t_ctx *c);
void			quick_sort(t_ctx *c, size_t low, size_t high);
void			insert_sort(t_ctx *c);
void			radix_sort(t_ctx *c);
#endif
