/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:43:10 by susami            #+#    #+#             */
/*   Updated: 2022/05/31 01:24:07 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <errno.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "ft_error_functions.h"
#include "push_swap.h"

static void	argparse_push(const char *arg, t_machine *m)
{
	char	*endptr;
	t_elm	new;

	if (*arg == '\0')
	{
		deinit_machine(m);
		err_exit("null or empty string");
	}
	errno = 0;
	new = ft_strtol(arg, &endptr, 10);
	if (errno != 0)
	{
		deinit_machine(m);
		err_exit("ft_strtol() failed\n	text: %s", arg);
	}
	if (*endptr != '\0')
	{
		deinit_machine(m);
		err_exit("nonnumeric characters\n	text: %s", arg);
	}
	if (contains(new, m->a))
	{
		deinit_machine(m);
		err_exit("duplicate values\n", arg);
	}
	push(m->a, new);
}

int	main(int argc, char **argv)
{
	t_machine	*m;
	size_t		i;

	m = init_machine(argc - 1);
	i = argc;
	while (--i > 0)
	{
		argparse_push(argv[i], m);
	}
	insert_sort(m->a, m->b);
	//print_machine(m);
	deinit_machine(m);
	return (EXIT_SUCCESS);
}
