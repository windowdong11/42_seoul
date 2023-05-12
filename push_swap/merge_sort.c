

#include "push_swap.h"
#include "utils/stack_ab.h"
#include "utils/compare.h"

void	merge_sort_2way(t_stack_ab *st, int size, t_order order, t_position dst)
{
	if (dst <= A_BOTTOM)
	{
		merge_sort(st, size / 2, !order, B_TOP);
		merge_sort(st, size - size / 2, order, A_BOTTOM);
		merge_to_dst(st, (int [4]){0, size - size / 2, size / 2, 0},
			order, A_TOP);
		if (dst == A_BOTTOM && st->stack_a->size != size)
			while (size-- > 0)
				st->ra(st, OPTIMIZE);
	}
	else
	{
		merge_sort(st, size / 2, order, B_BOTTOM);
		merge_sort(st, size - size / 2, !order, A_TOP);
		merge_to_dst(st, (int [4]){size - size / 2, 0, 0, size / 2},
			order, B_TOP);
		if (dst == B_BOTTOM && st->stack_b->size != size)
			while (size-- > 0)
				st->rb(st, OPTIMIZE);
	}
}

void	manual_sort(t_stack_ab *st, int size, t_order order, t_position dst)
{
	if (size == 1)
		manual_sort_single(st, dst);
	else if (size == 2)
		manual_sort_double(st, get_cmp(order), dst);
	else if (size == 3)
	{
		manual_sort_triple(st, dst, get_cmp(order));
	}
	else
		merge_sort_2way(st, size, order, dst);
}
