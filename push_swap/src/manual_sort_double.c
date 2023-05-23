/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sort_double.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:50:22 by dowon             #+#    #+#             */
/*   Updated: 2023/05/12 22:39:11 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/stack_ab.h"

static void	manual_sort_double_b(
	t_stack_ab *st, int (*cmp)(int, int), t_position dst)
{
	if (dst == B_TOP)
	{
		if (cmp(get_value(st, A_TOP), st->stack_a->top->next->value))
			st->sa(st, OPTIMIZE);
		st->pb(st, OPTIMIZE);
		st->pb(st, OPTIMIZE);
	}
	else if (dst == B_BOTTOM)
	{
		st->pb(st, OPTIMIZE);
		if (cmp(get_value(st, A_TOP), get_value(st, B_TOP)))
		{
			st->pb(st, OPTIMIZE);
			st->rb(st, OPTIMIZE);
		}
		else
		{
			st->rb(st, OPTIMIZE);
			st->pb(st, OPTIMIZE);
		}
		st->rb(st, OPTIMIZE);
	}
}

static void	manual_sort_double_a(
	t_stack_ab *st, int (*cmp)(int, int), t_position dst)
{
	if (dst == A_TOP)
	{
		if (!cmp(get_value(st, A_TOP), st->stack_a->top->next->value))
			st->sa(st, OPTIMIZE);
	}
	else if (dst == A_BOTTOM)
	{
		if (!cmp(get_value(st, A_TOP), st->stack_a->top->next->value))
			st->sa(st, OPTIMIZE);
		if (st->stack_a->size == 2)
			return ;
		st->ra(st, OPTIMIZE);
		st->ra(st, OPTIMIZE);
	}
}

void	manual_sort_double(t_stack_ab *st, int (*cmp)(int, int), t_position dst)
{
	if (dst == A_TOP || dst == A_BOTTOM)
		manual_sort_double_a(st, cmp, dst);
	else
		manual_sort_double_b(st, cmp, dst);
}
