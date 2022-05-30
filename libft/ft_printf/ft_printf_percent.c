/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:00:54 by susami            #+#    #+#             */
/*   Updated: 2022/05/30 11:07:21 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print(t_fmt *fmt, char *str, size_t len);

void	printf_percent(t_fmt *fmt, va_list ap)
{
	(void)ap;
	fmt->format++;
	print(fmt, "%", 1);
}
