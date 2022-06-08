/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:43:10 by susami            #+#    #+#             */
/*   Updated: 2022/06/08 15:27:41 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "ft_error_functions.h"
#include "push_swap.h"

char	*op_name(t_elm op)
{
	if (op == OP_PA)
		return ("pa");
	else if (op == OP_PB)
		return ("pb");
	else if (op == OP_SA)
		return ("sa");
	else if (op == OP_SB)
		return ("sb");
	else if (op == OP_SS)
		return ("ss");
	else if (op == OP_RA)
		return ("ra");
	else if (op == OP_RB)
		return ("rb");
	else if (op == OP_RR)
		return ("rr");
	else if (op == OP_RRA)
		return ("rra");
	else if (op == OP_RRB)
		return ("rrb");
	else if (op == OP_RRR)
		return ("rrr");
	else
		return ("unknown op");
}

t_op_function	op_func(t_elm op)
{
	if (op == OP_PA)
		return (pa);
	else if (op == OP_PB)
		return (pb);
	else if (op == OP_SA)
		return (sa);
	else if (op == OP_SB)
		return (sb);
	else if (op == OP_SS)
		return (ss);
	else if (op == OP_RA)
		return (ra);
	else if (op == OP_RB)
		return (rb);
	else if (op == OP_RR)
		return (rr);
	else if (op == OP_RRA)
		return (rra);
	else if (op == OP_RRB)
		return (rrb);
	else if (op == OP_RRR)
		return (rrr);
	else
		return (NULL);
}

static int	argparse_push(const char *arg, t_ctx *c)
{
	char	*endptr;
	long	res;

	if (*arg == '\0')
	{
		deinit_ctx(c);
		return (-1);
	}
	errno = 0;
	res = ft_strtol(arg, &endptr, 10);
	if (errno != 0 || *endptr != '\0' || res > INT_MAX || res < INT_MIN)
	{
		deinit_ctx(c);
		return (-2);
	}
	if (contains(res, c->a))
	{
		deinit_ctx(c);
		return (-3);
	}
	push(c->a, res);
	return (0);
}

static t_ctx	*argparse_ctx(int argc, char **argv)
{
	t_ctx	*c;

	c = init_ctx(argc - 1);
	if (c == NULL)
		return (NULL);
	while (--argc > 0)
		if (argparse_push(argv[argc], c) < 0)
			return (NULL);
	return (c);
}

t_stack	*stack_dup(t_stack *src)
{
	t_stack	*dup;

	dup = init_stack(src->cap);
	if (dup == NULL)
		return (NULL);
	dup->len = src->len;
	ft_memcpy(dup->arr, src->arr, sizeof(t_elm) * src->len);
	return (dup);
}

static t_ctx	*optimize(int argc, char **argv, t_ctx *c)
{
	t_stack	*ops;
	size_t	i;

	ft_debug_printf("\n=====[OPTIMIZE START] (before = %d)=====\n\n", n_op(c));
	while (1)
	{
		ops = stack_dup(c->ops);
		if (ops == NULL)
			return (NULL);
		deinit_ctx(c);
		c = argparse_ctx(argc, argv);
		if (c == NULL)
			return (NULL);
		i = 0;
		while (i < ops->len)
			op_func(ops->arr[i++])(c);
		opflush(c);
		if (ops->len == n_op(c))
			break ;
	}
	ft_debug_printf("\n=====[OPTIMIZE END] (after = %d)=====\n\n", n_op(c));
	return (c);
}

static void	print_ops(t_ctx *c)
{
	size_t	i;
	t_stack	*ops;

	ops = c->ops;
	i = 0;
	while (i < ops->len)
	{
		ft_printf("%s\n", op_name(ops->arr[i]));
		i++;
	}
}

// returns op count for quick sort
static t_ctx	*quicksort(int argc, char **argv)
{
	t_ctx	*c;

	c = argparse_ctx(argc, argv);
	if (c == NULL)
		return (NULL);
	ft_debug_printf("\n=====INITIAL STACKS=====\n");
	print_ctx(c);
	ft_debug_printf("========================\n\n");
	if (argc >= 2)
		quick_sort(c, 0, argc - 2);
	ft_debug_printf("\n=====[QUICK SORT RESULT](result=%d)=====\n\n", n_op(c));
	print_ctx(c);
	c = optimize(argc, argv, c);
	return (c);
}

// returns op count for insert sort
static t_ctx	*insertsort(int argc, char **argv)
{
	t_ctx	*c;

	c = argparse_ctx(argc, argv);
	if (c == NULL)
		return (NULL);
	ft_debug_printf("\n=====INITIAL STACKS=====\n");
	print_ctx(c);
	ft_debug_printf("========================\n\n");
	if (argc >= 2)
		insert_sort(c);
	ft_debug_printf("\n=====[INSERT SORT RESULT] (result=%d)=====\n\n", n_op(c));
	print_ctx(c);
	c = optimize(argc, argv, c);
	return (c);
}

int	main(int argc, char **argv)
{
	t_ctx	*c1;
	t_ctx	*c2;

	c1 = quicksort(argc, argv);
	c2 = insertsort(argc, argv);
	if (c1 == NULL || c2 == NULL)
	{
		deinit_ctx(c1);
		deinit_ctx(c2);
		err_exit("Error\n");
	}
	if (n_op(c1) < n_op(c2))
		print_ops(c1);
	else
		print_ops(c2);
	deinit_ctx(c1);
	deinit_ctx(c2);
	return (EXIT_SUCCESS);
}
