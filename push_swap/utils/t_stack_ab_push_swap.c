#include "stack_ab.h"
#include "../ft_printf/include/ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

void	sa(t_stack_ab *this)
{
	if (find_n_remove(this, SA, 1))
		return ;
	this->stack_a->swap(this->stack_a);
	this->command->push(this->command, new_t_dbl_list(SA));
}

void	sb(t_stack_ab *this)
{
	if (find_n_remove(this, SB, 1))
		return ;
	this->stack_b->swap(this->stack_b);
	this->command->push(this->command, new_t_dbl_list(SB));
}

void	ss(t_stack_ab *this)
{
	if (this->command->top->value == SS)
	{
		this->command->pop(this->command);
		return ;
	}
	sa(this);
	sb(this);
	this->command->pop(this->command);
	this->command->pop(this->command);
	this->command->push(this->command, new_t_dbl_list(SS));
}

void	pa(t_stack_ab *this)
{
	t_dbl_list*const	node = this->stack_b->pop(this->stack_b);

	this->stack_a->push(this->stack_a, node);
	this->command->push(this->command, new_t_dbl_list(PA));
}

void	pb(t_stack_ab *this)
{
	t_dbl_list*const	node = this->stack_a->pop(this->stack_a);

	this->stack_b->push(this->stack_b, node);
	this->command->push(this->command, new_t_dbl_list(PB));
}