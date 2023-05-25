/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_list_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:37:12 by dowon             #+#    #+#             */
/*   Updated: 2023/05/25 17:02:04 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../d_list.h"

t_d_list	*d_list_push_next(t_d_list *this, t_d_list *new_node)
{
	t_d_list*const	next_node = this->next;

	new_node->prev = this;
	new_node->next = next_node;
	if (next_node != NULL)
		next_node->prev = new_node;
	this->next = new_node;
	return (new_node);
}

t_d_list	*d_list_push_prev(t_d_list *this, t_d_list *new_node)
{
	t_d_list*const	prev_node = this->prev;

	new_node->prev = prev_node;
	new_node->next = this;
	if (prev_node != NULL)
		prev_node->next = new_node;
	this->prev = new_node;
	return (new_node);
}

t_d_list	*d_list_push_head(t_d_list *this, t_d_list *new_node)
{
	d_list_push_prev(d_list_head(this), new_node);
	return (new_node);
}


t_d_list	*d_list_push_tail(t_d_list *this, t_d_list *new_node)
{
	d_list_push_next(d_list_tail(this), new_node);
	return (new_node);
}
