/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_list_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:37:12 by dowon             #+#    #+#             */
/*   Updated: 2023/05/25 16:49:45 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../d_list.h"

t_d_list	*d_list_pop_head(t_d_list **this)
{
	t_d_list	*head;

	if (*this == NULL)
		return (NULL);
	head = d_list_head(*this);
	if (head->next == NULL)
		*this = NULL;
	else
		d_list_pop_prev(head->next);
	return (head);
}

t_d_list	*d_list_pop_tail(t_d_list **this)
{
	t_d_list	*tail;

	if (*this == NULL)
		return (NULL);
	tail = d_list_tail(*this);
	if (tail->prev == NULL)
		*this = NULL;
	else
		d_list_pop_next(tail->prev);
	return (tail);
}

t_d_list	*d_list_pop_prev(t_d_list *this)
{
	t_d_list*const	prev_node = this->prev;

	if (prev_node == NULL)
		return (NULL);
	if (prev_node->prev)
		prev_node->prev->next = this;
	this->prev = prev_node->prev;
	prev_node->prev = NULL;
	prev_node->next = NULL;
	return (prev_node);
}

t_d_list	*d_list_pop_next(t_d_list *this)
{
	t_d_list*const	next_node = this->next;

	if (next_node == NULL)
		return (NULL);
	if (next_node->next)
		next_node->next->prev = this;
	this->next = next_node->next;
	next_node->prev = NULL;
	next_node->next = NULL;
	return (next_node);
}
