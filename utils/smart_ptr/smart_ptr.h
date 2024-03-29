/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_ptr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:47:25 by dowon             #+#    #+#             */
/*   Updated: 2023/05/27 14:22:55 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMART_PTR_H
# define SMART_PTR_H

# include <stdlib.h>

typedef void	(*t_destructor)(void*);

/*
ptr : address of memory
destructor : function to free
*/
typedef struct s_smartptr
{
	void				*ptr;
	t_destructor		destructor;
	struct s_smartptr	*next;
}	t_smartptr;

typedef struct s_smartptr_manager
{
	t_smartptr	ptr;
}	t_smart_manager;

/* malloc and store to manager */
void	*smart_malloc(t_smart_manager*const manager,
			size_t size, t_destructor destructor);
/* malloc and store to manager */
void	smart_free(t_smart_manager*const manager, void *ptr_to_free);
void	smart_exit(t_smart_manager*const manager, int exit_code);

#endif