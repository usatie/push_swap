/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susami <susami@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:47:05 by susami            #+#    #+#             */
/*   Updated: 2022/06/13 19:27:10 by susami           ###   ########.fr       */
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

t_op_function	op_func_from_name(const char *op)
{
	if (ft_strcmp(op, "pa") == 0)
		return (optimize_pa);
	else if (ft_strcmp(op, "pb") == 0)
		return (optimize_pb);
	else if (ft_strcmp(op, "sa") == 0)
		return (optimize_sa);
	else if (ft_strcmp(op, "sb") == 0)
		return (optimize_sb);
	else if (ft_strcmp(op, "ss") == 0)
		return (optimize_ss);
	else if (ft_strcmp(op, "ra") == 0)
		return (optimize_ra);
	else if (ft_strcmp(op, "rb") == 0)
		return (optimize_rb);
	else if (ft_strcmp(op, "rr") == 0)
		return (optimize_rr);
	else if (ft_strcmp(op, "rra") == 0)
		return (optimize_rra);
	else if (ft_strcmp(op, "rrb") == 0)
		return (optimize_rrb);
	else if (ft_strcmp(op, "rrr") == 0)
		return (optimize_rrr);
	else
		return (NULL);
}
