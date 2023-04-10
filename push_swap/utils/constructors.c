#include "stack_ab.h"
#include "../ft_printf/include/ft_printf.h"
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
	node->push_next = t_dbl_list_push_next;
	node->push_prev = t_dbl_list_push_prev;
	node->pop_prev = t_dbl_list_pop_prev;
	node->pop_next = t_dbl_list_pop_next;
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
	stack->push_back = t_stack_push_back;
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
	stack_ab->command = new_t_stack();
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

void print_command(t_command command)
{
	t_dbl_list	*cmd;
	const char	*command_prefix[5] = {
		"",
		"s",
		"r",
		"rr",
		"p"
	};
	const char	*command_postfix[3] = {
		"r",
		"a",
		"b"
	};

	if (command / 10 == 1 && command % 10 == 0)
		ft_printf("ss\n");
	else
		ft_printf("%s%s\n", command_prefix[command / 10], command_postfix[command % 10]);
}

int	is_a_command(t_command command)
{
	if (command == PB)
		return (1);
	if (command % 10 == 0 || command % 10 == 1)
		return (1);
	return (0);
}
int	is_b_command(t_command command)
{
	if (command == PA)
		return (1);
	if (command % 10 == 0 || command % 10 == 2)
		return (1);
	return (0);
}

int	find_n_remove(t_stack_ab *this, t_command command, int view_history)
{
	t_dbl_list	*node;
	t_dbl_list	*tmp;
	int			(*is_command)(t_command);

	node = this->command->top;
	if (is_a_command(command))
		is_command = is_a_command;
	else
		is_command = is_b_command;
	if (node != NULL)
	{
		if (node->value == command)
		{
			this->command->pop(this->command);
			return (1);
		}
		if (view_history == 0)
			return (0);
		while (node->next && !is_a_command(node->value))
		{
			print_command(node->next->value);
			if (node->next->value == command)
			{
				if (this->command->bottom == node->next)
					this->command->bottom = node;
				tmp = node->pop_next(node);
				tmp->destructor(tmp);
				return (1);
			}
			node = node->next;
		}
	}
	return (0);
}