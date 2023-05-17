/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 22:40:06 by dowon             #+#    #+#             */
/*   Updated: 2023/05/17 19:21:11 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *st, int (*cmp)(int, int), int count)
{
	const t_dbl_list	*top = st->top;
	int					idx;

	idx = 1;
	while (idx < count)
	{
		if (!cmp(top->value, top->next->value))
			return (0);
		top = top->next;
		idx++;
	}
	return (1);
}

int	handle_sorted(t_stack_ab *st, int size, t_order order, t_position dst)
{
	int	idx;

	if (dst == A_TOP && is_sorted(st->stack_a, get_cmp(order), size))
		return (1);
	else if (((dst == A_BOTTOM || dst == B_BOTTOM)
		&& is_sorted(st->stack_a, get_cmp(order), size) && st->stack_a->size != size)
		|| (dst == B_TOP && is_sorted(st->stack_a, get_rcmp(order), size)))
	{
		idx = 0;
		while (idx++ < size)
			(get_merge_func(dst))(st, A_TOP);
		return (1);
	}
	else if (dst == B_BOTTOM && is_sorted(st->stack_a, get_rcmp(order), size))
	{
		idx = 0;
		while (idx++ < size)
			(get_merge_func(B_TOP))(st, A_TOP);
		if (st->stack_b->size != size)
		{
			idx = 0;
			while (idx++ < size)
				(get_merge_func(dst))(st, B_TOP);
		}
		return (1);
	}
	return (0);
}
