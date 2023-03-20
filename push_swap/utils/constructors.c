#include "stack_ab.h"
#include <stdlib.h>

t_dbl_list	*new_t_dbl_list(int value)
{
	t_dbl_list*const	node = malloc(sizeof(t_dbl_list));

	if (node == NULL)
		return (NULL);
	node->destructor = delete_t_dbl_list;
	node->next = NULL;
	node->prev = NULL;
	node->value = value;
	node->push_front = t_dbl_list_push_front;
	node->push_back = t_dbl_list_push_back;
	node->pop_front = t_dbl_list_pop_front;
	node->pop_back = t_dbl_list_pop_back;
	node->swap = t_dbl_list_swap;
	return (node);
}

t_stack		*new_t_stack(void)
{
	t_stack*const	stack = malloc(sizeof(t_stack));

	if (stack == NULL)
		return (NULL);
	stack->destructor = delete_t_stack;
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	stack->pop = t_stack_pop;
	stack->push = t_stack_push;
	stack->swap = t_stack_swap;
	stack->rotate = t_stack_rotate;
	stack->rrotate = t_stack_rrotate;
	return (stack);
}

t_stack_ab	*new_t_stack_ab(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_ab*const 	stack_ab = malloc(sizeof(t_stack_ab));

	if (stack_ab == NULL)
		return (NULL);
	stack_ab->destructor = delete_t_stack_ab;
	stack_ab->stack_a = stack_a;
	stack_ab->stack_b = stack_b;
	stack_ab->sa = sa;
	stack_ab->sb = sb;
	stack_ab->ss = ss;
	stack_ab->pa = pa;
	stack_ab->pb = pb;
	stack_ab->ra = ra;
	stack_ab->rb = rb;
	stack_ab->rr = rr;
	stack_ab->rra = rra;
	stack_ab->rrb = rrb;
	stack_ab->rrr = rrr;
	return (stack_ab);
}