/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:14:56 by dowon             #+#    #+#             */
/*   Updated: 2023/05/08 21:02:09 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/include/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"
#include "utils/stack_ab.h"
#include "utils/compare.h"
#include <stdlib.h>

void	handle_error(char *message, int exit_code)
{
	ft_putstr_fd(message, STDERR_FILENO);
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
		st->ra(st, OPTIMIZE);
	else if (dst == B_TOP)
		st->pb(st, OPTIMIZE);
	else if (dst == B_BOTTOM)
	{
		st->pb(st, OPTIMIZE);
		st->rb(st, OPTIMIZE);
	}
	return (1);
}

void	adv_merge_sort(t_stack_ab *st, const int total_size, int (*cmp)(int, int),
		int (*rcmp)(int, int), t_position dst)
{
	const int	sizes[4] = {0, total_size / 3, total_size / 3, total_size - total_size / 3 * 2};

	if (total_size <= 0 || handle_sorted(st, total_size, cmp, rcmp, dst))
		return ;
	if ((total_size == 1 && merge_sort_single(st, dst))
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

void	merge_to_dst(t_stack_ab *st, int sizes[4],
	const t_order order, t_position dst)
{
	const t_compare	cmp = get_rcmp(order);
	t_position		src;

	while (sizes[A_TOP] + sizes[A_BOTTOM] + sizes[B_TOP] + sizes[B_BOTTOM] > 0)
	{
		src = POS_NULL;
		if (sizes[A_TOP] && src == POS_NULL)
			src = A_TOP;
		if (sizes[A_BOTTOM] && (src == POS_NULL
				|| cmp(get_value(st, A_BOTTOM), get_value(st, src))))
			src = A_BOTTOM;
		if (sizes[B_TOP]
			&& (src == POS_NULL
				|| cmp(get_value(st, B_TOP), get_value(st, src))))
			src = B_TOP;
		if (sizes[B_BOTTOM]
			&& (src == POS_NULL
				|| cmp(get_value(st, B_BOTTOM), get_value(st, src))))
			src = B_BOTTOM;
		(merger_to(dst))(st, src);
		sizes[src]--;
	}
}

void	merge_sort(t_stack_ab *st, const int size,
	const t_order order, t_position dst)
{
	int	sizes[4] = {size / 3, size / 3, size / 3, size - size / 3 * 2};

	if (size <= 0 //|| handle_sorted(st, size, get_cmp(order), get_cmp(!order), dst)
		|| (size == 1 && merge_sort_single(st, dst))
		|| (size == 2 && merge_sort_double(st, get_cmp(order), dst)))
		return ;
	else if (size == 3)
	{
		if (dst == B_BOTTOM || dst == B_TOP)
		{
			manual_sort_a_top(st, get_rcmp(order));
			for(int i = 0; i < size; i++)
				st->pb(st, OPTIMIZE);
			if (dst == B_BOTTOM && st->stack_a->size != size)
				for(int i = 0; i < size; i++)
					st->rb(st, OPTIMIZE);
		}
		else
		{
			manual_sort_a_top(st, get_cmp(order));
			if (dst == A_BOTTOM && st->stack_a->size != size)
			{
				for(int i = 0; i < size; i++)
					st->ra(st, OPTIMIZE);
			}
		}
		return ;
	}
	else {
		if (dst == B_BOTTOM || dst == B_TOP)
		{
			merge_sort(st, sizes[B_BOTTOM], order, B_BOTTOM);
			merge_sort(st, sizes[A_BOTTOM], order, A_BOTTOM);
			merge_sort(st, sizes[A_TOP], !order, A_TOP);
			merge_to_dst(st, (int[4]){sizes[0], sizes[1], 0, sizes[3]}, order, B_TOP);
			if (dst == B_BOTTOM)
			{
				if (st->stack_b->size != size)
					for(int i = 0; i < size; i++)
						st->rb(st, OPTIMIZE);
			}
		}
		else
		{
			merge_sort(st, sizes[B_BOTTOM], order, B_BOTTOM);
			merge_sort(st, sizes[B_TOP], !order, B_TOP);
			merge_sort(st, sizes[A_BOTTOM], order, A_BOTTOM);
			merge_to_dst(st, (int[4]){0, sizes[1], sizes[2], sizes[3]}, order, A_TOP);
			if (dst == A_BOTTOM)
			{
				if (st->stack_a->size != size)
					for(int i = 0; i < size; i++)
						st->ra(st, OPTIMIZE);
			}
		}
	}
}

int	main(int argc, char *argv[])
{
	t_stack_ab	*st;
	t_dbl_list	*cmd;

	st = new_t_stack_ab(parse_args(argc, argv), new_t_stack());
	merge_sort(st, st->stack_a->size, DESC, A_TOP);
	// merge_sort(st, 3, DESC, B_BOTTOM);
	// merge_sort(st, 3, DESC, A_BOTTOM);
	// merge_sort(st, 3, !DESC, A_TOP);
	// merge_to_dst(st, (int[4]){3, 3, 0, 3}, DESC, B_TOP);
	// merge_sort(st, 3, !DESC, B_BOTTOM);
	// merge_sort(st, 3, !DESC, A_BOTTOM);
	// merge_sort(st, 3, DESC, A_TOP);
	// merge_to_dst(st, (int[4]){3, 3, 0, 3}, !DESC, B_TOP);
	// merge_sort(st, 3, DESC, B_BOTTOM);
	// merge_sort(st, 3, !DESC, B_TOP);
	// merge_sort(st, 3, DESC, A_BOTTOM);
	// merge_to_dst(st, (int[4]){0, 3, 3, 3}, DESC, A_TOP);
	// merge_to_dst(st, (int[4]){0, 9, 9, 9}, DESC, A_TOP);
	cmd = st->command->bottom;
	while (cmd)
	{
		print_command(cmd->value);
		cmd = cmd->prev;
	}
	st->destructor(st);
	return (0);
}
