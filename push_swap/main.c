/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:14:56 by dowon             #+#    #+#             */
/*   Updated: 2023/03/31 11:42:34 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/include/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"
#include "utils/stack_ab.h"
#include <stdlib.h>
#include <stdio.h>

// ! Warning : stderr or stdout
void	handle_error(char *message, int exit_code)
{
	ft_printf(message);
	exit(exit_code);
}

void merge_sort(t_stack_ab* st)
{
	const int	total_size = st->stack_a->size;
	int			idx;

	idx = 0;
	while (idx < total_size / 3)
	{
		st->pb(st);
		st->rb(st);
	}
	idx = 0;
	while (idx < total_size / 3)
		st->pb(st);
	idx = 0;
	while (idx < total_size - total_size / 3 * 2)
		st->ra(st);
}

int	main(int argc, char *argv[])
{
	t_stack_ab	*stack_ab;

	ft_printf("TODO : print error message to stderr\n");
	stack_ab = new_t_stack_ab(parse_args(argc, argv), new_t_stack());
	merge_sort(stack_ab);
	stack_ab->destructor(stack_ab);
	return (0);
}
// gcc -Wall -Werror -Wextra -g -fsanitize=address *.c utils/*.c ft_printf/libftprintf.a libft/libft.a
