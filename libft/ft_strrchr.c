/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:14:20 by susami            #+#    #+#             */
/*   Updated: 2022/04/07 16:50:44 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	ch;

	str = (char *)s + ft_strlen(s);
	ch = c;
	while (1)
	{
		if (*str == ch)
			return (str);
		if (str == s)
			return (NULL);
		str--;
	}
}
