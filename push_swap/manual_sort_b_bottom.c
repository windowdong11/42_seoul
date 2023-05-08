#include "utils/stack_ab.h"

void	manual_sort_b_bottom(t_stack_ab *st, int (*cmp)(int, int))
{
	if (cmp(st->stack_a->top->value, st->stack_a->top->next->value))
	{
		if (cmp(st->stack_a->top->next->value,
				st->stack_a->top->next->next->value))
		{
			st->pb(st, OPTIMIZE);
			st->pb(st, OPTIMIZE);
			st->pb(st, OPTIMIZE);
			st->rb(st, OPTIMIZE);
			st->rb(st, OPTIMIZE);
			st->rb(st, OPTIMIZE);
		}
		else if (cmp(st->stack_a->top->value,
				st->stack_a->top->next->next->value))
		{
			st->pb(st, OPTIMIZE);
			st->pb(st, OPTIMIZE);
			st->rb(st, OPTIMIZE);
			st->pb(st, OPTIMIZE);
			st->rb(st, OPTIMIZE);
			st->rb(st, OPTIMIZE);
		}
		else
		{
			st->sa(st, 1);
			st->pb(st, OPTIMIZE);
			st->rb(st, OPTIMIZE);
			st->pb(st, OPTIMIZE);
			st->rb(st, OPTIMIZE);
			st->pb(st, OPTIMIZE);
			st->rb(st, OPTIMIZE);
		}
	}
	else
	{
		if (cmp(st->stack_a->top->value, st->stack_a->top->next->next->value))
		{
			st->sa(st, 1);
			st->pb(st, OPTIMIZE);
			st->pb(st, OPTIMIZE);
			st->pb(st, OPTIMIZE);
			st->rb(st, OPTIMIZE);
			st->rb(st, OPTIMIZE);
			st->rb(st, OPTIMIZE);
		}
		else if (cmp(st->stack_a->top->next->value,
				st->stack_a->top->next->next->value))
		{
			st->pb(st, OPTIMIZE);
			st->rb(st, OPTIMIZE);
			st->pb(st, OPTIMIZE);
			st->pb(st, OPTIMIZE);
			st->rb(st, OPTIMIZE);
			st->rb(st, OPTIMIZE);
		}
		else
		{
			st->pb(st, OPTIMIZE);
			st->rb(st, OPTIMIZE);
			st->pb(st, OPTIMIZE);
			st->rb(st, OPTIMIZE);
			st->pb(st, OPTIMIZE);
			st->rb(st, OPTIMIZE);
		}
	}
}
