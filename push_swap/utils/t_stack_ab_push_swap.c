#include "stack_ab.h"
#include <stdlib.h>

void	sa(t_stack_ab *this)
{
	this->stack_a->swap(this->stack_a);
}

void	sb(t_stack_ab *this)
{
	this->stack_b->swap(this->stack_b);
}

void	ss(t_stack_ab *this)
{
	sa(this);
	sb(this);
}

void	pa(t_stack_ab *this)
{
	t_dbl_list*const	node = this->stack_b->pop(this->stack_b);

	this->stack_a->push(this->stack_a, node);
}

void	pb(t_stack_ab *this)
{
	t_dbl_list*const	node = this->stack_a->pop(this->stack_a);

	this->stack_b->push(this->stack_b, node);
}