/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:14:56 by dowon             #+#    #+#             */
/*   Updated: 2023/05/09 19:57:27 by dowon            ###   ########.fr       */
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
	// int	sizes[4] = {size / 3, (size - size / 3) / 2, size / 3, (size - size / 3) / 2 + (size - size / 3) % 2};
	// int	sizes[4] = {size / 3, size / 3, size / 3, size - size / 3 * 2};
	int	sizes[4] = {size - size / 3 * 2, size / 3, size - size / 3 * 2, size / 3};

	if (size <= 0
		|| (size == 1 && merge_sort_single(st, dst))
		|| (size == 2 && merge_sort_double(st, get_cmp(order), dst)))
		return ;
	else if (size == 3)
	{
		if (dst == B_BOTTOM || dst == B_TOP)
		{
			manual_sort_b_top(st, get_cmp(order));
			if (dst == B_BOTTOM && st->stack_b->size != size)
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
			merge_sort(st, sizes[A_BOTTOM], order, A_BOTTOM);
			merge_sort(st, sizes[B_BOTTOM], order, B_BOTTOM);
			merge_sort(st, sizes[A_TOP], !order, A_TOP);
			merge_to_dst(st, (int[4]){sizes[0], sizes[1], 0, sizes[3]}, order, B_TOP);
			if (dst == B_BOTTOM && st->stack_b->size != size)
			{
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
			if (dst == A_BOTTOM && st->stack_a->size != size)
			{
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
	// merge_sort_single(st, B_TOP);
	// merge_sort_single(st, B_BOTTOM);
	// manual_sort_b_top(st, get_cmp(DESC));
	cmd = st->command->bottom;
	while (cmd)
	{
		print_command(cmd->value);
		cmd = cmd->prev;
	}
	st->destructor(st);
	return (0);
}
