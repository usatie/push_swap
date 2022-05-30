/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:43:10 by susami            #+#    #+#             */
/*   Updated: 2022/05/30 21:52:42 by susami           ###   ########.fr       */
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
	int			i;

	m = init_machine(argc - 1);
	i = 1;
	while (i < argc)
	{
		argparse_push(argv[i], m);
		i++;
	}
	print_machine(m);
	deinit_machine(m);
	return (EXIT_SUCCESS);
}
