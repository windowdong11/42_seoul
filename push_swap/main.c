/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:14:56 by dowon             #+#    #+#             */
/*   Updated: 2023/05/12 22:45:50 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/include/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"
#include "utils/stack_ab.h"
#include <stdlib.h>

void	handle_error(char *message, int exit_code)
{
	ft_putstr_fd(message, STDERR_FILENO);
	exit(exit_code);
}

void	merge_sort_a(t_stack_ab *st, int size, t_order order, t_position dst)
{
	int	sizes[4];

	sizes[A_TOP] = 0;
	sizes[A_BOTTOM] = size / 3;
	sizes[B_BOTTOM] = size / 3;
	sizes[B_TOP] = size - size / 3 * 2;
	merge_sort(st, sizes[B_BOTTOM], order, B_BOTTOM);
	merge_sort(st, sizes[B_TOP], !order, B_TOP);
	merge_sort(st, sizes[A_BOTTOM], order, A_BOTTOM);
	merge_to_dst(st, sizes, order, A_TOP);
	if (dst == A_BOTTOM && st->stack_a->size != size)
		while (size-- > 0)
			st->ra(st, OPTIMIZE);
}

void	merge_sort_b(t_stack_ab *st, int size, t_order order, t_position dst)
{
	int	sizes[4];

	sizes[B_TOP] = 0;
	sizes[A_BOTTOM] = size / 3;
	sizes[B_BOTTOM] = size / 3;
	sizes[A_TOP] = size - size / 3 * 2;
	merge_sort(st, sizes[A_BOTTOM], order, A_BOTTOM);
	merge_sort(st, sizes[B_BOTTOM], order, B_BOTTOM);
	merge_sort(st, sizes[A_TOP], !order, A_TOP);
	merge_to_dst(st, sizes, order, B_TOP);
	if (dst == B_BOTTOM && st->stack_b->size != size)
		while (size-- > 0)
			st->rb(st, OPTIMIZE);
}

void	merge_sort(t_stack_ab *st, int size, t_order order, t_position dst)
{
	if (size <= 8)
		manual_sort(st, size, order, dst);
	else if (dst == A_TOP || dst == A_BOTTOM)
		merge_sort_a(st, size, order, dst);
	else
		merge_sort_b(st, size, order, dst);
}

int	main(int argc, char *argv[])
{
	t_stack_ab	*st;
	t_dbl_list	*cmd;

	st = new_t_stack_ab(parse_args(argc, argv), new_t_stack());
	merge_sort(st, st->stack_a->size, DESC, A_TOP);
	cmd = st->command->bottom;
	while (cmd)
	{
		print_command(cmd->value);
		cmd = cmd->prev;
	}
	st->destructor(st);
	return (0);
}
