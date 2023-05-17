/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:08:49 by dowon             #+#    #+#             */
/*   Updated: 2023/05/17 19:21:34 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils/stack_ab.h"
#include "utils/compare.h"

void	merge_sort_a(t_stack_ab *st, int size, t_order order, t_position dst)
{
	int	sizes[4];

	sizes[A_TOP] = 0;
	sizes[A_BOTTOM] = size / 3;
	sizes[B_BOTTOM] = size / 3;
	sizes[B_TOP] = size - size / 3 * 2;
	merge_sort(st, sizes[B_BOTTOM], order, B_BOTTOM);
	merge_sort(st, sizes[B_TOP], !order, B_TOP);
	merge_sort(st, sizes[A_BOTTOM], order, A_BOTTOM);
	merge_to_dst(st, sizes, order, A_TOP);
	if (dst == A_BOTTOM && st->stack_a->size != size)
		while (size-- > 0)
			st->ra(st, OPTIMIZE);
}

void	merge_sort_b(t_stack_ab *st, int size, t_order order, t_position dst)
{
	int	sizes[4];

	sizes[B_TOP] = 0;
	sizes[A_BOTTOM] = size / 3;
	sizes[B_BOTTOM] = size / 3;
	sizes[A_TOP] = size - size / 3 * 2;
	merge_sort(st, sizes[A_BOTTOM], order, A_BOTTOM);
	merge_sort(st, sizes[B_BOTTOM], order, B_BOTTOM);
	merge_sort(st, sizes[A_TOP], !order, A_TOP);
	merge_to_dst(st, sizes, order, B_TOP);
	if (dst == B_BOTTOM && st->stack_b->size != size)
		while (size-- > 0)
			st->rb(st, OPTIMIZE);
}
int	handle_sorted(t_stack_ab *st, int size, t_order order, t_position dst);

void	merge_sort(t_stack_ab *st, int size, t_order order, t_position dst)
{
	if (handle_sorted(st, size, order, dst))
		return ;
	if (size <= 8)
		manual_sort(st, size, order, dst);
	else if (dst == A_TOP || dst == A_BOTTOM)
		merge_sort_a(st, size, order, dst);
	else
		merge_sort_b(st, size, order, dst);
}

void	merge_sort_2way(t_stack_ab *st, int size, t_order order, t_position dst)
{
	if (dst <= A_BOTTOM)
	{
		merge_sort(st, size / 2, !order, B_TOP);
		merge_sort(st, size - size / 2, order, A_BOTTOM);
		merge_to_dst(st, (int [4]){0, size - size / 2, size / 2, 0},
			order, A_TOP);
		if (dst == A_BOTTOM && st->stack_a->size != size)
			while (size-- > 0)
				st->ra(st, OPTIMIZE);
	}
	else
	{
		merge_sort(st, size / 2, order, B_BOTTOM);
		merge_sort(st, size - size / 2, !order, A_TOP);
		merge_to_dst(st, (int [4]){size - size / 2, 0, 0, size / 2},
			order, B_TOP);
		if (dst == B_BOTTOM && st->stack_b->size != size)
			while (size-- > 0)
				st->rb(st, OPTIMIZE);
	}
}

void	manual_sort(t_stack_ab *st, int size, t_order order, t_position dst)
{
	if (size == 1)
		manual_sort_single(st, dst);
	else if (size == 2)
		manual_sort_double(st, get_cmp(order), dst);
	else if (size == 3)
		manual_sort_triple(st, dst, get_cmp(order));
	else
		merge_sort_2way(st, size, order, dst);
}
