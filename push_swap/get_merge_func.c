#include "utils/stack_ab.h"
#include "push_swap.h"

static void	merge_a_top(t_stack_ab *st, t_position src)
{
	if (src == A_BOTTOM)
	{
		if (st->stack_a->size > 1)
			st->rra(st, OPTIMIZE);
	}
	else if (src == B_TOP)
		st->pa(st, OPTIMIZE);
	else if (src == B_BOTTOM)
	{
		if (st->stack_b->size != 1)
			st->rrb(st, OPTIMIZE);
		st->pa(st, OPTIMIZE);
	}
}

static void	merge_a_bottom(t_stack_ab *st, t_position src)
{
	if (src == A_TOP)
	{
		if (st->stack_a->size > 1)
			st->ra(st, OPTIMIZE);
	}
	else if (src == B_TOP)
	{
		st->pa(st, OPTIMIZE);
		st->ra(st, OPTIMIZE);
	}
	else if (src == B_BOTTOM)
	{
		st->rrb(st, OPTIMIZE);
		st->pa(st, OPTIMIZE);
		st->ra(st, OPTIMIZE);
	}
}

static void	merge_b_top(t_stack_ab *st, t_position src)
{
	if (src == A_TOP)
		st->pb(st, OPTIMIZE);
	else if (src == A_BOTTOM)
	{
		st->rra(st, OPTIMIZE);
		st->pb(st, OPTIMIZE);
	}
	else if (src == B_BOTTOM)
		st->rrb(st, OPTIMIZE);
}

static void	merge_b_bottom(t_stack_ab *st, t_position src)
{
	if (src == A_TOP)
	{
		st->pb(st, OPTIMIZE);
		st->rb(st, OPTIMIZE);
	}
	else if (src == A_BOTTOM)
	{
		st->rra(st, OPTIMIZE);
		st->pb(st, OPTIMIZE);
		st->rb(st, OPTIMIZE);
	}
	else if (src == B_TOP)
		st->rb(st, OPTIMIZE);
}

t_merger	get_merge_func(t_position dst)
{
	const t_merger	mergefunc[4] = {
		merge_a_top,
		merge_a_bottom,
		merge_b_top,
		merge_b_bottom
	};

	return (mergefunc[dst]);
}
