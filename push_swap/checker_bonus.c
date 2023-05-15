/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:08:57 by dowon             #+#    #+#             */
/*   Updated: 2023/05/15 22:05:56 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/include/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"
#include "utils/stack_ab.h"
#include "get_next_line/get_next_line.h"
#include <stdlib.h>

t_stack_ab_method	get_rotate_method(t_stack_ab *st, char *cmd)
{
	if (cmd[1] == 'a' && cmd[2] == '\n')
		return (st->ra);
	else if (cmd[1] == 'b' && cmd[2] == '\n')
		return (st->rb);
	else if (cmd[1] == 'r')
	{
		if (cmd[2] == '\n')
			return (st->rr);
		else if (cmd[3] != '\n')
			return (NULL);
		else if (cmd[2] == 'a')
			return (st->rra);
		else if (cmd[2] == 'b')
			return (st->rrb);
		else if (cmd[2] == 'r')
			return (st->rrr);
	}
	return (NULL);
}

t_stack_ab_method	get_swap_method(t_stack_ab *st, char *cmd)
{
	if (cmd[2] != '\n')
		return (NULL);
	if (cmd[1] == 'a')
		return (st->sa);
	else if (cmd[1] == 'b')
		return (st->sb);
	else if (cmd[1] == 's')
		return (st->ss);
	return (NULL);
}

t_stack_ab_method	get_pop_method(t_stack_ab *st, char *cmd)
{
	if (cmd[2] != '\n')
		return (NULL);
	if (cmd[1] == 'a')
		return (st->pa);
	else if (cmd[1] == 'b')
		return (st->pb);
	return (NULL);
}

int	handle_cmd(t_stack_ab *st, char *cmd)
{
	const int			len = ft_strlen(cmd);
	t_stack_ab_method	method;

	method = NULL;
	if (len == 3 && cmd[0] == 'p')
		method = get_pop_method(st, cmd);
	else if (len == 3 && cmd[0] == 's')
		method = get_swap_method(st, cmd);
	else if (cmd[0] == 'r')
		method = get_rotate_method(st, cmd);
	if (method == NULL)
		return (0);
	method(st, 0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack_ab*const	stack_ab = new_t_stack_ab(argc, argv);
	char				*cmd;

	if (stack_ab == NULL)
		handle_error("Error\n", EXIT_FAILURE);
	cmd = get_next_line(STDIN_FILENO);
	while (cmd)
	{
		if (handle_cmd(stack_ab, cmd) == 0)
		{
			free(cmd);
			handle_error("Error\n", EXIT_FAILURE);
			return (0);
		}
		free(cmd);
		cmd = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(stack_ab->stack_a, get_cmp(DESC), stack_ab->stack_a->size)
		&& stack_ab->stack_b->size == 0)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	stack_ab->destructor(stack_ab);
	return (0);
}
