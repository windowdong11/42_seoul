/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dbl_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:37:12 by dowon             #+#    #+#             */
/*   Updated: 2023/05/23 22:15:34 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_ab.h"
#include <stdlib.h>

void	dbl_list_push_next(t_dbl_list *this, t_dbl_list *new_node)
{
	t_dbl_list*const	next_node = this->next;

	new_node->prev = this;
	new_node->next = next_node;
	if (next_node != NULL)
		next_node->prev = new_node;
	this->next = new_node;
}

void	dbl_list_push_prev(t_dbl_list *this, t_dbl_list *new_node)
{
	t_dbl_list*const	prev_node = this->prev;

	new_node->prev = prev_node;
	new_node->next = this;
	if (prev_node != NULL)
		prev_node->next = new_node;
	this->prev = new_node;
}

t_dbl_list	*dbl_list_pop_prev(t_dbl_list *this)
{
	t_dbl_list*const	prev_node = this->prev;

	if (prev_node == NULL)
		return (NULL);
	if (prev_node->prev)
		prev_node->prev->next = this;
	this->prev = prev_node->prev;
	prev_node->prev = NULL;
	prev_node->next = NULL;
	return (prev_node);
}

t_dbl_list	*dbl_list_pop_next(t_dbl_list *this)
{
	t_dbl_list*const	next_node = this->next;

	if (next_node == NULL)
		return (NULL);
	if (next_node->next)
		next_node->next->prev = this;
	this->next = next_node->next;
	next_node->prev = NULL;
	next_node->next = NULL;
	return (next_node);
}

t_dbl_list	*dbl_list_find(t_dbl_list *this, int value)
{
	t_dbl_list	*node;

	node = this;
	while (node != NULL)
	{
		if (node->value == value)
			return (node);
		node = node->next;
	}
	return (NULL);
}
