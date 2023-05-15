/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:08:57 by dowon             #+#    #+#             */
/*   Updated: 2023/05/15 14:46:23 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/include/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"
#include "utils/stack_ab.h"
#include "ft_get_next_line/get_next_line.h"
#include <stdlib.h>

void	handle_error(char *message, int exit_code)
{
	ft_putstr_fd(message, STDERR_FILENO);
	exit(exit_code);
}

int	handle_cmd(char *str, t_stack_ab *st)
{
	const int	len = ft_strlen(str);

	if (!((len == 3 || len == 4) && (str[len - 1] == '\n')))
		return (0);
	if (str[0] == 'p')
	{
		if (str[1] == 'a')
			st->pa(st, 0);
		else if (str[1] == 'b')
			st->pb(st, 0);
	}
	else if (str[0] == 's')
	{
		if (str[1] == 'a')
			st->sa(st, 0);
		else if (str[1] == 'b')
			st->sb(st, 0);
		else if (str[1] == 's')
			st->ss(st, 0);
	}
	else if (str[0] == 'r')
	{
		if (str[1] == 'a')
			st->ra(st, 0);
		else if (str[1] == 'b')
			st->rb(st, 0);
		else if (str[1] == 'r')
		{
			if (str[2] == '\n')
				st->rr(st, 0);
			else if (str[2] == 'a')
				st->rra(st, 0);
			else if (str[2] == 'b')
				st->rrb(st, 0);
			else if (str[2] == 'r')
				st->rrr(st, 0);
		}
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack_ab	*stack_ab;
	char		*str;

	stack_ab = new_t_stack_ab(parse_args(argc, argv), new_t_stack());
	str = get_next_line(STDIN_FILENO);
	while (str)
	{
		if (handle_cmd(str, stack_ab) == 0)
		{
			free(str);
			handle_error("Error\n", EXIT_FAILURE);
			return (0);
		}
		free(str);
		str = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(stack_ab, get_cmp(DESC), stack_ab->stack_a->size))
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	stack_ab->destructor(stack_ab);
	return (0);
}
