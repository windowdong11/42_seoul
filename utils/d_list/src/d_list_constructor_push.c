/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_list_constructor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:12:39 by dowon             #+#    #+#             */
/*   Updated: 2023/05/25 17:03:41 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../d_list.h"
#include <stdarg.h>

t_d_list	*smart_new_next(
	t_smart_manager *manager, t_d_list *this,
	void *value, t_destructor destructor)
{
	t_d_list*const	new_node = smart_new_d_list(manager, value, destructor);

	if (new_node == NULL)
		return (NULL);
	return (d_list_push_next(this, new_node));
}

t_d_list	*smart_new_prev(
	t_smart_manager *manager, t_d_list *this,
	void *value, t_destructor destructor)
{
	t_d_list*const	new_node = smart_new_d_list(manager, value, destructor);

	if (new_node == NULL)
		return (NULL);
	return (d_list_push_prev(this, new_node));
}

t_d_list	*smart_new_push_head(
	t_smart_manager *manager, t_d_list *this,
	void *value, t_destructor destructor)
{
	t_d_list*const	new_node = smart_new_d_list(manager, value, destructor);

	if (new_node == NULL)
		return (NULL);
	return (d_list_push_head(this, new_node));
}

t_d_list	*smart_new_push_tail(
	t_smart_manager *manager, t_d_list *this,
	void *value, t_destructor destructor)
{
	t_d_list*const	new_node = smart_new_d_list(manager, value, destructor);

	if (new_node == NULL)
		return (NULL);
	return (d_list_push_tail(this, new_node));
}
