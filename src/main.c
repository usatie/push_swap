/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:43:10 by susami            #+#    #+#             */
/*   Updated: 2022/06/03 18:51:32 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "ft_error_functions.h"
#include "push_swap.h"

static void	argparse_push(const char *arg, t_stack_pair *p)
{
	char	*endptr;
	t_elm	new;

	if (*arg == '\0')
	{
		deinit_stack_pair(p);
		err_exit("null or empty string");
	}
	errno = 0;
	new = ft_strtol(arg, &endptr, 10);
	if (errno != 0)
	{
		deinit_stack_pair(p);
		err_exit("ft_strtol() failed\n	text: %s", arg);
	}
	if (*endptr != '\0')
	{
		deinit_stack_pair(p);
		err_exit("nonnumeric characters\n	text: %s", arg);
	}
	if (contains(new, p->a))
	{
		deinit_stack_pair(p);
		err_exit("duplicate values\n", arg);
	}
	push(p->a, new);
}

int	main(int argc, char **argv)
{
	t_stack_pair	*p;

	p = init_stack_pair(argc - 1);
	p->fd = STDOUT_FILENO;
	while (--argc > 0)
		argparse_push(argv[argc], p);
	insert_sort(p);
	if (VERBOSE)
		ft_dprintf(p->fd, "\n=====SORT RESULT=====\n\n");
	print_stack_pair(p);
	deinit_stack_pair(p);
	return (EXIT_SUCCESS);
}
