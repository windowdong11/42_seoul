/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:37:12 by dowon             #+#    #+#             */
/*   Updated: 2023/03/20 14:31:32 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_ab.h"
#include <stdlib.h>

void	t_dbl_list_push_front(t_dbl_list*this, t_dbl_list *new_node)
{
	t_dbl_list*const	prev_node = this->prev;

	new_node->prev = prev_node;
	new_node->next = this;
	if (prev_node != NULL)
		prev_node->next = new_node;
	this->prev = new_node;
}

void	t_dbl_list_push_back(t_dbl_list*this, t_dbl_list *new_node)
{
	t_dbl_list*const	next_node = this->next;

	new_node->prev = this;
	new_node->next = next_node;
	if (next_node != NULL)
		next_node->prev = new_node;
	this->next = new_node;
}

t_dbl_list	*t_dbl_list_pop_front(t_dbl_list*this)
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

t_dbl_list	*t_dbl_list_pop_back(t_dbl_list*this)
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

void	t_dbl_list_swap(t_dbl_list *this, t_dbl_list *node)
{
	t_dbl_list*const	this_next = this->next;
	t_dbl_list*const	this_prev = this->prev;
	t_dbl_list*const	node_next = node->next;
	t_dbl_list*const	node_prev = node->prev;

	this->next = node_next;
	this->prev = node_prev;
	node->next = this_next;
	node->prev = this_prev;
	if (node_next)
		node_next->prev = this;
	if (node_prev)
		node_prev->next = this;
	if (this_next)
		this_next->prev = node;
	if (this_prev)
		this_prev->next = this;
}