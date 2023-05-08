/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sort_a_top.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:37:32 by dowon             #+#    #+#             */
/*   Updated: 2023/05/07 17:35:34 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/stack_ab.h"

void	manual_sort_a_top_empty(t_stack_ab *st, int (*cmp)(int, int))
{
	if (cmp(st->stack_a->top->value, st->stack_a->top->next->value))
	{
		if (cmp(st->stack_a->top->next->value,
				st->stack_a->top->next->next->value))
			return ;
		st->rra(st, OPTIMIZE);
		if (!cmp(st->stack_a->top->value, st->stack_a->top->next->value))
			st->sa(st, 1);
	}
	else
	{
		if (cmp(st->stack_a->top->value, st->stack_a->top->next->next->value))
			st->sa(st, 1);
		else if (cmp(st->stack_a->top->next->value,
				st->stack_a->top->next->next->value))
			st->ra(st, OPTIMIZE);
		else
		{
			st->ra(st, OPTIMIZE);
			st->sa(st, 1);
		}
	}
}

static void	sort_a_top_by_order(t_stack_ab *st, int order)
{
	if (order == 132 || order == 231)
	{
		st->ra(st, OPTIMIZE);
		st->sa(st, 1);
		st->rra(st, OPTIMIZE);
		if (order == 231)
			st->sa(st, 1);
	}
	else if (order == 312)
	{
		st->sa(st, 1);
		st->ra(st, OPTIMIZE);
		st->sa(st, 1);
		st->rra(st, OPTIMIZE);
	}
	else if (order == 321)
	{
		st->sa(st, 1);
		st->ra(st, OPTIMIZE);
		st->sa(st, 1);
		st->rra(st, OPTIMIZE);
		st->sa(st, 1);
	}
}

void	manual_sort_a_top(t_stack_ab *st, int (*cmp)(int, int))
{
	if (st->stack_a->size == 3)
	{
		manual_sort_a_top_empty(st, cmp);
		return ;
	}
	if (cmp(get_value(st, A_TOP), st->stack_a->top->next->value))
	{
		if (cmp(st->stack_a->top->next->value,
				st->stack_a->top->next->next->value))
			return ;
		if (cmp(st->stack_a->top->value, st->stack_a->top->next->next->value))
			sort_a_top_by_order(st, 132);
		else
			sort_a_top_by_order(st, 231);
	}
	else
	{
		if (cmp(st->stack_a->top->value, st->stack_a->top->next->next->value))
			st->sa(st, 1);
		else if (cmp(st->stack_a->top->next->value,
				st->stack_a->top->next->next->value))
			sort_a_top_by_order(st, 312);
		else
			sort_a_top_by_order(st, 321);
	}
}
