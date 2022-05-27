/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:34:31 by susami            #+#    #+#             */
/*   Updated: 2022/05/26 23:12:30 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <errno.h>
#include "libft.h"
#include "ft_printf.h"

/*	Overview of conversion specifiers
 
	start of conversion specifiers	: "%"
	flags							: "#-+ 0"
	width							: "20" "3"
	precision						: ".10" ".5"
	conversion specifier			: "%csdiupxX"

*/

void	parse_flags(t_fmt *fmt)
{
	char	c;

	while (1)
	{
		c = *(fmt->format);
		if (c == '#')
			fmt->flags |= ALT_FLG;
		else if (c == '-')
			fmt->flags |= PAD_RIGHT_FLG;
		else if (c == '+')
			fmt->flags |= SIGN_PLUS_FLG;
		else if (c == ' ')
			fmt->flags |= SIGN_SPACE_FLG;
		else
			break ;
		++(fmt->format);
	}
	if (c == '0')
	{
		fmt->flags |= PAD_ZERO_FLG;
		++(fmt->format);
	}
}

// "(x * 10 + y > INT_MAX)" is equivalent to "(x > (INT_MAX - y) / 10)"
// and no overflow/zero division unless y is less than INT_MAX
//
void	parse_width(t_fmt *fmt)
{
	char	c;

	c = *(fmt->format);
	while (ft_isdigit(c))
	{
		if (fmt->width > (INT_MAX - (c - '0')) / 10)
		{
			fmt->out_size = -1;
			errno = EOVERFLOW;
			return ;
		}
		fmt->width = fmt->width * 10 + (c - '0');
		++(fmt->format);
		c = *(fmt->format);
	}
}

void	parse_precision(t_fmt *fmt)
{
	char	c;

	c = *(fmt->format);
	if (c == '.')
	{
		fmt->flags |= PRECISION_FLG;
		fmt->precision = 0;
		(fmt->format)++;
		c = *(fmt->format);
		while (ft_isdigit(c))
		{
			fmt->precision = fmt->precision * 10 + (c - '0');
			++(fmt->format);
			c = *(fmt->format);
		}
	}
	if (fmt->precision < 0)
	{
		fmt->precision = 0;
		fmt->flags &= ~PRECISION_FLG;
	}
}

void	parse_conversion_spec(t_fmt *fmt)
{
	char	c;
	int		i;

	c = *(fmt->format);
	i = 0;
	while (i < N_CONVERSIONS)
	{
		if (c == g_conversions[i])
		{
			fmt->conversion = c;
			g_conversion_funcs[i](fmt);
			return ;
		}
		i++;
	}
}
