/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:04:21 by susami            #+#    #+#             */
/*   Updated: 2022/06/09 16:04:29 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_sa(t_ctx *c)
{
	if (len_a(c) < 3)
		optimize_ra(c);
	else
	{
		opflush_r(c);
		opflush_rr(c);
		opflush_p(c);
		c->sa++;
		c->sa %= 2;
	}
}

void	optimize_sb(t_ctx *c)
{
	if (len_b(c) < 3)
		optimize_rb(c);
	else
	{
		opflush_r(c);
		opflush_rr(c);
		opflush_p(c);
		c->sb++;
		c->sb %= 2;
	}
}

void	optimize_ss(t_ctx *c)
{
	optimize_sa(c);
	optimize_sb(c);
}
