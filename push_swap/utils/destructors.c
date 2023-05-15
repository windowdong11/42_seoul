/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:32:28 by dowon             #+#    #+#             */
/*   Updated: 2023/05/15 18:38:28 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_ab.h"
#include <stdlib.h>

void	delete_t_dbl_list(t_dbl_list *this)
{
	free(this);
}

void	delete_t_stack(t_stack *this)
{
	t_dbl_list	*head;
	t_dbl_list	*tmp;

	if (this == NULL)
		return ;
	head = this->top;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		tmp->destructor(tmp);
	}
	free(this);
}

void	delete_t_stack_ab(t_stack_ab *this)
{
	if (this == NULL)
		return ;
	if (this->command)
		this->command->destructor(this->command);
	if (this->stack_a)
		this->stack_a->destructor(this->stack_a);
	if (this->stack_b)
		this->stack_b->destructor(this->stack_b);
	free(this);
}
