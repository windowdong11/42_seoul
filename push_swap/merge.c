/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 22:48:10 by dowon             #+#    #+#             */
/*   Updated: 2023/05/12 22:48:40 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils/stack_ab.h"
#include "./push_swap.h"

void	merge_to_dst(
	t_stack_ab *st, int sizes[4], t_order order, t_position dst)
{
	const t_compare		cmp = get_rcmp(order);
	t_position			src;

	while (sizes[A_TOP] + sizes[A_BOTTOM] + sizes[B_TOP] + sizes[B_BOTTOM] > 0)
	{
		src = POS_NULL;
		if (sizes[A_TOP] && src == POS_NULL)
			src = A_TOP;
		if (sizes[A_BOTTOM] && (src == POS_NULL
				|| cmp(get_value(st, A_BOTTOM), get_value(st, src))))
			src = A_BOTTOM;
		if (sizes[B_TOP] && (src == POS_NULL
				|| cmp(get_value(st, B_TOP), get_value(st, src))))
			src = B_TOP;
		if (sizes[B_BOTTOM] && (src == POS_NULL
				|| cmp(get_value(st, B_BOTTOM), get_value(st, src))))
			src = B_BOTTOM;
		(get_merge_func(dst))(st, src);
		sizes[src]--;
	}
}