/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:43:10 by susami            #+#    #+#             */
/*   Updated: 2022/05/30 18:50:56 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_argparse.h"
#include "ft_printf.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_machine	m;
	int			i;
	int			val;

	(void)argc;
	i = 1;
	while (**argv)
	{
		val = ft_argparse_int(argv[i], 0, "val");
		push(m.a, val);
		i++;
	}
	ft_printf("let's write push_swap!\n");
	return (EXIT_SUCCESS);
}
