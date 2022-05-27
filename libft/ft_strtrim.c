/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:48:18 by susami            #+#    #+#             */
/*   Updated: 2022/05/26 23:00:53 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_strtrim_len(char const *s1, char const *set)
{
	size_t	len;
	char	*p;

	len = ft_strlen(s1);
	p = (char *)s1;
	s1 = s1 + len - 1;
	while (len > 0 && ft_strchr(set, *s1) != NULL)
	{
		s1--;
		len--;
	}
	s1 = p;
	while (len > 0 && ft_strchr(set, *s1) != NULL)
	{
		s1++;
		len--;
	}
	return (len);
}

// s1: not protected
// set: not protected
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*p;
	char	*s;

	len = ft_strtrim_len(s1, set);
	s = malloc(len + 1);
	p = s;
	if (s == NULL)
		return (NULL);
	while (len > 0 && ft_strchr(set, *s1) != NULL)
		s1++;
	while (len-- > 0)
		*s++ = *s1++;
	*s = '\0';
	return (p);
}
