/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:34:31 by susami            #+#    #+#             */
/*   Updated: 2022/06/01 17:53:55 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <errno.h>
#include "libft.h"
#include "ft_printf.h"

void	parse_flags(t_fmt *fmt);
void	parse_width(t_fmt *fmt);
void	parse_precision(t_fmt *fmt);
void	parse_conversion_spec(t_fmt *fmt, va_list ap);

#define N_CONVERSIONS 9
void	printf_percent(t_fmt *fmt, va_list ap);
void	printf_c(t_fmt *fmt, va_list ap);
void	printf_s(t_fmt *fmt, va_list ap);
void	printf_p(t_fmt *fmt, va_list ap);
void	printf_di(t_fmt *fmt, va_list ap);
void	printf_u(t_fmt *fmt, va_list ap);
void	printf_x_lower(t_fmt *fmt, va_list ap);
void	printf_x_upper(t_fmt *fmt, va_list ap);

static const char	g_conversions[N_CONVERSIONS] = {
	'%',
	'c',
	's',
	'p',
	'd',
	'i',
	'u',
	'x',
	'X'
};
static	void		(*g_conversion_funcs[N_CONVERSIONS])(t_fmt *, va_list) = {
	printf_percent,
	printf_c,
	printf_s,
	printf_p,
	printf_di,
	printf_di,
	printf_u,
	printf_x_lower,
	printf_x_upper
};

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

void	parse_conversion_spec(t_fmt *fmt, va_list ap)
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
			g_conversion_funcs[i](fmt, ap);
			return ;
		}
		i++;
	}
}
