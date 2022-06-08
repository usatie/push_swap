/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:47:05 by susami            #+#    #+#             */
/*   Updated: 2022/06/08 15:57:28 by susami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*op_name(t_elm op)
{
	if (op == OP_PA)
		return ("pa");
	else if (op == OP_PB)
		return ("pb");
	else if (op == OP_SA)
		return ("sa");
	else if (op == OP_SB)
		return ("sb");
	else if (op == OP_SS)
		return ("ss");
	else if (op == OP_RA)
		return ("ra");
	else if (op == OP_RB)
		return ("rb");
	else if (op == OP_RR)
		return ("rr");
	else if (op == OP_RRA)
		return ("rra");
	else if (op == OP_RRB)
		return ("rrb");
	else if (op == OP_RRR)
		return ("rrr");
	else
		return ("unknown op");
}

t_op_function	op_func(t_elm op)
{
	if (op == OP_PA)
		return (pa);
	else if (op == OP_PB)
		return (pb);
	else if (op == OP_SA)
		return (sa);
	else if (op == OP_SB)
		return (sb);
	else if (op == OP_SS)
		return (ss);
	else if (op == OP_RA)
		return (ra);
	else if (op == OP_RB)
		return (rb);
	else if (op == OP_RR)
		return (rr);
	else if (op == OP_RRA)
		return (rra);
	else if (op == OP_RRB)
		return (rrb);
	else if (op == OP_RRR)
		return (rrr);
	else
		return (NULL);
}
