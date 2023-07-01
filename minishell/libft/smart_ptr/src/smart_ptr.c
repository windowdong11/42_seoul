/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:41:39 by dowon             #+#    #+#             */
/*   Updated: 2023/06/27 18:12:44 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../smart_ptr.h"

/*
@brief Call destructor for handled pointer and free smart pointer
@param ptr_to_free 
*/
static void	free_smartptr(t_smartptr *ptr_to_free)
{
	if (ptr_to_free->destructor && ptr_to_free->ptr)
		ptr_to_free->destructor(ptr_to_free->ptr);
	free(ptr_to_free);
}

void	smart_clean_all(t_smart_manager*const manager)
{
	t_smartptr	*ptr_to_free;

	while (manager->head.next != NULL)
	{
		ptr_to_free = manager->head.next;
		manager->head.next = manager->head.next->next;
		free_smartptr(ptr_to_free);
	}
	smart_init(manager);
}

void	*smart_malloc(
	t_smart_manager*const manager, size_t size, t_destructor destructor)
{
	void*const			ptr = malloc(size);
	t_smartptr*const	new_ptr = malloc(sizeof(t_smartptr));

	if (ptr == NULL || new_ptr == NULL)
	{
		free(ptr);
		free(new_ptr);
		return (NULL);
	}
	new_ptr->ptr = ptr;
	new_ptr->destructor = destructor;
	new_ptr->next = manager->head.next;
	manager->head.next = new_ptr;
	return (ptr);
}

void	smart_free(t_smart_manager*const manager, void *ptr_to_free)
{
	t_smartptr	*prev_ptr;
	t_smartptr	*iter_ptr;

	if (ptr_to_free == NULL)
		return ;
	prev_ptr = &manager->head;
	iter_ptr = manager->head.next;
	while (iter_ptr != NULL)
	{
		if (iter_ptr == ptr_to_free)
		{
			prev_ptr->next = iter_ptr->next;
			free_smartptr(iter_ptr);
			return ;
		}
		prev_ptr = iter_ptr;
		iter_ptr = iter_ptr->next;
	}
}

void	smart_exit(t_smart_manager*const manager, int exit_code)
{
	smart_clean_all(manager);
	exit(exit_code);
}
