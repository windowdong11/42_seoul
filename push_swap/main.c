/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:14:56 by dowon             #+#    #+#             */
/*   Updated: 2023/04/10 05:30:36 by dowon            ###   ########.fr       */
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
	ft_printf("stack_a : ");
	visualize(st->stack_a);
	ft_printf("stack_b : ");
	visualize(st->stack_b);
}

int ps_pow3(int n)
{
	static int results[20] = {1, };
	if (results[n] == 0)
		results[n] = 3 * ps_pow3(n - 1);
	return (results[n]);
}

void merge_sort(t_stack_ab* st, const int total_size);

void manual_sort3(t_stack_ab* st)
{
	if (st->stack_a->top->value < st->stack_a->top->next->value)
		{
			// 123
			if (st->stack_a->top->next->value < st->stack_a->top->next->next->value)
				return ;
			if (st->stack_a->top->value < st->stack_a->top->next->next->value)
			{
				// 132
				if (st->stack_a->size == 3)
				{
					ft_printf("rra\n");
					st->rra(st);
					ft_printf("sa\n");
					st->sa(st);
				}
				else
				{
					ft_printf("ra\n");
					st->ra(st);
					ft_printf("sa\n");
					st->sa(st);
					ft_printf("rra\n");
					st->rra(st);
				}
			}
			else
			{
				// 231
				if (st->stack_a->size == 3)
				{
					ft_printf("rra\n");
					st->rra(st);
				}
				else
				{
					ft_printf("ra\n");
					st->ra(st);
					ft_printf("sa\n");
					st->sa(st);
					ft_printf("rra\n");
					st->rra(st);
					ft_printf("sa\n");
					st->sa(st);
				}
			}
		}
		else
		{
			if (st->stack_a->top->value < st->stack_a->top->next->next->value)
			{
				// 2 1 3
				ft_printf("sa\n");
				st->sa(st);
			}
			else if (st->stack_a->top->next->value < st->stack_a->top->next->next->value)
			{
				// 3 1 2
				if (st->stack_a->size == 3)
				{
					ft_printf("ra\n");
					st->ra(st);
				}
				else
				{
					ft_printf("sa\n");
					st->sa(st);
					ft_printf("ra\n");
					st->ra(st);
					ft_printf("sa\n");
					st->sa(st);
					ft_printf("rra\n");
					st->rra(st);
				}
			}
			else
			{
				// 3 2 1
				if (st->stack_a->size == 3)
				{
					ft_printf("ra\n");
					st->ra(st);
					ft_printf("sa\n");
					st->sa(st);
				}
				else
				{
					ft_printf("sa\n");
					st->sa(st);
					ft_printf("ra\n");
					st->ra(st);
					ft_printf("sa\n");
					st->sa(st);
					ft_printf("rra\n");
					st->rra(st);
					ft_printf("sa\n");
					st->sa(st);
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

int ps_nearpow3(int n)
{
	int i;

	if (n <= 3)
		return 1;
	i = 0;
	while (i < 20)
	{
		if (ps_pow3(i) == n)
			return (ps_pow3(i - 1));
		if (n / 2 < ps_pow3(i) && n / 3 < ps_pow3(i))
			return (ps_pow3(i - 1));
		i++;
	}
	return -1;
}

void merge_sort(t_stack_ab* st, const int total_size)
{
	// const int	divided_size = ps_nearpow3(total_size);
	const int	divided_size = total_size / 3;
	// const int	sizes[] = {total_size - divided_size * 2, divided_size, divided_size};
	const int	sizes[] = {divided_size, total_size - divided_size * 2};
	// const int	sizes[] = {divided_size, divided_size, total_size - divided_size * 2};
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
	if (total_size == 3)
	{
		manual_sort3(st);
		return;
	}

	merge_sort(st, sizes[1]);
	idx = 0;
	while (idx++ < sizes[1])
	{
		ft_printf("pb\n");
		st->pb(st);
	}
	

	merge_sort(st, sizes[0]);
	idx = 0;
	while (idx++ < sizes[0])
	{
		ft_printf("pb\n");
		st->pb(st);
		if (st->stack_b->size > 1)
		{
			ft_printf("rb\n");
			st->rb(st);
		}
	}

	merge_sort(st, sizes[0]);
	idx = 0;
	while (idx++ < sizes[0])
	{
		ft_printf("ra\n");
		st->ra(st);
	}

	merge_3way(st, sizes[0], sizes[1], sizes[0]);
	// visualize_ab(st);
}

int	main(int argc, char *argv[])
{
	t_stack_ab	*stack_ab;

	stack_ab = new_t_stack_ab(parse_args(argc, argv), new_t_stack());
	// visualize_ab(stack_ab);
	merge_sort(stack_ab, stack_ab->stack_a->size);
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