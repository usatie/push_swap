/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:47:05 by susami            #+#    #+#             */
/*   Updated: 2022/06/09 14:45:27 by susami           ###   ########.fr       */
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
		return (optimize_pa);
	else if (op == OP_PB)
		return (optimize_pb);
	else if (op == OP_SA)
		return (optimize_sa);
	else if (op == OP_SB)
		return (optimize_sb);
	else if (op == OP_SS)
		return (optimize_ss);
	else if (op == OP_RA)
		return (optimize_ra);
	else if (op == OP_RB)
		return (optimize_rb);
	else if (op == OP_RR)
		return (optimize_rr);
	else if (op == OP_RRA)
		return (optimize_rra);
	else if (op == OP_RRB)
		return (optimize_rrb);
	else if (op == OP_RRR)
		return (optimize_rrr);
	else
		return (NULL);
}
