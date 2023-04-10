#include "stack_ab.h"

void	ra(t_stack_ab *this)
{
	if (find_n_remove(this, RRA, 1))
		return ;
	this->stack_a->rotate(this->stack_a);
	this->command->push(this->command, new_t_dbl_list(RA));
}

void	rb(t_stack_ab *this)
{
	if (find_n_remove(this, RRB, 1))
		return ;
	this->stack_a->rotate(this->stack_b);
	this->command->push(this->command, new_t_dbl_list(RB));
}

void	rr(t_stack_ab *this)
{
	if (this->command->top->value == RRR)
	{
		this->command->pop(this->command);
		return ;
	}
	this->ra(this);
	this->rb(this);
	this->command->pop(this->command);
	this->command->pop(this->command);
	this->command->push(this->command, new_t_dbl_list(RR));
}