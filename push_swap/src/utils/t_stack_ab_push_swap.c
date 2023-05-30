/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_ab_push_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:20:22 by dowon             #+#    #+#             */
/*   Updated: 2023/05/30 16:43:29 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_ab.h"

void	sa(t_stack_ab *this, int optimize)
{
	if (this->stack_a->size <= 1)
		return ;
	this->stack_a->swap(this->stack_a);
	if (optimize && remove_rev_cmd(this, cmd_sa, 1))
		return ;
	else if (optimize && this->command->top
		&& this->command->top->value == cmd_sb)
	{
		delete_t_dbl_list(this->command->pop(this->command));
		if (optimize && remove_rev_cmd(this, cmd_ss, 0))
			return ;
		this->command->push(this->command, new_t_dbl_list(cmd_ss));
		return ;
	}
	this->command->push(this->command, new_t_dbl_list(cmd_sa));
}

void	sb(t_stack_ab *this, int optimize)
{
	if (this->stack_b->size <= 1)
		return ;
	this->stack_b->swap(this->stack_b);
	if (optimize && remove_rev_cmd(this, cmd_sb, 1))
		return ;
	else if (optimize && this->command->top
		&& this->command->top->value == cmd_sa)
	{
		delete_t_dbl_list(this->command->pop(this->command));
		if (optimize && remove_rev_cmd(this, cmd_ss, 0))
			return ;
		this->command->push(this->command, new_t_dbl_list(cmd_ss));
		return ;
	}
	this->command->push(this->command, new_t_dbl_list(cmd_sb));
}

void	ss(t_stack_ab *this, int optimize)
{
	this->sa(this, 0);
	this->sb(this, 0);
	delete_t_dbl_list(this->command->pop(this->command));
	delete_t_dbl_list(this->command->pop(this->command));
	if (optimize && remove_rev_cmd(this, cmd_ss, 0))
		return ;
	this->command->push(this->command, new_t_dbl_list(cmd_ss));
}

void	pa(t_stack_ab *this, int optimize)
{
	t_dbl_list*const	node = this->stack_b->pop(this->stack_b);

	this->stack_a->push(this->stack_a, node);
	if (optimize && remove_rev_cmd(this, cmd_pa, 0))
		return ;
	this->command->push(this->command, new_t_dbl_list(cmd_pa));
}

void	pb(t_stack_ab *this, int optimize)
{
	t_dbl_list*const	node = this->stack_a->pop(this->stack_a);

	this->stack_b->push(this->stack_b, node);
	if (optimize && remove_rev_cmd(this, cmd_pb, 0))
		return ;
	this->command->push(this->command, new_t_dbl_list(cmd_pb));
}
