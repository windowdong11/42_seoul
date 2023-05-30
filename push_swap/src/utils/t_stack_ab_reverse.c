/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_ab_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:20:18 by dowon             #+#    #+#             */
/*   Updated: 2023/05/30 16:41:24 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_ab.h"

void	rra(t_stack_ab *this, int optimize)
{
	if (this->stack_a->size <= 1)
		return ;
	this->stack_a->rrotate(this->stack_a);
	if (optimize && remove_rev_cmd(this, cmd_rra, 1))
		return ;
	else if (optimize && this->command->top
		&& this->command->top->value == cmd_rrb)
	{
		delete_t_dbl_list(this->command->pop(this->command));
		if (optimize && remove_rev_cmd(this, cmd_rrr, 0))
			return ;
		this->command->push(this->command, new_t_dbl_list(cmd_rrr));
		return ;
	}
	this->command->push(this->command, new_t_dbl_list(cmd_rra));
}

void	rrb(t_stack_ab *this, int optimize)
{
	if (this->stack_b->size <= 1)
		return ;
	this->stack_b->rrotate(this->stack_b);
	if (optimize && remove_rev_cmd(this, cmd_rrb, 1))
		return ;
	else if (optimize && this->command->top
		&& this->command->top->value == cmd_rra)
	{
		delete_t_dbl_list(this->command->pop(this->command));
		if (optimize && remove_rev_cmd(this, cmd_rrr, 0))
			return ;
		this->command->push(this->command, new_t_dbl_list(cmd_rrr));
		return ;
	}
	this->command->push(this->command, new_t_dbl_list(cmd_rrb));
}

void	rrr(t_stack_ab *this, int optimize)
{
	if (this->stack_a->size == 0 && this->stack_b->size == 0)
		return ;
	this->rra(this, 0);
	this->rrb(this, 0);
	delete_t_dbl_list(this->command->pop(this->command));
	delete_t_dbl_list(this->command->pop(this->command));
	if (optimize && remove_rev_cmd(this, cmd_rrr, 0))
		return ;
	this->command->push(this->command, new_t_dbl_list(cmd_rrr));
}
