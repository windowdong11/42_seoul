#include "utils/stack_ab.h"

void	merge_sort_double(t_stack_ab *st, int (*cmp)(int, int), t_position dst)
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
			return ;
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
		st->pb(st, OPTIMIZE);
		if (cmp(get_value(st, A_TOP), get_value(st, B_TOP)))
		{
			st->pb(st, OPTIMIZE);
			st->rb(st, OPTIMIZE);
		}
		else
		{
			st->rb(st, OPTIMIZE);
			st->pb(st, OPTIMIZE);
		}
		st->rb(st, OPTIMIZE);
	}
	return ;
}
