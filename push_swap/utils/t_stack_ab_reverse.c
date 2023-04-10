#include "stack_ab.h"

void	rra(t_stack_ab *this, int optimize)
{
	if (optimize && find_n_remove(this, RA, 1))
		return ;
	this->stack_a->rrotate(this->stack_a);
	this->command->push(this->command, new_t_dbl_list(RRA));
}

void	rrb(t_stack_ab *this, int optimize)
{
	if (optimize && find_n_remove(this, RB, 1))
		return ;
	this->stack_b->rrotate(this->stack_b);
	this->command->push(this->command, new_t_dbl_list(RRB));
}

void	rrr(t_stack_ab *this, int optimize)
{
	if (optimize && this->command->top->value == RR)
	{
		this->command->pop(this->command);
		return ;
	}
	this->rra(this, 0);
	this->rrb(this, 0);
	this->command->pop(this->command);
	this->command->pop(this->command);
	this->command->push(this->command, new_t_dbl_list(RRR));
}