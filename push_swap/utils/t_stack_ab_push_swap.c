#include "stack_ab.h"
#include <stdlib.h>
#include <stdio.h>

void	sa(t_stack_ab *this, int optimize)
{
	this->stack_a->swap(this->stack_a);
	if (optimize && find_n_remove(this, SA, 1))
		return ;
	else if (optimize && this->command->top && this->command->top->value == SB)
	{
		this->command->pop(this->command);
		if (optimize && find_n_remove(this, SS, 0))
			return ;
		this->command->push(this->command, new_t_dbl_list(SS));
		return ;
	}
	this->command->push(this->command, new_t_dbl_list(SA));
}

void	sb(t_stack_ab *this, int optimize)
{
	this->stack_b->swap(this->stack_b);
	if (optimize && find_n_remove(this, SB, 1))
		return ;
	else if (optimize && this->command->top && this->command->top->value == SA)
	{
		this->command->pop(this->command);
		if (optimize && find_n_remove(this, SS, 0))
			return ;
		this->command->push(this->command, new_t_dbl_list(SS));
		return ;
	}
	this->command->push(this->command, new_t_dbl_list(SB));
}

void	ss(t_stack_ab *this, int optimize)
{
	this->sa(this, 0);
	this->sb(this, 0);
	this->command->pop(this->command);
	this->command->pop(this->command);
	if (optimize && find_n_remove(this, SS, 0))
		return ;
	this->command->push(this->command, new_t_dbl_list(SS));
}

void	pa(t_stack_ab *this, int optimize)
{
	t_dbl_list*const	node = this->stack_b->pop(this->stack_b);

	this->stack_a->push(this->stack_a, node);
	if (optimize && find_n_remove(this, PA, 0))
		return ;
	this->command->push(this->command, new_t_dbl_list(PA));
}

void	pb(t_stack_ab *this, int optimize)
{
	t_dbl_list*const	node = this->stack_a->pop(this->stack_a);

	this->stack_b->push(this->stack_b, node);
	if (optimize && find_n_remove(this, PB, 0))
		return ;
	this->command->push(this->command, new_t_dbl_list(PB));
}