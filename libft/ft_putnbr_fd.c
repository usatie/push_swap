/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 10:04:25 by susami            #+#    #+#             */
/*   Updated: 2022/04/08 10:32:38 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putabsnbr_fd(unsigned int n, int fd)
{
	char	c;

	if (n >= 10)
		putabsnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	ft_putchar_fd(c, fd);
}

// why this is ok when n is INT_MIN?
// putabsnbr_fd(-n, fd);
// Don't fully understand type conversion behaviours...
void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n <= -10)
			putabsnbr_fd(-(n / 10), fd);
		ft_putchar_fd((-(n % 10)) + '0', fd);
	}
	else
		putabsnbr_fd(n, fd);
}
