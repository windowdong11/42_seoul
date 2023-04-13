#include "utils/stack_ab.h"
#include "push_swap.h"

void	merge_a_top(t_stack_ab *st, t_position src)
{
	if (src == A_BOTTOM)
		st->rra(st, 1);
	else if (src == B_TOP)
		st->pa(st, 1);
	else if (src == B_BOTTOM)
	{
		st->rrb(st, 1);
		st->pa(st, 1);
	}
}

void	merge_a_bottom(t_stack_ab *st, t_position src)
{
	if (src == A_TOP)
		st->ra(st, 1);
	else if (src == B_TOP)
	{
		st->pa(st, 1);
		st->ra(st, 1);
	}
	else if (src == B_BOTTOM)
	{
		st->rrb(st, 1);
		st->pa(st, 1);
		st->ra(st, 1);
	}
}

void	merge_b_top(t_stack_ab *st, t_position src)
{
	if (src == A_TOP)
		st->pb(st, 1);
	else if (src == A_BOTTOM)
	{
		st->rra(st, 1);
		st->pb(st, 1);
	}
	else if (src == B_BOTTOM)
		st->rrb(st, 1);
}

void	merge_b_bottom(t_stack_ab *st, t_position src)
{
	if (src == A_TOP)
	{
		st->pb(st, 1);
		st->rb(st, 1);
	}
	else if (src == A_BOTTOM)
	{
		st->rra(st, 1);
		st->pb(st, 1);
		st->rb(st, 1);
	}
	else if (src == B_TOP)
		st->rb(st, 1);
}

void	adv_merge_3way(t_stack_ab *st, const int sizes[4],
	int (*cmp)(int, int), int (*rcmp)(int, int), t_position dst)
{
	if (dst == A_TOP)
		merge3_a_top(st, (int [4]){0, sizes[A_BOTTOM], sizes[B_TOP], sizes[B_BOTTOM]}, cmp);
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