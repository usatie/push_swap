/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:43:35 by susami            #+#    #+#             */
/*   Updated: 2022/05/26 23:11:43 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
//# include <unistd.h>
//# include <errno.h>
//# include <limits.h>

// specifications
// #/0/-/ /+/.
# define ALT_FLG		0b00000001
# define PAD_ZERO_FLG	0b00000010
# define PAD_RIGHT_FLG	0b00000100
# define SIGN_SPACE_FLG	0b00001000
# define SIGN_PLUS_FLG	0b00010000
# define PRECISION_FLG	0b00100000

// GENERAL properties:
// 	- format
// 	- ap
// 	- out_size
//
// conversion specifiers properties:
//	- conversion
// 	- width
// 	- precision
// 	- flags
//
// 	- sign_c
typedef struct s_fmt
{
	const char	*format;
	va_list		ap;
	int			out_size;

	char		conversion;
	int			width;
	int			precision;
	int			flags;

	char		sign_c;
	size_t		buf_len;
}	t_fmt;

// fmt.c
void		fmt_init(t_fmt *fmt, const char *format);
void		fmt_clear_spec(t_fmt *fmt);

// ft_printf.c
// static void	print_bytes(t_fmt *fmt, char *str, size_t len)
// static void	parse_conversion_spec(t_fmt *fmt)
void		print(t_fmt *fmt, char *str, size_t len);
int			ft_printf(const char *format, ...);

// spec_parser.c
void		parse_flags(t_fmt *fmt);
void		parse_width(t_fmt *fmt);
void		parse_precision(t_fmt *fmt);
void		parse_conversion_spec(t_fmt *fmt);

// printf_cs.c
void		printf_c(t_fmt *fmt);
void		printf_s(t_fmt *fmt);

// printf_px.c
void		printf_p(t_fmt *fmt);
void		printf_x_lower(t_fmt *fmt);
void		printf_x_upper(t_fmt *fmt);

// puthex.c
// static void	set_buf_hex(char *buf, unsigned long long n,
// 					int capitals, t_fmt *fmt);
// static void	set_buf_precision(char *buf, t_fmt *fmt)
void		puthex(unsigned long long n, int capitals,
				char *prefix, t_fmt *fmt);

// printf_diu.c
// static void		puti(int n);
// static void	putui(unsigned int n);
void		printf_di(t_fmt *fmt);
void		printf_u(t_fmt *fmt);

// printf_percent.c
void		printf_percent(t_fmt *fmt);

// conversions
# define N_CONVERSIONS 9

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
static	void		(*g_conversion_funcs[N_CONVERSIONS])(t_fmt *) = {
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
#endif
