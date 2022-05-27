/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:04:10 by susami            #+#    #+#             */
/*   Updated: 2022/05/26 23:12:50 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <errno.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

// If overflow happens, set -1 to out_size and set EOVERFLOW to errno.
// MEMO: libc's printf does not set errno when len > INT_MAX.
static void	print_bytes(t_fmt *fmt, char *str, size_t len)
{
	if (fmt->out_size < 0)
		return ;
	else if (len > (size_t)INT_MAX - fmt->out_size)
	{
		errno = EOVERFLOW;
		fmt->out_size = -1;
	}
	else
		fmt->out_size += write(STDOUT_FILENO, str, len);
}

// print len size str with padding
void	print(t_fmt *fmt, char *str, size_t len)
{
	int		pad_len;
	char	pad_c;

	if (fmt->sign_c && fmt->width > 0)
		fmt->width--;
	pad_c = ' ';
	if (fmt->flags & PAD_ZERO_FLG)
		pad_c = '0';
	if ((fmt->flags & PRECISION_FLG) && ft_strchr("diouixX", fmt->conversion))
		pad_c = ' ';
	if (fmt->sign_c && pad_c == '0')
		print_bytes(fmt, &fmt->sign_c, 1);
	pad_len = 0;
	if ((size_t)fmt->width > len)
		pad_len = fmt->width - len;
	if (!(fmt->flags & PAD_RIGHT_FLG))
		while (pad_len--)
			print_bytes(fmt, &pad_c, 1);
	if (fmt->sign_c && pad_c == ' ')
		print_bytes(fmt, &fmt->sign_c, 1);
	print_bytes(fmt, str, len);
	if (fmt->flags & PAD_RIGHT_FLG)
		while (pad_len--)
			print_bytes(fmt, &pad_c, 1);
}

void	print_non_conversion_bytes(t_fmt *fmt)
{
	size_t	len;
	char	*s;

	s = (char *)fmt->format;
	len = 0;
	while (*(fmt->format) != '\0' && *(fmt->format) != '%')
	{
		len++;
		(fmt->format)++;
	}
	if (len > INT_MAX)
	{
		errno = EOVERFLOW;
		fmt->out_size = -1;
	}
	print_bytes(fmt, s, len);
}

int	ft_printf(const char *format, ...)
{
	t_fmt	fmt;

	if (format == NULL)
	{
		errno = EINVAL;
		return (-1);
	}
	fmt_init(&fmt, format);
	va_start(fmt.ap, format);
	while (fmt.out_size > -1 && *(fmt.format))
	{
		fmt_clear_spec(&fmt);
		if (*(fmt.format) == '%')
		{
			(fmt.format)++;
			parse_flags(&fmt);
			parse_width(&fmt);
			parse_precision(&fmt);
			parse_conversion_spec(&fmt);
		}
		else
			print_non_conversion_bytes(&fmt);
	}
	va_end(fmt.ap);
	return (fmt.out_size);
}
