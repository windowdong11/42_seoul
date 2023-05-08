#include "compare.h"

static int	greater(int a, int b)
{
	return (a > b);
}

static int	smaller(int a, int b)
{
	return (a < b);
}

t_compare	get_cmp(const t_order order)
{
	const t_compare	cmp[] = {smaller, greater};

	return (cmp[order]);
}

t_compare	get_rcmp(const	t_order order)
{
	const t_compare	rcmp[] = {greater, smaller};

	return (rcmp[order]);
}
