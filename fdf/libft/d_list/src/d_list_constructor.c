/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_list_constructor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:12:39 by dowon             #+#    #+#             */
/*   Updated: 2023/06/14 19:21:05 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../d_list.h"
#include <stdarg.h>

static void	init_d_list(t_d_list *this, void *value, t_destructor destructor)
{
	this->next = NULL;
	this->prev = NULL;
	this->value = value;
	this->destructor = destructor;
}

static void	delete_d_list(t_d_list *this)
{
	if (this->destructor != NULL && this->value != NULL)
		this->destructor(this->value);
	free(this);
}

void	smart_free_d_list_all(t_smart_manager *manager, t_d_list *node)
{
	t_d_list	*del_node;

	node = d_list_head(node);
	while (node != NULL)
	{
		del_node = node;
		node = node->next;
		smart_free(manager, del_node);
	}
}

t_d_list	*smart_new_d_list(
	t_smart_manager *manager, void *value, t_destructor destructor)
{
	t_d_list*const	new_node = smart_malloc(
			manager, sizeof(t_d_list), (t_destructor)delete_d_list);

	if (new_node == NULL)
		return (NULL);
	init_d_list(new_node, value, destructor);
	return (new_node);
}

t_d_list	*smart_new_d_list_va(
	t_smart_manager *manager, size_t n, t_destructor destructor, ...)
{
	va_list		args;
	t_d_list	*head;
	t_d_list	*last_node;
	t_d_list	*new_node;

	if (n == 0)
		return (NULL);
	va_start(args, destructor);
	new_node = smart_new_d_list(manager, va_arg(args, void *), destructor);
	if (new_node == NULL)
		return (NULL);
	head = new_node;
	while (--n > 0)
	{
		last_node = new_node;
		new_node = smart_new_d_list(manager, va_arg(args, void *), destructor);
		if (new_node == NULL)
		{
			smart_free_d_list_all(manager, head);
			return (NULL);
		}
		d_list_push_next(last_node, new_node);
	}
	va_end(args);
	return (head);
}
