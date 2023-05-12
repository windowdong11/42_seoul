/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_ab_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:20:14 by dowon             #+#    #+#             */
/*   Updated: 2023/05/12 22:22:10 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_ab.h"

void	ra(t_stack_ab *this, int optimize)
{
	if (this->stack_a->size <= 1)
		return ;
	this->stack_a->rotate(this->stack_a);
	if (optimize && remove_rev_cmd(this, RA, 1))
		return ;
	else if (optimize && this->command->top && this->command->top->value == RB)
	{
		this->command->pop(this->command);
		if (optimize && remove_rev_cmd(this, RR, 0))
			return ;
		this->command->push(this->command, new_t_dbl_list(RR));
		return ;
	}
	this->command->push(this->command, new_t_dbl_list(RA));
}

void	rb(t_stack_ab *this, int optimize)
{
	if (this->stack_b->size <= 1)
		return ;
	this->stack_a->rotate(this->stack_b);
	if (optimize && remove_rev_cmd(this, RB, 1))
		return ;
	else if (optimize && this->command->top && this->command->top->value == RA)
	{
		this->command->pop(this->command);
		if (optimize && remove_rev_cmd(this, RR, 0))
			return ;
		this->command->push(this->command, new_t_dbl_list(RR));
		return ;
	}
	this->command->push(this->command, new_t_dbl_list(RB));
}

void	rr(t_stack_ab *this, int optimize)
{
	if (this->stack_a->size == 0 && this->stack_b->size == 0)
		return ;
	this->ra(this, 0);
	this->rb(this, 0);
	this->command->pop(this->command);
	this->command->pop(this->command);
	if (optimize && remove_rev_cmd(this, RR, 0))
		return ;
	this->command->push(this->command, new_t_dbl_list(RR));
}
