#include "push_swap.h"

int	is_sorted(t_stack_ab *st, int (*cmp)(int, int), int count)
{
	const t_dbl_list	*top = st->stack_a->top;
	int					idx;

	idx = 1;
	while (idx < count)
	{
		if (!cmp(top->value, top->next->value))
			return (0);
		top = top->next;
		idx++;
	}
	return (1);
}

static int	handle_sorted_b_bottom(t_stack_ab *st, const int total_size,
		int (*cmp)(int, int), int (*rcmp)(int, int))
{
	int	idx;

	if (is_sorted(st, cmp, total_size))
	{
		idx = 0;
		while (idx++ < total_size)
			st->pb(st, OPTIMIZE);
		idx = 0;
		while (idx++ < total_size)
			st->rb(st, OPTIMIZE);
		return (1);
	}
	else if (is_sorted(st, rcmp, total_size))
	{
		idx = 0;
		while (idx++ < total_size)
		{
			st->pb(st, OPTIMIZE);
			st->rb(st, OPTIMIZE);
		}
		return (1);
	}
	return (0);
}

int	handle_sorted(t_stack_ab *st, const int total_size, int (*cmp)(int, int),
		int (*rcmp)(int, int), t_position dst)
{
	int	idx;

	if (dst == A_TOP && is_sorted(st, cmp, total_size))
		return (1);
	else if (dst == A_BOTTOM && is_sorted(st, rcmp, total_size))
	{
		idx = 0;
		while (idx++ < total_size)
			st->ra(st, OPTIMIZE);
		return (1);
	}
	else if (dst == B_TOP && is_sorted(st, rcmp, total_size))
	{
		idx = 0;
		while (idx++ < total_size)
			st->pb(st, OPTIMIZE);
		return (1);
	}
	else if (dst == B_BOTTOM)
		return (handle_sorted_b_bottom(st, total_size, cmp, rcmp));
	return (0);
}
