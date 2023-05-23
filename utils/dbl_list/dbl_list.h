/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 22:11:33 by dowon             #+#    #+#             */
/*   Updated: 2023/05/23 22:15:33 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DBL_LIST_H
# define DBL_LIST_H


typedef struct s_dbl_list
{
	struct s_dbl_list	*next;
	struct s_dbl_list	*prev;
	int					value;
}						t_dbl_list;

t_dbl_list				*new_t_dbl_list(int value);
void					delete_t_dbl_list(t_dbl_list *this);
void					dbl_list_push_next(
							t_dbl_list *this, t_dbl_list *new_node);
void					dbl_list_push_prev(
							t_dbl_list *this, t_dbl_list *new_node);
t_dbl_list				*dbl_list_pop_prev(t_dbl_list *this);
t_dbl_list				*dbl_list_pop_next(t_dbl_list *this);
void					t_dbl_list_swap(t_dbl_list *this, t_dbl_list *node);
t_dbl_list				*dbl_list_find(t_dbl_list *this, int value);

#endif