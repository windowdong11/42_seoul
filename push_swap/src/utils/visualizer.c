/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:06:36 by dowon             #+#    #+#             */
/*   Updated: 2023/05/23 18:33:34 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_ab.h"
#include "ft_printf.h"
#include <stdlib.h>

static void	visualize(t_stack *s)
{
	t_dbl_list	*node;
	long long	idx;

	idx = 0;
	node = s->top;
	if (node == NULL)
	{
		ft_printf("\n");
		return ;
	}
	while (node->prev)
	{
		node = node->prev;
		idx--;
	}
	while (node)
	{
		ft_printf("[%d] %d -> ", idx, node->value);
		node = node->next;
		idx++;
	}
	ft_printf("[END]\n");
}

void	visualize_ab(t_stack_ab *st, const char *prefix, int d)
{
	ft_printf("(%d) %s", d, prefix);
	ft_printf("stack_a: ");
	visualize(st->stack_a);
	ft_printf("stack_b: ");
	visualize(st->stack_b);
}

void	print_command(t_command command)
{
	const char*const	cmd_pre[5] = {
		"", "s", "r", "rr", "p"
	};
	const char*const	cmd_post[3] = {
		"r", "a", "b"
	};

	if (command / 10 == 1 && command % 10 == 0)
		ft_printf("ss\n");
	else
		ft_printf("%s%s\n", cmd_pre[command / 10], cmd_post[command % 10]);
}
