/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:45:58 by susami            #+#    #+#             */
/*   Updated: 2022/06/06 16:40:01 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#ifdef DEBUG
# define DEBUG 1
#else
# define DEBUG 0
#endif

int	ft_debug_vdprintf(int fd, const char *format, va_list ap)
{
	if (DEBUG)
		return (ft_vdprintf(fd, format, ap));
	else
		return (0);
}

int	ft_debug_vprintf(const char *format, va_list ap)
{
	if (DEBUG)
		return (ft_vprintf(format, ap));
	else
		return (0);
}

int	ft_debug_dprintf(int fd, const char *format, ...)
{
	int		ret;
	va_list	ap;

	if (DEBUG)
	{
		va_start(ap, format);
		ret = ft_vdprintf(fd, format, ap);
		va_end(ap);
		return (ret);
	}
	else
		return (0);
}

int	ft_debug_printf(const char *format, ...)
{
	int		ret;
	va_list	ap;

	if (DEBUG)
	{
		va_start(ap, format);
		ret = ft_vprintf(format, ap);
		va_end(ap);
		return (ret);
	}
	else
		return (0);
}
