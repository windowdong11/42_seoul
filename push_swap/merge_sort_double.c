#include "utils/stack_ab.h"

int	merge_sort_double(t_stack_ab *st, int (*cmp)(int, int), t_position dst)
{
	if (dst == A_TOP)
	{
		if (!cmp(st->stack_a->top->value, st->stack_a->top->next->value))
			st->sa(st, OPTIMIZE);
	}
	else if (dst == A_BOTTOM)
	{
		if (!cmp(st->stack_a->top->value, st->stack_a->top->next->value))
			st->sa(st, OPTIMIZE);
		if (st->stack_b->size == 2)
			return (1);
		st->ra(st, OPTIMIZE);
		st->ra(st, OPTIMIZE);
	}
	else if (dst == B_TOP)
	{
		if (cmp(st->stack_a->top->value, st->stack_a->top->next->value))
			st->sa(st, OPTIMIZE);
		st->pb(st, OPTIMIZE);
		st->pb(st, OPTIMIZE);
	}
	else if (dst == B_BOTTOM)
	{
		if (cmp(st->stack_a->top->value, st->stack_a->top->next->value))
			st->sa(st, OPTIMIZE);
		st->pb(st, OPTIMIZE);
		st->pb(st, OPTIMIZE);
		if (st->stack_b->size == 2)
			return (1);
		st->rb(st, OPTIMIZE);
		st->rb(st, OPTIMIZE);
	}
	return (1);
}
