/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:14:56 by dowon             #+#    #+#             */
/*   Updated: 2023/04/13 20:54:14 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/include/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"
#include "utils/stack_ab.h"
#include <stdio.h>
#include <stdlib.h>

void	visualize_ab(t_stack_ab *st, const char *prefix, int d)
{
	if (0)
	{
		ft_printf("(%d) %s", d, prefix);
		ft_printf("stack_a: ");
		visualize(st->stack_a);
		ft_printf("stack_b: ");
		visualize(st->stack_b);
	}
}

void	manual_sort3_empty(t_stack_ab *st, int (*cmp)(int, int))
{
	if (cmp(st->stack_a->top->value, st->stack_a->top->next->value))
	{
		// 123
		if (cmp(st->stack_a->top->next->value,
				st->stack_a->top->next->next->value))
			return ;
		if (cmp(st->stack_a->top->value, st->stack_a->top->next->next->value))
		{
			// 132
			st->rra(st, 1);
			st->sa(st, 1);
		}
		else
			st->rra(st, 1);
	}
	else
	{
		if (cmp(st->stack_a->top->value, st->stack_a->top->next->next->value))
			st->sa(st, 1);
		else if (cmp(st->stack_a->top->next->value,
					st->stack_a->top->next->next->value))
			st->ra(st, 1);
		else
		{
			st->ra(st, 1);
			st->sa(st, 1);
		}
	}
}

void	manual_sort3(t_stack_ab *st, int (*cmp)(int, int))
{
	if (st->stack_a->size == 3)
	{
		manual_sort3_empty(st, cmp);
		return ;
	}
	if (cmp(st->stack_a->top->value, st->stack_a->top->next->value))
	{
		if (cmp(st->stack_a->top->next->value,
				st->stack_a->top->next->next->value))
			return ;
		if (cmp(st->stack_a->top->value, st->stack_a->top->next->next->value))
		{
			st->ra(st, 1);
			st->sa(st, 1);
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
	else
	{
		if (cmp(st->stack_a->top->value, st->stack_a->top->next->next->value))
			st->sa(st, 1);
		else if (cmp(st->stack_a->top->next->value,
					st->stack_a->top->next->next->value))
		{
			st->sa(st, 1);
			st->ra(st, 1);
			st->sa(st, 1);
			st->rra(st, 1);
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

void	manual_sort_b_top(t_stack_ab *st, int (*cmp)(int, int))
{
	if (cmp(st->stack_a->top->value, st->stack_a->top->next->value))
	{
		if (cmp(st->stack_a->top->next->value,
				st->stack_a->top->next->next->value))
		{
			st->pb(st, 1);
			st->sa(st, 1);
			st->pb(st, 1);
			st->sb(st, 1);
			st->pb(st, 1);
			st->sb(st, 1);
		}
		else if (cmp(st->stack_a->top->value, st->stack_a->top->next->next->value))
		{
			st->sa(st, 1);
			st->pb(st, 1);
			st->sa(st, 1);
			st->pb(st, 1);
			st->pb(st, 1);
		}
		else
		{
			st->sa(st, 1);
			st->pb(st, 1);
			st->pb(st, 1);
			st->pb(st, 1);
		}
	}
	else
	{
		if (cmp(st->stack_a->top->value, st->stack_a->top->next->next->value))
		{
			st->pb(st, 1);
			st->sa(st, 1);
			st->pb(st, 1);
			st->sb(st, 1);
			st->pb(st, 1);
		}
		else if (cmp(st->stack_a->top->next->value,
					st->stack_a->top->next->next->value))
		{
			st->pb(st, 1);
			st->sa(st, 1);
			st->pb(st, 1);
			st->pb(st, 1);
		}
		else
		{
			st->pb(st, 1);
			st->pb(st, 1);
			st->pb(st, 1);
		}
	}
}

void	manual_sort_b_bottom(t_stack_ab *st, int (*cmp)(int, int))
{
	if (cmp(st->stack_a->top->value, st->stack_a->top->next->value))
	{
		if (cmp(st->stack_a->top->next->value,
				st->stack_a->top->next->next->value))
		{
			st->pb(st, 1);
			st->pb(st, 1);
			st->pb(st, 1);
			st->rb(st, 1);
			st->rb(st, 1);
			st->rb(st, 1);
		}
		else if (cmp(st->stack_a->top->value, st->stack_a->top->next->next->value))
		{
			st->pb(st, 1);
			st->pb(st, 1);
			st->rb(st, 1);
			st->pb(st, 1);
			st->rb(st, 1);
			st->rb(st, 1);
		}
		else
		{
			st->sa(st, 1);
			st->pb(st, 1);
			st->rb(st, 1);
			st->pb(st, 1);
			st->rb(st, 1);
			st->pb(st, 1);
			st->rb(st, 1);
		}
	}
	else
	{
		if (cmp(st->stack_a->top->value, st->stack_a->top->next->next->value))
		{
			st->sa(st, 1);
			st->pb(st, 1);
			st->pb(st, 1);
			st->pb(st, 1);
			st->rb(st, 1);
			st->rb(st, 1);
			st->rb(st, 1);
		}
		else if (cmp(st->stack_a->top->next->value,
					st->stack_a->top->next->next->value))
		{
			st->pb(st, 1);
			st->rb(st, 1);
			st->pb(st, 1);
			st->pb(st, 1);
			st->rb(st, 1);
			st->rb(st, 1);
		}
		else
		{
			st->pb(st, 1);
			st->rb(st, 1);
			st->pb(st, 1);
			st->rb(st, 1);
			st->pb(st, 1);
			st->rb(st, 1);
		}
	}
}

void	manual_sort_a_bottom(t_stack_ab *st, int (*cmp)(int, int))
{
	if (cmp(st->stack_a->top->value, st->stack_a->top->next->value))
	{
		if (cmp(st->stack_a->top->next->value,
				st->stack_a->top->next->next->value))
		{
			st->pb(st, 1);
			st->sa(st, 1);
			st->ra(st, 1);
			st->ra(st, 1);
			st->pa(st, 1);
			st->ra(st, 1);
		}
		else if (cmp(st->stack_a->top->value, st->stack_a->top->next->next->value))
		{
			st->sa(st, 1);
			st->ra(st, 1);
			st->sa(st, 1);
			st->ra(st, 1);
			st->ra(st, 1);
		}
		else
		{
			st->sa(st, 1);
			st->ra(st, 1);
			st->ra(st, 1);
			st->ra(st, 1);
		}
	}
	else
	{
		if (cmp(st->stack_a->top->value, st->stack_a->top->next->next->value))
		{
			st->pb(st, 1);
			st->sa(st, 1);
			st->ra(st, 1);
			st->pa(st, 1);
			st->ra(st, 1);
			st->ra(st, 1);
		}
		else if (cmp(st->stack_a->top->next->value,
					st->stack_a->top->next->next->value))
		{
			st->ra(st, 1);
			st->sa(st, 1);
			st->ra(st, 1);
			st->ra(st, 1);
		}
		else
		{
			st->rb(st, 1);
			st->rb(st, 1);
			st->rb(st, 1);
		}
	}
}

// 1 1 2 -> 9 or 10
void manual_sort4(t_stack_ab *st, int (*cmp)(int, int))
{
	const t_dbl_list *top = st->stack_a->top;

	if (cmp(top->value, top->next->value) &&
		cmp(top->value, top->next->next->value) &&
		cmp(top->value, top->next->next->next->value))
	{
		st->pa(st, 1);
		manual_sort3(st, cmp);
		st->pb(st, 1);
	}
	else if (cmp(top->next->next->next->value, top->value) &&
		cmp(top->next->next->next->value, top->next->value) &&
		cmp(top->next->next->next->value, top->next->next->value))
	{
		st->pa(st, 1);
		manual_sort3(st, cmp);
		st->pb(st, 1);
	}
}

// ! Warning : stderr or stdout
void	handle_error(char *message, int exit_code)
{
	ft_printf(message);
	exit(exit_code);
}

void   merge_a_top(t_stack_ab *st, t_position src)
{
	if (src == A_BOTTOM)
		st->rra(st, 1);
	else if (src == B_TOP)
		st->pa(st, 1);
	else if (src == B_BOTTOM)
	{
		st->rrb(st, 1);
		st->pa(st, 1);
	}
}

void	merge_a_bottom(t_stack_ab *st, t_position src)
{
	if (src == A_TOP)
		st->ra(st, 1);
	else if (src == B_TOP)
	{
		st->pa(st, 1);
		st->ra(st, 1);
	}
	else if (src == B_BOTTOM)
	{
		st->rrb(st, 1);
		st->pa(st, 1);
		st->ra(st, 1);
	}
}

void	merge_b_top(t_stack_ab *st, t_position src)
{
	if (src == A_TOP)
		st->pb(st, 1);
	else if (src == A_BOTTOM)
	{
		st->rra(st, 1);
		st->pb(st, 1);
	}
	else if (src == B_BOTTOM)
		st->rrb(st, 1);
}

void	merge_b_bottom(t_stack_ab *st, t_position src)
{
	if (src == A_TOP)
	{
		st->pb(st, 1);
		st->rb(st, 1);
	}
	else if (src == A_BOTTOM)
	{
		st->rra(st, 1);
		st->pb(st, 1);
		st->rb(st, 1);
	}
	else if (src == B_TOP)
		st->rb(st, 1);
}

int is_sorted(t_stack_ab *st, int (*cmp)(int, int), int count)
{
	t_dbl_list *top = st->stack_a->top;
	int i = 1;

	while (i < count)
	{
		if (!cmp(top->value, top->next->value))
			return (0);
		top = top->next;
		i++;
	}
	return (1);
}

typedef struct s_merge_data
{
	int size[2];
	t_position src[2];
	void (*merge)(t_stack_ab*, t_position);
	int (*cmp)(int, int);
}	t_merge_data;

t_merge_data get_merge_data(int size[2], t_position src[2], t_position dst, int (*cmp)(int, int))
{
	t_merge_data meta;

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

void	merge_3way(t_stack_ab *st, int size_a_bottom, int size_b_top,
		int size_b_bottom, int (*cmp)(int, int))
{
	int	total_size;
	int	a_bottom;
	int	b_top;
	int	b_bottom;
	t_position	merge_position;

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
			if (!(cmp(a_bottom, b_top) || cmp(a_bottom, b_bottom)))
				merge_position = A_BOTTOM;
			else
			{
				if (!cmp(b_top, b_bottom))
					merge_position = B_TOP;
				else
					merge_position = B_BOTTOM;
			}
		}
		else if (size_a_bottom && size_b_bottom)
		{
			if (!cmp(a_bottom, b_bottom))
				merge_position = A_BOTTOM;
			else
				merge_position = B_BOTTOM;
		}
		else if (size_a_bottom && size_b_top)
		{
			if (!cmp(a_bottom, b_top))
				merge_position = A_BOTTOM;
			else
				merge_position = B_TOP;
		}
		else if (size_b_bottom && size_b_top)
		{
			if (!cmp(b_top, b_bottom))
				merge_position = B_TOP;
			else
				merge_position = B_BOTTOM;
		}
		else if (size_a_bottom)
			merge_position = A_BOTTOM;
		else if (size_b_top)
			merge_position = B_TOP;
		else
			merge_position = B_BOTTOM;
		if (merge_position == A_BOTTOM)
		{
			merge_a_top(st, A_BOTTOM);
			size_a_bottom--;
		}
		else if (merge_position == B_TOP)
		{
			merge_a_top(st, B_TOP);
			size_b_top--;
		}
		else if (merge_position == B_BOTTOM)
		{
			merge_a_top(st, B_BOTTOM);
			size_b_bottom--;
		}
	}
}

void	adv_merge_3way(t_stack_ab *st, const int sizes[4], int (*cmp)(int, int), int (*rcmp)(int, int), t_position dst)
{
	visualize_ab(st, "[before merge]\n", 0);
	if (dst == A_TOP)
		merge_3way(st, sizes[A_BOTTOM], sizes[B_TOP], sizes[B_BOTTOM], cmp);
	else if (dst == A_BOTTOM)
	{
		merge_any2(st, get_merge_data((int[2]){sizes[A_BOTTOM], sizes[B_BOTTOM]}, (t_position[2]){A_BOTTOM, B_BOTTOM}, A_TOP, rcmp));
		visualize_ab(st, "[merged to A_TOP]\n", 0);
		merge_any2(st, get_merge_data((int[2]){sizes[A_TOP] + sizes[A_BOTTOM] + sizes[B_BOTTOM], sizes[B_TOP]}, (t_position[2]){A_TOP, B_TOP}, dst, cmp));
	}
	else if (dst == B_TOP)
	{
		merge_any2(st, get_merge_data((int[2]){sizes[B_TOP], sizes[A_BOTTOM]}, (t_position[2]){B_TOP, A_BOTTOM}, A_TOP, rcmp));
		visualize_ab(st, "[merged to A_TOP]\n", 0);
		merge_any2(st, get_merge_data((int[2]){sizes[A_TOP] + sizes[B_TOP] + sizes[A_BOTTOM], sizes[B_BOTTOM]}, (t_position[2]){A_TOP, B_BOTTOM}, dst, cmp));
	}
	else if (dst == B_BOTTOM)
	{
		merge_any2(st, get_merge_data((int[2]){sizes[B_BOTTOM], sizes[A_BOTTOM]}, (t_position[2]){B_BOTTOM, A_BOTTOM}, A_TOP, rcmp));
		visualize_ab(st, "[merged to A_TOP]\n", 0);
		merge_any2(st, get_merge_data((int[2]){sizes[A_TOP] + sizes[B_BOTTOM] + sizes[A_BOTTOM], sizes[B_TOP]}, (t_position[2]){A_TOP, B_TOP}, dst, cmp));
	}
}

int	greater(int a, int b)
{
	// ft_printf("gt\n");
	return (a > b);
}

int	smaller(int a, int b)
{
	// ft_printf("sm\n");
	return (a < b);
}

void	adv_merge_sort(t_stack_ab *st, const int total_size, int (*cmp)(int, int),
		int (*rcmp)(int, int), t_position dst)
{
	int	sizes[4] = {0, total_size / 3, total_size - total_size / 3 * 2, total_size / 3};
	int idx;

	if (dst == A_BOTTOM && is_sorted(st, rcmp, total_size))
	{
		idx = 0;
		while (idx++ < total_size)
			st->ra(st, 1);
		return ;
	}
	else if (dst == B_TOP && is_sorted(st, rcmp, total_size))
	{
		idx = 0;
		while (idx++ < total_size)
			st->pb(st, 1);
		return ;
	}
	else if (dst == B_BOTTOM)
	{
		if (is_sorted(st, cmp, total_size))
		{
			idx = 0;
			while (idx++ < total_size)
				st->pb(st, 1);
			idx = 0;
			while (idx++ < total_size)
				st->rb(st, 1);
			return ;
		}
		else if (is_sorted(st, rcmp, total_size))
		{
			idx = 0;
			while (idx++ < total_size)
			{
				st->pb(st, 1);
				st->rb(st, 1);
			}
			return ;
		}
	}
	if (total_size <= 0)
		return ;
	if (total_size == 1)
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
		return ;
	}
	else if (total_size == 2)
	{
		if (dst == A_TOP)
		{
			if (!cmp(st->stack_a->top->value, st->stack_a->top->next->value))
				st->sa(st, 1);
		}
		else if (dst == A_BOTTOM)
		{
			if (cmp(st->stack_a->top->value, st->stack_a->top->next->value))
				st->sa(st, 1);
			st->ra(st, 1);
			st->ra(st, 1);
		}
		else if (dst == B_TOP)
		{
			st->pb(st, 1);
			st->pb(st, 1);
			if (!cmp(st->stack_b->top->value, st->stack_b->top->next->value))
				st->sb(st, 1);
		}
		else if (dst == B_BOTTOM)
		{
			st->pb(st, 1);
			st->pb(st, 1);
			if (cmp(st->stack_b->top->value, st->stack_b->top->next->value))
				st->sb(st, 1);
			st->rb(st, 1);
			st->rb(st, 1);
		}
		return ;
	}
	else if (total_size == 3)
	{
		if (dst == A_TOP)
			manual_sort3(st, cmp);
		else if (dst == A_BOTTOM)
			manual_sort_a_bottom(st, cmp);
		else if (dst == B_TOP)
			manual_sort_b_top(st, cmp);
		else if (dst == B_BOTTOM)
			manual_sort_b_bottom(st, cmp);
		return ;
	}
	else if (total_size <= 8 && 1)
	{
		if (dst == A_TOP)
		{
			sizes[A_BOTTOM] = total_size - total_size / 2;
			sizes[B_TOP] = total_size / 2;
			sizes[B_BOTTOM] = 0;
		}
		else if (dst == A_BOTTOM)
		{
			adv_merge_sort(st, total_size / 2, rcmp, cmp, B_TOP);
			adv_merge_sort(st, total_size - total_size / 2, rcmp, cmp, A_TOP);
			adv_merge_3way(st, (int[4]){total_size - total_size / 2, 0, total_size / 2, 0}, cmp, rcmp, A_BOTTOM);
			return ;
		}
		else if (dst == B_TOP)
		{
			adv_merge_sort(st, total_size - total_size / 2, rcmp, cmp, B_BOTTOM);
			adv_merge_sort(st, total_size / 2, rcmp, cmp, A_TOP);
			adv_merge_3way(st, (int[4]){total_size / 2, 0, 0, total_size - total_size / 2}, cmp, rcmp, B_TOP);
			return ;
		}
		else if (dst == B_BOTTOM)
		{
			adv_merge_sort(st, total_size - total_size / 2, rcmp, cmp, B_TOP);
			adv_merge_sort(st, total_size / 2, rcmp, cmp, A_TOP);
			adv_merge_3way(st, (int[4]){total_size / 2, 0, total_size - total_size / 2, 0}, cmp, rcmp, B_BOTTOM);
			return ;
		}
	}
	if (dst == A_TOP || dst == B_TOP)
		adv_merge_sort(st, sizes[B_BOTTOM], rcmp, cmp, B_BOTTOM);
	else
		adv_merge_sort(st, sizes[B_BOTTOM], cmp, rcmp, B_BOTTOM);
	visualize_ab(st, "merge_sort: B_BOTTOM\n", sizes[B_BOTTOM]);
	if (dst == A_TOP)
		adv_merge_sort(st, sizes[A_BOTTOM], rcmp, cmp, A_BOTTOM);
	else
		adv_merge_sort(st, sizes[A_BOTTOM], cmp, rcmp, A_BOTTOM);
	visualize_ab(st, "merge_sort: A_BOTTOM\n", sizes[A_BOTTOM]);
	if (dst == B_TOP)
		adv_merge_sort(st, sizes[B_TOP], cmp, rcmp, B_TOP);
	else
		adv_merge_sort(st, sizes[B_TOP], rcmp, cmp, B_TOP);
	visualize_ab(st, "merge_sort: B_TOP\n", sizes[B_TOP]);
	adv_merge_3way(st, sizes, cmp, rcmp, dst);
	visualize_ab(st, "merge_sort: merge_3way\n", sizes[A_BOTTOM] + sizes[B_BOTTOM] + sizes[B_TOP]);
}

int	main(int argc, char *argv[])
{
	t_stack_ab	*stack_ab;
	t_dbl_list	*cmd;

	stack_ab = new_t_stack_ab(parse_args(argc, argv), new_t_stack());
	if (stack_ab->stack_a->size <= 8)
	{
		adv_merge_sort(stack_ab, stack_ab->stack_a->size / 2, greater, smaller, B_TOP);
		adv_merge_sort(stack_ab, stack_ab->stack_a->size, smaller, greater, A_TOP);
		adv_merge_3way(stack_ab, (int[4]){0, stack_ab->stack_a->size, stack_ab->stack_b->size, 0}, smaller, greater, A_TOP);
	}
	else
		adv_merge_sort(stack_ab, stack_ab->stack_a->size, smaller, greater, A_TOP);
	cmd = stack_ab->command->bottom;
	while (cmd)
	{
		print_command(cmd->value);
		cmd = cmd->prev;
	}
	stack_ab->destructor(stack_ab);
	return (0);
}
// gcc -Wall -Werror -Wextra -g
	// -fsanitize=address *.c utils/*.c ft_printf/src/*.c libft/*.c
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