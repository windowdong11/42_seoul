/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:31:59 by dowon             #+#    #+#             */
/*   Updated: 2023/02/11 22:38:52 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

/*
(swap top, next) sa, sb, ss
(push a->b, b->a) pa, pb
(rotate a, b, ra & rb) ra, rb, rr
(reverse rotate a, b) rra, rrb, rrr (top to bottom)
*/
t_stack	*new_stack(void)
{
	t_stack *const	new_node = malloc(sizeof(t_stack));

	new_node->head.next = NULL;
	new_node->head.prev = NULL;
	new_node->head.value = 0;
	new_node->tail.next = NULL;
	new_node->tail.prev = NULL;
	new_node->tail.value = 0;
	new_node->size = 0;
	return (new_node);
}
