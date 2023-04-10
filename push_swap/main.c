/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:14:56 by dowon             #+#    #+#             */
/*   Updated: 2023/04/10 22:55:33 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/include/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"
#include "utils/stack_ab.h"
#include <stdlib.h>
#include <stdio.h>

void visualize_ab(t_stack_ab *st)
{
	visualize(st->stack_a);
	visualize(st->stack_b);
}

void manual_sort3(t_stack_ab* st, int (*cmp)(int, int))
{
	if (!cmp(st->stack_a->top->value, st->stack_a->top->next->value))
		{
			// 123
			if (!cmp(st->stack_a->top->next->value, st->stack_a->top->next->next->value))
				return ;
			if (!cmp(st->stack_a->top->value, st->stack_a->top->next->next->value))
			{
				// 132
				if (st->stack_a->size == 3)
				{
					st->rra(st, 1);
					st->sa(st, 1);
				}
				else
				{
					st->ra(st, 1);
					st->sa(st, 1);
					st->rra(st, 1);
				}
			}
			else
			{
				// 231
				if (st->stack_a->size == 3)
				{
					st->rra(st, 1);
				}
				else
				{
					st->ra(st, 1);
					st->sa(st, 1);
					st->rra(st, 1);
					st->sa(st, 1);
				}
			}
		}
		else
		{
			if (!cmp(st->stack_a->top->value, st->stack_a->top->next->next->value))
			{
				// 2 1 3
				st->sa(st, 1);
			}
			else if (!cmp(st->stack_a->top->next->value, st->stack_a->top->next->next->value))
			{
				// 3 1 2
				if (st->stack_a->size == 3)
				{
					st->ra(st, 1);
				}
				else
				{
					st->sa(st, 1);
					st->ra(st, 1);
					st->sa(st, 1);
					st->rra(st, 1);
				}
			}
			else
			{
				// 3 2 1
				if (st->stack_a->size == 3)
				{
					st->ra(st, 1);
					st->sa(st, 1);
				}
				else
				{
					st->sa(st, 1);
					st->ra(st, 1);
					st->sa(st, 1);
					st->rra(st, 1);
					st->sa(st, 1);
				}
			}
		}
}

// ! Warning : stderr or stdout
void	handle_error(char *message, int exit_code)
{
	ft_printf(message);
	exit(exit_code);
}

void merge_a_bottom(t_stack_ab *st)
{
	st->rra(st, 1);
}

void merge_b_top(t_stack_ab *st)
{
	st->pa(st, 1);
}

void merge_b_bottom(t_stack_ab *st)
{
	st->rrb(st, 1);
	st->pa(st, 1);
}

void merge_3way(t_stack_ab *st, int size_a_bottom, int size_b_top, int size_b_bottom, int (*cmp)(int, int))
{
	int total_size;
	int a_bottom;
	int b_top;
	int b_bottom;
	int merge_position;

	total_size = size_a_bottom + size_b_top + size_b_bottom;
	while (total_size-- > 0)
	{
		if (size_a_bottom)
			a_bottom = st->stack_a->bottom->value;
		if (size_b_top)
			b_top = st->stack_b->top->value;
		if (size_b_bottom)
			b_bottom = st->stack_b->bottom->value;
		if (size_a_bottom && size_b_bottom && size_b_top)
		{
			if (cmp(a_bottom, b_top) && cmp(a_bottom, b_bottom))
				merge_position = 2;
			else
			{
				if (cmp(b_top, b_bottom))
					merge_position = 3;
				else
					merge_position = 4;
			}
		}
		else if (size_a_bottom && size_b_bottom)
		{
			if (cmp(a_bottom, b_bottom))
				merge_position = 2;
			else
				merge_position = 4;
		}
		else if (size_a_bottom && size_b_top)
		{
			if (cmp(a_bottom, b_top))
				merge_position = 2;
			else
				merge_position = 3;
		}
		else if (size_b_bottom && size_b_top)
		{
			if (cmp(b_top, b_bottom))
				merge_position = 3;
			else
				merge_position = 4;
		}
		else if (size_a_bottom)
			merge_position = 2;
		else if (size_b_top)
			merge_position = 3;
		else
			merge_position = 4;
		if (merge_position == 2)
		{
			merge_a_bottom(st);
			size_a_bottom--;
		}
		else if (merge_position == 3)
		{
			merge_b_top(st);
			size_b_top--;
		}
		else if (merge_position == 4)
		{
			merge_b_bottom(st);
			size_b_bottom--;
		}
	}
}

int greater(int a, int b)
{
	return (a > b);
}

int smaller(int a, int b)
{
	return (a < b);
}

void merge_sort(t_stack_ab* st, const int total_size, int (*cmp)(int, int), int (*rcmp)(int, int))
{
	const int	divided_size = total_size / 3;
	const int	sizes[] = {divided_size, total_size - divided_size * 2};
	int			idx;

	if (total_size <= 1)
		return ;
	else if (total_size == 2)
	{
		if (cmp(st->stack_a->top->value, st->stack_a->top->next->value))
			st->sa(st, 1);
		return ;
	}
	if (total_size == 3)
	{
		manual_sort3(st, cmp);
		return;
	}

	merge_sort(st, sizes[0], rcmp, cmp);
	idx = 0;
	while (idx++ < sizes[0])
		st->pb(st, 1);

	merge_sort(st, sizes[0], cmp, rcmp);
	idx = 0;
	while (idx++ < sizes[0])
		st->rr(st, 1);

	merge_sort(st, sizes[1], cmp, rcmp);
	idx = 0;
	while (idx++ < sizes[1])
		st->pb(st, 1);

	merge_3way(st, sizes[0], sizes[1], sizes[0], cmp);
}

int	main(int argc, char *argv[])
{
	t_stack_ab	*stack_ab;
	t_dbl_list	*cmd;

	stack_ab = new_t_stack_ab(parse_args(argc, argv), new_t_stack());
	merge_sort(stack_ab, stack_ab->stack_a->size, greater, smaller);
	cmd = stack_ab->command->bottom;
	while (cmd)
	{
		print_command(cmd->value);
		cmd = cmd->prev;
	}
	stack_ab->destructor(stack_ab);
	return (0);
}
// gcc -Wall -Werror -Wextra -g -fsanitize=address *.c utils/*.c ft_printf/src/*.c libft/*.c
/*
div3 = n / 3
left = n - div3 * 2
mergesort(div3)
moveB(div3)
mergesort(div3)
moveB(div3)
rB(div3)
mergesort(left)
rA(div3)
merge(div3, div3, left)


42c0 -> 4310 -> 4360
42c0 <- 42c0 <-

top
62a0 -> 6ca0 -> 6cf0 -> 6d40 -> 62f0
62a0 <- 6ca0 <- 6cf0

division
-> n / 3
commands
-> 1,1,2
n/3 + n/3 + 2n/3 = 4n/3
8/3nlog3(n)
*/