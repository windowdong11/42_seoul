/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sort_triple.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:37:32 by dowon             #+#    #+#             */
/*   Updated: 2023/05/17 14:19:27 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/stack_ab.h"

static void	manual_sort_a_top_empty(t_stack_ab *st, int (*cmp)(int, int))
{
	if (cmp(get_value(st, A_TOP), st->stack_a->top->next->value))
	{
		if (cmp(st->stack_a->top->next->value,
				st->stack_a->top->next->next->value))
			return ;
		st->rra(st, OPTIMIZE);
	}
	if (!cmp(get_value(st, A_TOP), st->stack_a->top->next->next->value))
		st->ra(st, 1);
	if (!cmp(get_value(st, A_TOP), st->stack_a->top->next->value))
		st->sa(st, 1);
}

static void	manual_sort_triple_a_top(t_stack_ab *st, int (*cmp)(int, int))
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

static void	manual_sort_b_top_empty(t_stack_ab *st, int (*cmp)(int, int))
{
	if (cmp(get_value(st, B_TOP), st->stack_b->top->next->value))
	{
		if (cmp(st->stack_b->top->next->value,
				st->stack_b->top->next->next->value))
			return ;
		st->rrb(st, OPTIMIZE);
	}
	if (!cmp(get_value(st, B_TOP), st->stack_b->top->next->next->value))
		st->rb(st, OPTIMIZE);
	if (!cmp(get_value(st, B_TOP), st->stack_b->top->next->value))
		st->sb(st, OPTIMIZE);
}

static void	manual_sort_triple_b_top(t_stack_ab *st, int (*cmp)(int, int))
{
	if (st->stack_b->size == 0)
	{
		st->pb(st, OPTIMIZE);
		st->pb(st, OPTIMIZE);
		st->pb(st, OPTIMIZE);
		manual_sort_b_top_empty(st, cmp);
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

void	manual_sort_triple(t_stack_ab *st, t_position dst, int (*cmp)(int, int))
{
	int	size;

	size = 3;
	if (dst == A_TOP || dst == A_BOTTOM)
	{
		manual_sort_triple_a_top(st, cmp);
		if (dst == A_BOTTOM && st->stack_a->size != 3)
			while (size-- > 0)
				st->ra(st, OPTIMIZE);
	}
	else
	{
		manual_sort_triple_b_top(st, cmp);
		if (dst == B_BOTTOM && st->stack_b->size != 3)
			while (size-- > 0)
				st->rb(st, OPTIMIZE);
	}
}
