/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_list_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:28:35 by dowon             #+#    #+#             */
/*   Updated: 2023/05/25 13:42:28 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../d_list.h"

static void	d_list_swap_next(t_d_list *this)
{
	t_d_list*const	node = this->next;
	t_d_list*const	this_prev = this->prev;
	t_d_list*const	node_next = node->next;

	this->prev = node;
	this->next = node_next;
	node->prev = this_prev;
	node->next = this;
	if (node_next)
		node_next->prev = this;
	if (this_prev)
		this_prev->next = node;
}

static void	d_list_swap_prev(t_d_list *this)
{
	t_d_list*const	node = this->prev;
	t_d_list*const	this_next = this->next;
	t_d_list*const	node_prev = node->prev;

	this->next = node;
	this->prev = node_prev;
	node->next = this_next;
	node->prev = this;
	if (this_next)
		this_next->prev = node;
	if (node_prev)
		node_prev->next = this;
}

void	d_list_swap(t_d_list *this, t_d_list *node)
{
	t_d_list*const	this_next = this->next;
	t_d_list*const	this_prev = this->prev;
	t_d_list*const	node_next = node->next;
	t_d_list*const	node_prev = node->prev;

	if (this->next == node)
		d_list_swap_next(this);
	else if (this->prev == node)
		d_list_swap_prev(this);
	else
	{
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
			this_prev->next = node;
	}
}
