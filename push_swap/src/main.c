/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:14:56 by dowon             #+#    #+#             */
/*   Updated: 2023/05/25 11:30:16 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include "utils/stack_ab.h"

#include <stdio.h>

void	ft_exit(void)
{
	system("leaks --list -- push_swap");
}

int	main(int argc, char *argv[])
{
	t_stack_ab*const	st = new_t_stack_ab(argc, argv);
	t_dbl_list			*cmd;

	if (st == NULL)
		handle_error("Error\n", EXIT_FAILURE);
	merge_sort(st, st->stack_a->size, DESC, A_TOP);
	cmd = st->command->bottom;
	while (cmd)
	{
		print_command(cmd->value);
		cmd = cmd->prev;
	}
	st->destructor(st);
	atexit(ft_exit);
	return (0);
}