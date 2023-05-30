/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_ab_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:20:14 by dowon             #+#    #+#             */
/*   Updated: 2023/05/30 16:41:00 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_ab.h"

void	ra(t_stack_ab *this, int optimize)
{
	if (this->stack_a->size <= 1)
		return ;
	this->stack_a->rotate(this->stack_a);
	if (optimize && remove_rev_cmd(this, cmd_ra, 1))
		return ;
	else if (optimize && this->command->top
		&& this->command->top->value == cmd_rb)
	{
		delete_t_dbl_list(this->command->pop(this->command));
		if (optimize && remove_rev_cmd(this, cmd_rr, 0))
			return ;
		this->command->push(this->command, new_t_dbl_list(cmd_rr));
		return ;
	}
	this->command->push(this->command, new_t_dbl_list(cmd_ra));
}

void	rb(t_stack_ab *this, int optimize)
{
	if (this->stack_b->size <= 1)
		return ;
	this->stack_a->rotate(this->stack_b);
	if (optimize && remove_rev_cmd(this, cmd_rb, 1))
		return ;
	else if (optimize && this->command->top
		&& this->command->top->value == cmd_ra)
	{
		delete_t_dbl_list(this->command->pop(this->command));
		if (optimize && remove_rev_cmd(this, cmd_rr, 0))
			return ;
		this->command->push(this->command, new_t_dbl_list(cmd_rr));
		return ;
	}
	this->command->push(this->command, new_t_dbl_list(cmd_rb));
}

void	rr(t_stack_ab *this, int optimize)
{
	if (this->stack_a->size == 0 && this->stack_b->size == 0)
		return ;
	this->ra(this, 0);
	this->rb(this, 0);
	delete_t_dbl_list(this->command->pop(this->command));
	delete_t_dbl_list(this->command->pop(this->command));
	if (optimize && remove_rev_cmd(this, cmd_rr, 0))
		return ;
	this->command->push(this->command, new_t_dbl_list(cmd_rr));
}
