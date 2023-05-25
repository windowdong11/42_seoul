/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:41:39 by dowon             #+#    #+#             */
/*   Updated: 2023/05/25 19:08:17 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../smart_ptr.h"

static void	free_smartptr(t_smartptr *ptr_to_free)
{
	ptr_to_free->destructor(ptr_to_free->ptr);
	free(ptr_to_free);
}

void	smart_free_rest(t_smart_manager*const manager)
{
	t_smartptr					*iter_ptr;
	t_smartptr					*ptr_to_free;

	iter_ptr = manager->ptr.next;
	while (iter_ptr == NULL)
	{
		ptr_to_free = iter_ptr;
		iter_ptr = iter_ptr->next;
		free_smartptr(ptr_to_free);
	}
	iter_ptr->next = NULL;
}

void	*smart_malloc(
	t_smart_manager*const manager, size_t size, t_destructor destructor)
{
	void*const	ptr = malloc(size);
	t_smartptr	*last_smart_ptr;

	if (ptr == NULL)
		return (NULL);
	if (manager->ptr.next == NULL)
		last_smart_ptr = &manager->ptr;
	else
	{
		last_smart_ptr = manager->ptr.next;
		while (last_smart_ptr->next != NULL)
			last_smart_ptr = last_smart_ptr->next;
	}
	last_smart_ptr->next = malloc(sizeof(t_smartptr));
	if (last_smart_ptr->next == NULL)
		return (NULL);
	last_smart_ptr->next->ptr = ptr;
	last_smart_ptr->next->destructor = destructor;
	last_smart_ptr->next->next = NULL;
	return (ptr);
}

void	smart_free(t_smart_manager*const manager, void *ptr_to_free)
{
	t_smartptr	*prev_ptr;
	t_smartptr	*iter_ptr;

	prev_ptr = &manager->ptr;
	iter_ptr = manager->ptr.next;
	while (iter_ptr != NULL)
	{
		if (iter_ptr == ptr_to_free)
		{
			prev_ptr->next = iter_ptr->next;
			iter_ptr->destructor(iter_ptr);
			return ;
		}
		prev_ptr = iter_ptr;
		iter_ptr = iter_ptr->next;
	}
}

void	smart_exit(t_smart_manager*const manager, int exit_code)
{
	smart_free_rest(manager);
	exit(exit_code);
}
