/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:15:24 by dowon             #+#    #+#             */
/*   Updated: 2023/05/12 21:19:49 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./stack_ab.h"

void	t_stack_rotate(t_stack *this)
{
	t_dbl_list	*node;

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
	t_dbl_list	*node;

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
