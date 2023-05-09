#include "stack_ab.h"

void	rra(t_stack_ab *this, int optimize)
{
	if (this->stack_a->size <= 1)
		return ;
	this->stack_a->rrotate(this->stack_a);
	if (optimize && find_n_remove(this, RRA, 1))
		return ;
	else if (optimize && this->command->top && this->command->top->value == RRB)
	{
		this->command->pop(this->command);
		if (optimize && find_n_remove(this, RRR, 0))
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
	if (optimize && find_n_remove(this, RRB, 1))
		return ;
	else if (optimize && this->command->top && this->command->top->value == RRA)
	{
		this->command->pop(this->command);
		if (optimize && find_n_remove(this, RRR, 0))
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
	this->command->pop(this->command);
	this->command->pop(this->command);
	if (optimize && find_n_remove(this, RRR, 0))
		return ;
	this->command->push(this->command, new_t_dbl_list(RRR));
}
