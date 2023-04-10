#include <stdlib.h>
#include "stack_ab.h"

void	delete_t_dbl_list(t_dbl_list *this)
{
	free(this);
}

void	delete_t_stack(t_stack *this)
{
	t_dbl_list*	head;
	t_dbl_list*	tmp;

	head = this->top;
	while(head != NULL)
	{
		tmp = head;
		head = head->next;
		tmp->destructor(tmp);
	}
	free(this);
}

void	delete_t_stack_ab(t_stack_ab *this)
{
	this->command->destructor(this->command);
	this->stack_a->destructor(this->stack_a);
	this->stack_b->destructor(this->stack_b);
	free(this);
}