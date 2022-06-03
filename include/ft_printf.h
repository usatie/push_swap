/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:43:35 by susami            #+#    #+#             */
/*   Updated: 2022/06/01 18:14:34 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>

// specifications
// #/0/-/ /+/.
# define ALT_FLG		01
# define PAD_ZERO_FLG	02
# define PAD_RIGHT_FLG	04
# define SIGN_SPACE_FLG	010
# define SIGN_PLUS_FLG	020
# define PRECISION_FLG	040

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
	size_t		buf_len;

	int			out_size;
	int			width;
	int			precision;
	int			flags;
	int			fd;
	char		conversion;
	char		sign_c;
	char		_PADDING[2];
}	t_fmt;

int		ft_vdprintf(int fd, const char *format, va_list ap);
int		ft_vprintf(const char *format, va_list ap);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_printf(const char *format, ...);
#endif
