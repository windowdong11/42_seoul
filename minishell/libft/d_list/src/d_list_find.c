/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_list_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:19:07 by dowon             #+#    #+#             */
/*   Updated: 2023/05/25 16:45:31 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../d_list.h"

t_d_list	*d_list_findptr(t_d_list *this, void *value)
{
	t_d_list	*node;

	node = this;
	while (node != NULL)
	{
		if (node->value == value)
			return (node);
		node = node->next;
	}
	return (NULL);
}

t_d_list	*d_list_find(t_d_list *this, void *value, t_comp cmp)
{
	t_d_list	*node;

	node = this;
	while (node != NULL)
	{
		if (cmp(node->value, value))
			return (node);
		node = node->next;
	}
	return (NULL);
}

t_d_list	*d_list_head(t_d_list *this)
{
	t_d_list	*node;

	if (this == NULL)
		return (NULL);
	node = this;
	while (node->prev != NULL)
		node = node->prev;
	return (node);
}

t_d_list	*d_list_tail(t_d_list *this)
{
	t_d_list	*node;

	if (this == NULL)
		return (NULL);
	node = this;
	while (node->next != NULL)
		node = node->next;
	return (node);
}
