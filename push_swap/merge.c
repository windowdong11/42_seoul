#include "utils/stack_ab.h"
#include "push_swap.h"

void	merge_a_top(t_stack_ab *st, t_position src)
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

void	merge_a_bottom(t_stack_ab *st, t_position src)
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

void	merge_b_top(t_stack_ab *st, t_position src)
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

void	merge_b_bottom(t_stack_ab *st, t_position src)
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

t_merger	merger_to(t_position dst)
{
	const t_merger	mergefunc[4] = {merge_a_top, merge_a_bottom, merge_b_top, merge_b_bottom};

	return (mergefunc[dst]);
}

void	adv_merge_3way(t_stack_ab *st, const int sizes[4],
	int (*cmp)(int, int), int (*rcmp)(int, int), t_position dst)
{
	if (dst == A_TOP)
		merge_all_a_top(st, (int [4]){0, sizes[A_BOTTOM], sizes[B_TOP], sizes[B_BOTTOM]}, cmp);
	else if (dst == A_BOTTOM)
	{
		merge_any2(st, get_merge_data((int[2]){sizes[A_BOTTOM], sizes[B_BOTTOM]}, (t_position[2]){A_BOTTOM, B_BOTTOM}, A_TOP, rcmp));
		merge_any2(st, get_merge_data((int[2]){sizes[A_TOP] + sizes[A_BOTTOM] + sizes[B_BOTTOM], sizes[B_TOP]}, (t_position[2]){A_TOP, B_TOP}, dst, cmp));
	}
	else if (dst == B_TOP)
	{
		merge_any2(st, get_merge_data((int[2]){sizes[B_TOP], sizes[A_BOTTOM]}, (t_position[2]){B_TOP, A_BOTTOM}, A_TOP, rcmp));
		merge_any2(st, get_merge_data((int[2]){sizes[A_TOP] + sizes[B_TOP] + sizes[A_BOTTOM], sizes[B_BOTTOM]}, (t_position[2]){A_TOP, B_BOTTOM}, dst, cmp));
	}
	else if (dst == B_BOTTOM)
	{
		merge_any2(st, get_merge_data((int[2]){sizes[B_BOTTOM], sizes[A_BOTTOM]}, (t_position[2]){B_BOTTOM, A_BOTTOM}, A_TOP, rcmp));
		merge_any2(st, get_merge_data((int[2]){sizes[A_TOP] + sizes[B_BOTTOM] + sizes[A_BOTTOM], sizes[B_TOP]}, (t_position[2]){A_TOP, B_TOP}, dst, cmp));
	}
}