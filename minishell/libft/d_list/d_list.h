/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_list.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 22:11:33 by dowon             #+#    #+#             */
/*   Updated: 2023/06/28 18:44:41 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef D_LIST_H
# define D_LIST_H

# include <smart_ptr.h>

typedef int				(*t_comp)(void*, void*);

typedef struct s_d_list
{
	struct s_d_list	*next;
	struct s_d_list	*prev;
	void			*value;
	t_destructor	destructor;
}						t_d_list;

/* new, delete */
t_d_list				*new_d_list(void *value, t_destructor destructor);
void					delete_all_d_list(t_d_list *head);
t_d_list				*smart_new_d_list(
							t_smart_manager *manager,
							void *value, t_destructor destructor);
t_d_list				*smart_new_next(
							t_smart_manager *manager, t_d_list *this,
							void *value, t_destructor destructor);
t_d_list				*smart_new_prev(
							t_smart_manager *manager, t_d_list *this,
							void *value, t_destructor destructor);
t_d_list				*smart_new_d_list_va(
							t_smart_manager *manager,
							size_t n, t_destructor destructor, ...);
void					smart_delete_d_list_all(t_smart_manager *manager,
							t_d_list *node);
/* push */
t_d_list				*d_list_push_next(t_d_list *this, t_d_list *new_node);
t_d_list				*d_list_push_prev(t_d_list *this, t_d_list *new_node);
t_d_list				*d_list_push_head(t_d_list *this, t_d_list *new_node);
t_d_list				*d_list_push_tail(t_d_list *this, t_d_list *new_node);
/* pop */
t_d_list				*d_list_pop_prev(t_d_list *this);
t_d_list				*d_list_pop_next(t_d_list *this);
t_d_list				*d_list_pop_head(t_d_list **this);
t_d_list				*d_list_pop_tail(t_d_list **this);
/* swap */
void					d_list_swap(t_d_list *this, t_d_list *node);
/* find */
t_d_list				*d_list_findptr(t_d_list *this, void *value);
t_d_list				*d_list_find(t_d_list *this, void *value, t_comp cmp);
t_d_list				*d_list_head(t_d_list *this);
t_d_list				*d_list_tail(t_d_list *this);

#endif