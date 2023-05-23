/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_ab_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:20:18 by dowon             #+#    #+#             */
/*   Updated: 2023/05/23 19:41:06 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_ab.h"

void	rra(t_stack_ab *this, int optimize)
{
	if (this->stack_a->size <= 1)
		return ;
	this->stack_a->rrotate(this->stack_a);
	if (optimize && remove_rev_cmd(this, RRA, 1))
		return ;
	else if (optimize && this->command->top && this->command->top->value == RRB)
	{
		delete_t_dbl_list(this->command->pop(this->command));
		if (optimize && remove_rev_cmd(this, RRR, 0))
			return ;
		this->command->push(this->command, new_t_dbl_list(RRR));
		return ;
	}
	this->command->push(this->command, new_t_dbl_list(RRA));
}

void	rrb(t_stack_ab *this, int optimize)
{
	if (this->stack_b->size <= 1)
		return ;
	this->stack_b->rrotate(this->stack_b);
	if (optimize && remove_rev_cmd(this, RRB, 1))
		return ;
	else if (optimize && this->command->top && this->command->top->value == RRA)
	{
		delete_t_dbl_list(this->command->pop(this->command));
		if (optimize && remove_rev_cmd(this, RRR, 0))
			return ;
		this->command->push(this->command, new_t_dbl_list(RRR));
		return ;
	}
	this->command->push(this->command, new_t_dbl_list(RRB));
}

void	rrr(t_stack_ab *this, int optimize)
{
	if (this->stack_a->size == 0 && this->stack_b->size == 0)
		return ;
	this->rra(this, 0);
	this->rrb(this, 0);
	delete_t_dbl_list(this->command->pop(this->command));
	delete_t_dbl_list(this->command->pop(this->command));
	if (optimize && remove_rev_cmd(this, RRR, 0))
		return ;
	this->command->push(this->command, new_t_dbl_list(RRR));
}
