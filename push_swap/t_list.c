/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:37:12 by dowon             #+#    #+#             */
/*   Updated: 2023/02/11 22:39:05 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_list	*new_list(int value)
{
	t_list *const	new_node = malloc(sizeof(t_list));

	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->value = value;
	return (new_node);
}

t_list	*append_list(t_list *prev_node, t_list *cur_node)
{
	cur_node->prev = prev_node;
	cur_node->next = prev_node->next;
	if (prev_node->next != NULL)
		prev_node->next->prev = cur_node;
	prev_node->next = cur_node;
	return (cur_node);
}
