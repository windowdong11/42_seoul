#include "utils/stack_ab.h"

void	manual_sort_b_bottom(t_stack_ab *st, int (*cmp)(int, int))
{
	if (cmp(st->stack_a->top->value, st->stack_a->top->next->value))
	{
		if (cmp(st->stack_a->top->next->value,
				st->stack_a->top->next->next->value))
		{
			st->pb(st, 1);
			st->pb(st, 1);
			st->pb(st, 1);
			st->rb(st, 1);
			st->rb(st, 1);
			st->rb(st, 1);
		}
		else if (cmp(st->stack_a->top->value,
				st->stack_a->top->next->next->value))
		{
			st->pb(st, 1);
			st->pb(st, 1);
			st->rb(st, 1);
			st->pb(st, 1);
			st->rb(st, 1);
			st->rb(st, 1);
		}
		else
		{
			st->sa(st, 1);
			st->pb(st, 1);
			st->rb(st, 1);
			st->pb(st, 1);
			st->rb(st, 1);
			st->pb(st, 1);
			st->rb(st, 1);
		}
	}
	else
	{
		if (cmp(st->stack_a->top->value, st->stack_a->top->next->next->value))
		{
			st->sa(st, 1);
			st->pb(st, 1);
			st->pb(st, 1);
			st->pb(st, 1);
			st->rb(st, 1);
			st->rb(st, 1);
			st->rb(st, 1);
		}
		else if (cmp(st->stack_a->top->next->value,
				st->stack_a->top->next->next->value))
		{
			st->pb(st, 1);
			st->rb(st, 1);
			st->pb(st, 1);
			st->pb(st, 1);
			st->rb(st, 1);
			st->rb(st, 1);
		}
		else
		{
			st->pb(st, 1);
			st->rb(st, 1);
			st->pb(st, 1);
			st->rb(st, 1);
			st->pb(st, 1);
			st->rb(st, 1);
		}
	}
}
