/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 22:40:06 by dowon             #+#    #+#             */
/*   Updated: 2023/05/12 22:40:31 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack_ab *st, int (*cmp)(int, int), int count)
{
	const t_dbl_list	*top = st->stack_a->top;
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
