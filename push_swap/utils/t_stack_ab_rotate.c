#include "stack_ab.h"

void	ra(t_stack_ab *this, int optimize)
{
	this->stack_a->rotate(this->stack_a);
	if (optimize && find_n_remove(this, RA, 1))
		return ;
	else if (optimize && this->command->top && this->command->top->value == RB)
	{
		this->command->pop(this->command);
		if (optimize && find_n_remove(this, RR, 0))
			return ;
		this->command->push(this->command, new_t_dbl_list(RR));
		return ;
	}
	this->command->push(this->command, new_t_dbl_list(RA));
}

void	rb(t_stack_ab *this, int optimize)
{
	this->stack_a->rotate(this->stack_b);
	if (optimize && find_n_remove(this, RB, 1))
		return ;
	else if (optimize && this->command->top && this->command->top->value == RA)
	{
		this->command->pop(this->command);
		if (optimize && find_n_remove(this, RR, 0))
			return ;
		this->command->push(this->command, new_t_dbl_list(RR));
		return ;
	}
	this->command->push(this->command, new_t_dbl_list(RB));
}

void	rr(t_stack_ab *this, int optimize)
{
	this->ra(this, 0);
	this->rb(this, 0);
	this->command->pop(this->command);
	this->command->pop(this->command);
	if (optimize && find_n_remove(this, RR, 0))
		return ;
	this->command->push(this->command, new_t_dbl_list(RR));
}