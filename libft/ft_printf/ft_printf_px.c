/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_px.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 21:57:06 by susami            #+#    #+#             */
/*   Updated: 2022/05/26 22:31:04 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_p(t_fmt *fmt)
{
	unsigned long long	p;

	(fmt->format)++;
	p = va_arg(fmt->ap, unsigned long long);
	puthex(p, 0, "0x", fmt);
}

void	printf_x_lower(t_fmt *fmt)
{
	unsigned int	x;
	char			*prefix;

	(fmt->format)++;
	x = va_arg(fmt->ap, unsigned int);
	prefix = "";
	if ((fmt->flags & ALT_FLG) && x > 0)
		prefix = "0x";
	puthex(x, 0, prefix, fmt);
}

void	printf_x_upper(t_fmt *fmt)
{
	unsigned int	x;
	char			*prefix;

	(fmt->format)++;
	x = va_arg(fmt->ap, unsigned int);
	prefix = "";
	if ((fmt->flags & ALT_FLG) && x > 0)
		prefix = "0X";
	puthex(x, 16, prefix, fmt);
}
