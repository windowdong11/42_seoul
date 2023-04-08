/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:14:56 by dowon             #+#    #+#             */
/*   Updated: 2023/04/08 07:04:44 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/include/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"
#include "utils/stack_ab.h"
#include <stdlib.h>
#include <stdio.h>

void merge_sort(t_stack_ab* st, const int total_size);

// ! Warning : stderr or stdout
void	handle_error(char *message, int exit_code)
{
	ft_printf(message);
	exit(exit_code);
}

void merge_a_bottom(t_stack_ab *st)
{
	ft_printf("rra\n");
	st->rra(st);
}

void merge_b_top(t_stack_ab *st)
{
	ft_printf("pa\n");
	st->pa(st);
}

void merge_b_bottom(t_stack_ab *st)
{
	ft_printf("rrb\n");
	st->rrb(st);
	ft_printf("pa\n");
	st->pa(st);
}

void merge_3way(t_stack_ab *st, int size_a_bottom, int size_b_top, int size_b_bottom)
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
			if (a_bottom > b_top && a_bottom > b_bottom)
				merge_position = 2;
			else
			{
				if (b_top > b_bottom)
					merge_position = 3;
				else
					merge_position = 4;
			}
		}
		else if (size_a_bottom && size_b_bottom)
		{
			if (a_bottom > b_bottom)
				merge_position = 2;
			else
				merge_position = 4;
		}
		else if (size_a_bottom && size_b_top)
		{
			if (a_bottom > b_top)
				merge_position = 2;
			else
				merge_position = 3;
		}
		else if (size_b_bottom && size_b_top)
		{
			if (b_top > b_bottom)
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

void merge_sort(t_stack_ab* st, const int total_size)
{
	const int	divided_size = total_size / 3;
	int			idx;

	if (total_size <= 1)
		return ;
	else if (total_size == 2)
	{
		if (st->stack_a->top->value > st->stack_a->top->next->value)
		{
			ft_printf("sa\n");
			st->sa(st);
		}
		return ;
	}
	merge_sort(st, divided_size);
	idx = 0;
	while (idx++ < divided_size)
	{
		ft_printf("pb\n");
		st->pb(st);
		if (st->stack_b->size > 1)
		{
			ft_printf("rb\n");
			st->rb(st);
		}
	}
	merge_sort(st, divided_size);
	idx = 0;
	while (idx++ < divided_size)
	{
		ft_printf("pb\n");
		st->pb(st);
	}
	merge_sort(st, total_size - divided_size * 2);
	idx = 0;
	while (idx++ < total_size - divided_size * 2)
	{
		ft_printf("ra\n");
		st->ra(st);
	}
	merge_3way(st, total_size - divided_size * 2, divided_size, divided_size);
}

int	main(int argc, char *argv[])
{
	t_stack_ab	*stack_ab;

	stack_ab = new_t_stack_ab(parse_args(argc, argv), new_t_stack());
	visualize(stack_ab->stack_a);
	visualize(stack_ab->stack_b);
	merge_sort(stack_ab, stack_ab->stack_a->size);
	visualize(stack_ab->stack_a);
	visualize(stack_ab->stack_b);
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
*/