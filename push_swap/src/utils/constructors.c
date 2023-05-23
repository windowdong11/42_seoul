/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:32:44 by dowon             #+#    #+#             */
/*   Updated: 2023/05/23 22:16:19 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_ab.h"
#include "push_swap.h"
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
	node->push_next = dbl_list_push_next;
	node->push_prev = dbl_list_push_prev;
	node->pop_prev = dbl_list_pop_prev;
	node->pop_next = dbl_list_pop_next;
	node->swap = t_dbl_list_swap;
	return (node);
}

t_stack	*new_t_stack(void)
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
	stack->push_back = t_stack_push_back;
	stack->swap = t_stack_swap;
	stack->rotate = t_stack_rotate;
	stack->rrotate = t_stack_rrotate;
	return (stack);
}

static void	bind_method_stack_ab(t_stack_ab *stack_ab)
{
	stack_ab->destructor = delete_t_stack_ab;
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
}

t_stack_ab	*new_t_stack_ab(int argc, char *argv[])
{
	t_stack_ab*const	stack_ab = malloc(sizeof(t_stack_ab));

	if (stack_ab == NULL)
		return (NULL);
	stack_ab->command = new_t_stack();
	stack_ab->stack_a = parse_args(argc, argv);
	stack_ab->stack_b = new_t_stack();
	if (stack_ab->command == NULL
		|| stack_ab->stack_a == NULL || stack_ab->stack_b == NULL)
	{
		if (stack_ab->stack_a != NULL)
			stack_ab->stack_a->destructor(stack_ab->stack_a);
		if (stack_ab->stack_b != NULL)
			stack_ab->stack_b->destructor(stack_ab->stack_b);
		if (stack_ab->command != NULL)
			stack_ab->command->destructor(stack_ab->command);
		if (stack_ab != NULL)
			free(stack_ab);
		return (NULL);
	}
	bind_method_stack_ab(stack_ab);
	return (stack_ab);
}
