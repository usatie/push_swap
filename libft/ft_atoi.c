/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 08:52:28 by susami            #+#    #+#             */
/*   Updated: 2022/05/27 15:13:10 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

/*
DESCRIPTION
The atoi() function converts the initial portion of the string pointed to by str
to int representation.

It is equivalent to:

(int)strtol(str, (char **)NULL, 10);

While the atoi() function uses the current locale, the atoi_l() function may be
passed a locale directly. See xlocale(3) for more information.

IMPLEMENTATION NOTES
The atoi() and atoi_l() functions are thread-safe and async-cancel-safe.

The strtol() and strtol_l() functions are recommended instead of atoi() and
atoi_l() functions, especially in new code.

ERRORS
The function atoi() need not affect the value of errno on an error.
*/
static int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r' || c == ' ');
}

static int	is_cut(unsigned long current, unsigned long next)
{
	unsigned long	cutoff;
	unsigned long	cutlim;

	cutoff = LONG_MAX / 10;
	cutlim = LONG_MAX % 10;
	return (current > cutoff || (current == cutoff && next > cutlim));
}

// Original strtol takes endptr and base
// 	long strtol(const char *restrict str, char **restrict endptr, int base);
// This time, only implemented the pattern of (endptr: NULL, base: 10).
static long	ft_strtol(const char *str)
{
	unsigned long	ul_val;
	BOOL			isneg;

	while (ft_isspace(*str))
		str++;
	isneg = FALSE;
	if (*str == '-')
		isneg = TRUE;
	if (*str == '-' || *str == '+')
		str++;
	ul_val = 0;
	while (ft_isdigit(*str))
	{
		if (is_cut(ul_val, *str - '0'))
		{
			if (isneg)
				return (LONG_MIN);
			else
				return (LONG_MAX);
		}
		ul_val = ul_val * 10 + (*str++ - '0');
	}
	if (isneg)
		return (- (long)ul_val);
	return ((long)ul_val);
}

int	ft_atoi(const char *str)
{
	return ((int)ft_strtol(str));
}
