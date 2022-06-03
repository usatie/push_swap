/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:04:21 by susami            #+#    #+#             */
/*   Updated: 2022/06/03 14:04:35 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

size_t	min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
