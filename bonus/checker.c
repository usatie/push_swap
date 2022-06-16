/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:03:30 by susami            #+#    #+#             */
/*   Updated: 2022/06/16 15:01:43 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include "ft_error_functions.h"
#include "ft_printf.h"
#include "push_swap.h"
#include "get_next_line.h"

static BOOL	is_sorted(t_ctx *c)
{
	size_t	i;
	size_t	last;

	if (len_p(c) == 0)
		return (TRUE);
	if (len_b(c) > 0)
		return (FALSE);
	last = get_elm(0, c);
	i = 1;
	while (i < len_p(c))
	{
		if (get_elm(i, c) <= (t_elm)last)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_ctx			*c;
	char			*line;
	t_op_function	op;

	if (argc == 1)
		return (0);
	c = argparse_ctx(argc, argv);
	if (c == NULL)
		err_exit("Error\n");
	debug_print_ctx(c);
	errno = 0;
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (*line)
		{
			op = op_func_from_name(line);
			if (op == NULL)
				err_exit("Error\n", line);
			op(c);
		}
		else
			err_exit("Error\n", line);
		line = get_next_line(STDIN_FILENO);
	}
	opflush(c);
	if (is_sorted(c))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
