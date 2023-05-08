#include "utils/stack_ab.h"

static void	merge_sort_double_a(t_stack_ab *st,
	int (*cmp)(int, int), t_position dst)
{
	if (dst == A_TOP)
	{
		if (!cmp(st->stack_a->top->value, st->stack_a->top->next->value))
			st->sa(st, OPTIMIZE);
	}
	else if (dst == A_BOTTOM)
	{
		if (cmp(st->stack_a->top->value, st->stack_a->top->next->value))
			st->sa(st, OPTIMIZE);
		st->ra(st, OPTIMIZE);
		st->ra(st, OPTIMIZE);
	}
}

static void	merge_sort_double_b(t_stack_ab *st,
	int (*cmp)(int, int), t_position dst)
{
	if (dst == B_TOP)
	{
		st->pb(st, OPTIMIZE);
		st->pb(st, OPTIMIZE);
		if (!cmp(st->stack_b->top->value, st->stack_b->top->next->value))
			st->sb(st, 1);
	}
	else if (dst == B_BOTTOM)
	{
		st->pb(st, OPTIMIZE);
		st->pb(st, OPTIMIZE);
		if (cmp(st->stack_b->top->value, st->stack_b->top->next->value))
			st->sb(st, 1);
		st->rb(st, OPTIMIZE);
		st->rb(st, OPTIMIZE);
	}
}

int	merge_sort_double(t_stack_ab *st, int (*cmp)(int, int), t_position dst)
{
	if (dst <= A_BOTTOM)
		merge_sort_double_a(st, cmp, dst);
	else
		merge_sort_double_b(st, cmp, dst);
	return (1);
}
