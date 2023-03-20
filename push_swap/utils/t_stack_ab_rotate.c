#include "stack_ab.h"

void	ra(t_stack_ab *this)
{
	this->stack_a->rotate(this->stack_a);
}

void	rb(t_stack_ab *this)
{
	this->stack_a->rotate(this->stack_a);
}

void	rr(t_stack_ab *this)
{
	this->ra(this);
	this->rb(this);
}