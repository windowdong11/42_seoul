/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sort_a_top.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:37:32 by dowon             #+#    #+#             */
/*   Updated: 2023/05/09 17:22:54 by dowon            ###   ########.fr       */
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

void	manual_sort_a_top(t_stack_ab *st, int (*cmp)(int, int))
{
	if (st->stack_a->size == 3)
	{
		manual_sort_a_top_empty(st, cmp);
		return ;
	}
	if (!cmp(get_value(st, A_TOP), st->stack_a->top->next->value))
		st->sa(st, OPTIMIZE);
	if (cmp(st->stack_a->top->next->value, st->stack_a->top->next->next->value))
		return ;
	st->pb(st, OPTIMIZE);
	st->sa(st, OPTIMIZE);
	st->pa(st, OPTIMIZE);
	if (!cmp(get_value(st, A_TOP), st->stack_a->top->next->value))
		st->sa(st, OPTIMIZE);
}

void	manual_sort_b_top(t_stack_ab *st, int (*cmp)(int, int))
{
	if (st->stack_a->size == 3)
	{
		manual_sort_a_top_empty(st, cmp);
		return ;
	}
	if (cmp(get_value(st, A_TOP), st->stack_a->top->next->value))
		st->sa(st, OPTIMIZE);
	st->pb(st, OPTIMIZE);
	if (cmp(get_value(st, A_TOP), st->stack_a->top->next->value))
		st->sa(st, OPTIMIZE);
	st->pb(st, OPTIMIZE);
	if (!cmp(get_value(st, B_TOP), st->stack_b->top->next->value))
		st->sb(st, OPTIMIZE);
	st->pb(st, OPTIMIZE);
}
