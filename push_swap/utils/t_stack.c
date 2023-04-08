/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:31:59 by dowon             #+#    #+#             */
/*   Updated: 2023/04/08 06:45:29 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_ab.h"
#include <stdlib.h>

void	t_stack_push(t_stack *this, t_dbl_list *new_node)
{
	if (new_node == NULL)
		return ;
	if (this->size == 0)
	{
		this->top = new_node;
		this->bottom = new_node;
	}
	else
	{
		this->top->push_prev(this->top, new_node);
		this->top = new_node;
	}
	this->size++;
}

void	t_stack_push_back(t_stack *this, t_dbl_list *new_node)
{
	if (new_node == NULL)
		return ;
	if (this->size == 0)
	{
		this->top = new_node;
		this->bottom = new_node;
	}
	else
	{
		this->bottom->push_next(this->bottom, new_node);
		this->bottom = new_node;
	}
	this->size++;
}

t_dbl_list*		t_stack_pop(t_stack *this)
{
	t_dbl_list*	node;

	node = NULL;
	if (this->size == 0)
		return (NULL);
	if (this->size == 1)
	{
		node = this->top;
		node->prev = NULL;
		node->next = NULL;
		this->top = NULL;
		this->bottom = NULL;
	}
	else
	{
		this->top = this->top->next;
		node = this->top->pop_prev(this->top);
	}
	this->size--;
	return (node);
}

void	t_stack_swap(t_stack *this)
{
	t_dbl_list*const	top_node = this->top;

	if (this->size <= 1)
		return ;
	if (this->size == 2)
	{
		top_node->swap(top_node, top_node->next);
		this->top = this->bottom;
		this->bottom = top_node;
	}
	else
	{
		top_node->swap(top_node, top_node->next);
		this->top = top_node->prev;
	}
}

void	t_stack_rotate(t_stack *this)
{
	t_dbl_list*	node;

	if (this->size <= 1)
		return ;
	if (this->size == 2)
		this->swap(this);
	else
	{
		this->top = this->top->next;
		node = this->top->pop_prev(this->top);
		this->bottom->push_next(this->bottom, node);
		this->bottom = node;
	}
}

void	t_stack_rrotate(t_stack *this)
{
	t_dbl_list*	node;

	if (this->size <= 1)
		return ;
	if (this->size == 2)
		this->swap(this);
	else
	{
		this->bottom = this->bottom->prev;
		node = this->bottom->pop_next(this->bottom);
		this->top->push_prev(this->top, node);
		this->top = node;
	}
}