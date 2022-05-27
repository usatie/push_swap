/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:34:58 by susami            #+#    #+#             */
/*   Updated: 2022/05/26 23:00:28 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

// Returns empty string if start is larger than length of s.
// like Python. (And it was difficult to cause crash like index out of range)
// s: not protected
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	new_len;
	char	*new;

	new_len = 1;
	if (start < ft_strlen(s))
		new_len = ft_strlen(s) - start + 1;
	if (new_len > len)
		new_len = len + 1;
	new = malloc(new_len);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < new_len - 1)
	{
		*(new + i) = *(s + start + i);
		i++;
	}
	*(new + i) = '\0';
	return (new);
}
