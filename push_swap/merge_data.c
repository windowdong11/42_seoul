#include "push_swap.h"

t_merge_data	get_merge_data(int size[2], t_position src[2],
	t_position dst, int (*cmp)(int, int))
{
	t_merge_data	meta;

	meta.size[0] = size[0];
	meta.size[1] = size[1];
	meta.src[0] = src[0];
	meta.src[1] = src[1];
	meta.cmp = cmp;
	if (dst == A_TOP)
		meta.merge = merge_a_top;
	else if (dst == A_BOTTOM)
		meta.merge = merge_a_bottom;
	else if (dst == B_TOP)
		meta.merge = merge_b_top;
	else if (dst == B_BOTTOM)
		meta.merge = merge_b_bottom;
	return (meta);
}
