/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:43:35 by susami            #+#    #+#             */
/*   Updated: 2022/05/30 11:12:36 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>

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
	int			out_size;

	char		conversion;
	int			width;
	int			precision;
	int			flags;

	char		sign_c;
	size_t		buf_len;

	int			fd;
}	t_fmt;

int		ft_vdprintf(int fd, const char *format, va_list ap);
int		ft_vprintf(const char *format, va_list ap);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_printf(const char *format, ...);
#endif
