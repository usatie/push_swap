/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:43:10 by susami            #+#    #+#             */
/*   Updated: 2022/06/08 14:47:23 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "ft_error_functions.h"
#include "push_swap.h"

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

static t_ctx	*optimize(int argc, char **argv, t_ctx *c)
{
	t_stack	*ops;
	size_t	result;
	size_t	i;

	result = n_op(c);
	ft_debug_printf("\n=====[OPTIMIZE START] (before = %d)=====\n\n", result);
	while (1)
	{
		ops = init_stack(c->ops->len);
		ops->len = c->ops->len;
		ft_memcpy(ops->arr, c->ops->arr, sizeof(t_elm) * c->ops->len);
		deinit_ctx(c);
		c = argparse_ctx(argc, argv);
		if (c == NULL)
			err_exit("Error\n");
		i = 0;
		while (i < ops->len)
		{
			if (ops->arr[i] == OP_PA)
				pa(c);
			else if (ops->arr[i] == OP_PB)
				pb(c);
			else if (ops->arr[i] == OP_SA)
				sa(c);
			else if (ops->arr[i] == OP_SB)
				sb(c);
			else if (ops->arr[i] == OP_SS)
				ss(c);
			else if (ops->arr[i] == OP_RA)
				ra(c);
			else if (ops->arr[i] == OP_RB)
				rb(c);
			else if (ops->arr[i] == OP_RR)
				rr(c);
			else if (ops->arr[i] == OP_RRA)
				rra(c);
			else if (ops->arr[i] == OP_RRB)
				rrb(c);
			else if (ops->arr[i] == OP_RRR)
				rrr(c);
			i++;
		}
		opflush(c);
		if (result > n_op(c))
			result = n_op(c);
		else
			break ;
	}
	ft_debug_printf("\n=====[OPTIMIZE END] (after = %d)=====\n\n", result);
	print_ctx(c);
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
		if (ops->arr[i] == OP_PA)
			ft_printf("pa\n");
		else if (ops->arr[i] == OP_PB)
			ft_printf("pb\n");
		else if (ops->arr[i] == OP_SA)
			ft_printf("sa\n");
		else if (ops->arr[i] == OP_SB)
			ft_printf("sb\n");
		else if (ops->arr[i] == OP_SS)
			ft_printf("ss\n");
		else if (ops->arr[i] == OP_RA)
			ft_printf("ra\n");
		else if (ops->arr[i] == OP_RB)
			ft_printf("rb\n");
		else if (ops->arr[i] == OP_RR)
			ft_printf("rr\n");
		else if (ops->arr[i] == OP_RRA)
			ft_printf("rra\n");
		else if (ops->arr[i] == OP_RRB)
			ft_printf("rrb\n");
		else if (ops->arr[i] == OP_RRR)
			ft_printf("rrr\n");
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
