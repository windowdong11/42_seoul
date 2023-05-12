/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 22:28:36 by dowon             #+#    #+#             */
/*   Updated: 2023/05/12 22:37:32 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_ab.h"
#include <stdlib.h>

int	is_a_command(t_command command)
{
	if (command == PB)
		return (1);
	if (command % 10 == 0 || command % 10 == 1)
		return (1);
	return (0);
}

int	is_b_command(t_command command)
{
	if (command == PA)
		return (1);
	if (command % 10 == 0 || command % 10 == 2)
		return (1);
	return (0);
}

int	(*get_command_group(t_command command))(t_command command)
{
	if (is_a_command(command))
		return (is_a_command);
	return (is_b_command);
}

static int	find_n_remove_revcmd_from_history(
		t_stack_ab *this, t_command command, t_command rev_command)
{
	t_dbl_list	*node;
	t_dbl_list	*tmp;

	node = this->command->top;
	while (node->next && !get_command_group(command)(node->value))
	{
		if ((t_command)node->next->value == rev_command)
		{
			if (this->command->bottom == node->next)
				this->command->bottom = node;
			tmp = node->pop_next(node);
			tmp->destructor(tmp);
			return (1);
		}
		node = node->next;
	}
	return (0);
}

int	remove_rev_cmd(t_stack_ab *this, t_command command, int view_history)
{
	const t_command		rev_commands[5][3] = {{NONE, NONE, NONE}, {SS, SA, SB},
	{RRR, RRA, RRB}, {RR, RA, RB}, {NONE, PB, PA}};
	const t_command		rev_command = rev_commands[command / 10][command % 10];
	const t_dbl_list	*node = this->command->top;
	t_dbl_list			*tmp;

	if (node == NULL)
		return (0);
	if ((t_command)node->value == rev_command)
	{
		tmp = this->command->pop(this->command);
		tmp->destructor(tmp);
		return (1);
	}
	if (view_history == 0)
		return (0);
	return (find_n_remove_revcmd_from_history(this, command, rev_command));
}
