/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_list_constructor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:28:22 by dowon             #+#    #+#             */
/*   Updated: 2023/06/27 20:32:41 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "d_list_constructor.h"

void	init_d_list(t_d_list *this, void *value, t_destructor destructor)
{
	this->next = NULL;
	this->prev = NULL;
	this->value = value;
	this->destructor = destructor;
}

void	delete_d_list(t_d_list *this)
{
	if (this->destructor != NULL && this->value != NULL)
		this->destructor(this->value);
	free(this);
}

t_d_list	*new_d_list(void *value, t_destructor destructor)
{
	t_d_list*const	lst = malloc(sizeof(t_d_list));

	init_d_list(lst, value, destructor);
	return (lst);
}

void	delete_all_d_list(t_d_list *head)
{
	t_d_list	*del_node;

	while (head != NULL)
	{
		del_node = head;
		head = head->next;
		delete_d_list(del_node);
	}
}
