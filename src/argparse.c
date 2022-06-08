/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:08:00 by susami            #+#    #+#             */
/*   Updated: 2022/06/08 16:09:38 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <errno.h>
#include "push_swap.h"

static int	argparse_push(const char *arg, t_ctx *c)
{
	char	*endptr;
	long	res;

	if (*arg == '\0')
		return (-1);
	errno = 0;
	res = ft_strtol(arg, &endptr, 10);
	if (errno != 0 || *endptr != '\0' || res > INT_MAX || res < INT_MIN)
		return (-2);
	if (contains(res, c->a))
		return (-3);
	push(c->a, res);
	return (0);
}

t_ctx	*argparse_ctx(int argc, char **argv)
{
	t_ctx	*c;

	c = init_ctx(argc - 1);
	if (c == NULL)
		return (NULL);
	while (--argc > 0)
	{
		if (argparse_push(argv[argc], c) < 0)
		{
			deinit_ctx(c);
			return (NULL);
		}
	}
	return (c);
}
