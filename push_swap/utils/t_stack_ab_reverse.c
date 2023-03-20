#include "stack_ab.h"

void	rra(t_stack_ab *this)
{
	this->stack_a->rrotate(this->stack_a);
}

void	rrb(t_stack_ab *this)
{
	this->stack_b->rrotate(this->stack_b);
}

void	rrr(t_stack_ab *this)
{
	this->rra(this);
	this->rrb(this);
}