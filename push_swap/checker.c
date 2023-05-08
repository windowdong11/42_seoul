/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:08:57 by dowon             #+#    #+#             */
/*   Updated: 2023/05/08 15:33:26 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/include/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"
#include "utils/stack_ab.h"
#include <stdlib.h>

void	handle_error(char *message, int exit_code)
{
	ft_printf(message);
	exit(exit_code);
}

t_dbl_list	**get_position_ptr(t_stack_ab *st, t_position position)
{
	if (position == A_TOP)
		return (&st->stack_a->top);
	else if (position == A_BOTTOM)
		return (&st->stack_a->bottom);
	else if (position == B_TOP)
		return (&st->stack_b->top);
	else if (position == B_BOTTOM)
		return (&st->stack_b->bottom);
	return (NULL);
}

void	merge_any2(t_stack_ab *st, t_merge_data meta)
{
	t_dbl_list**const	storages[2] = {
		get_position_ptr(st, meta.src[0]),
		get_position_ptr(st, meta.src[1])
	};

	while (meta.size[0] && meta.size[1])
	{
		if (!meta.cmp((*storages[0])->value, (*storages[1])->value))
		{
			meta.merge(st, meta.src[0]);
			meta.size[0]--;
		}
		else
		{
			meta.merge(st, meta.src[1]);
			meta.size[1]--;
		}
	}
	while (meta.size[0]-- > 0)
		meta.merge(st, meta.src[0]);
	while (meta.size[1]-- > 0)
		meta.merge(st, meta.src[1]);
}

void	merge_all_a_top(t_stack_ab *st, int sizes[4], int (*cmp)(int, int))
{
	int			total_size;
	int			values[4];
	t_position	merge_position;

	total_size = sizes[A_BOTTOM] + sizes[B_TOP] + sizes[B_BOTTOM];
	while (total_size-- > 0)
	{
		if (sizes[A_BOTTOM])
			values[A_BOTTOM] = st->stack_a->bottom->value;
		if (sizes[B_TOP])
			values[B_TOP] = st->stack_b->top->value;
		if (sizes[B_BOTTOM])
			values[B_BOTTOM] = st->stack_b->bottom->value;
		if (sizes[A_BOTTOM] && sizes[B_BOTTOM] && sizes[B_TOP])
		{
			if (!(cmp(values[A_BOTTOM], values[B_TOP])
					|| cmp(values[A_BOTTOM], values[B_BOTTOM])))
				merge_position = A_BOTTOM;
			else
			{
				if (!cmp(values[B_TOP], values[B_BOTTOM]))
					merge_position = B_TOP;
				else
					merge_position = B_BOTTOM;
			}
		}
		else if (sizes[A_BOTTOM] && sizes[B_BOTTOM])
		{
			if (!cmp(values[A_BOTTOM], values[B_BOTTOM]))
				merge_position = A_BOTTOM;
			else
				merge_position = B_BOTTOM;
		}
		else if (sizes[A_BOTTOM] && sizes[B_TOP])
		{
			if (!cmp(values[A_BOTTOM], values[B_TOP]))
				merge_position = A_BOTTOM;
			else
				merge_position = B_TOP;
		}
		else if (sizes[B_BOTTOM] && sizes[B_TOP])
		{
			if (!cmp(values[B_TOP], values[B_BOTTOM]))
				merge_position = B_TOP;
			else
				merge_position = B_BOTTOM;
		}
		else if (sizes[A_BOTTOM])
			merge_position = A_BOTTOM;
		else if (sizes[B_TOP])
			merge_position = B_TOP;
		else
			merge_position = B_BOTTOM;
		merge_a_top(st, merge_position);
		sizes[merge_position]--;
	}
}

int	merge_sort_single(t_stack_ab *st, t_position dst)
{
	if (dst == A_BOTTOM)
		st->ra(st, 1);
	else if (dst == B_TOP)
		st->pb(st, 1);
	else if (dst == B_BOTTOM)
	{
		st->pb(st, 1);
		st->rb(st, 1);
	}
	return (1);
}

void	adv_merge_sort(t_stack_ab *st, const int total_size, int (*cmp)(int, int),
		int (*rcmp)(int, int), t_position dst)
{
	const int	sizes[4] = {0, total_size / 3,
		total_size - total_size / 3 * 2, total_size / 3};

	if (total_size <= 0 || handle_sorted(st, total_size, cmp, rcmp, dst)
		|| (total_size == 1 && merge_sort_single(st, dst))
		|| (total_size == 2 && merge_sort_double(st, cmp, dst)))
		return ;
	else if (total_size == 3)
	{
		if (dst == A_TOP)
			manual_sort_a_top(st, cmp);
		else if (dst == A_BOTTOM)
			manual_sort_a_bottom(st, cmp);
		else if (dst == B_TOP)
			manual_sort_b_top(st, cmp);
		else if (dst == B_BOTTOM)
			manual_sort_b_bottom(st, cmp);
		return ;
	}
	else if (total_size <= 8)
	{
		if (dst == A_TOP)
		{
			adv_merge_sort(st, total_size / 2, rcmp, cmp, B_TOP);
			adv_merge_sort(st, total_size - total_size / 2,
				rcmp, cmp, A_BOTTOM);
			adv_merge_3way(st, (int [4]){0, total_size - total_size / 2,
				total_size / 2, 0}, cmp, rcmp, dst);
		}
		else if (dst == A_BOTTOM)
		{
			adv_merge_sort(st, total_size / 2, rcmp, cmp, B_TOP);
			adv_merge_sort(st, total_size - total_size / 2, rcmp, cmp, A_TOP);
			adv_merge_3way(st, (int [4]){total_size - total_size / 2,
				0, total_size / 2, 0}, cmp, rcmp, dst);
		}
		else if (dst == B_TOP)
		{
			adv_merge_sort(st, total_size - total_size / 2,
				rcmp, cmp, B_BOTTOM);
			adv_merge_sort(st, total_size / 2, rcmp, cmp, A_TOP);
			adv_merge_3way(st, (int [4]){total_size / 2, 0,
				0, total_size - total_size / 2}, cmp, rcmp, dst);
		}
		else if (dst == B_BOTTOM)
		{
			adv_merge_sort(st, total_size - total_size / 2, rcmp, cmp, B_TOP);
			adv_merge_sort(st, total_size / 2, rcmp, cmp, A_TOP);
			adv_merge_3way(st, (int [4]){total_size / 2,
				0, total_size - total_size / 2, 0}, cmp, rcmp, dst);
		}
		return ;
	}
	if (dst == A_TOP || dst == B_TOP)
		adv_merge_sort(st, sizes[B_BOTTOM], rcmp, cmp, B_BOTTOM);
	else
		adv_merge_sort(st, sizes[B_BOTTOM], cmp, rcmp, B_BOTTOM);
	if (dst == A_TOP)
		adv_merge_sort(st, sizes[A_BOTTOM], rcmp, cmp, A_BOTTOM);
	else
		adv_merge_sort(st, sizes[A_BOTTOM], cmp, rcmp, A_BOTTOM);
	if (dst == B_TOP)
		adv_merge_sort(st, sizes[B_TOP], cmp, rcmp, B_TOP);
	else
		adv_merge_sort(st, sizes[B_TOP], rcmp, cmp, B_TOP);
	adv_merge_3way(st, sizes, cmp, rcmp, dst);
}

int	main(int argc, char *argv[])
{
	t_stack_ab	*stack_ab;
	t_dbl_list	*cmd;

	stack_ab = new_t_stack_ab(parse_args(argc, argv), new_t_stack());
	while (read(STDIN_FILENO, ))
	stack_ab->destructor(stack_ab);
	return (0);
}
