/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:24:22 by dowon             #+#    #+#             */
/*   Updated: 2023/02/11 20:35:58 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	int				value;
}	t_list;

typedef struct s_stack
{
	struct s_list	head;
	struct s_list	tail;
	int				size;
}	t_stack;

t_stack	*new_stack(void);

#endif