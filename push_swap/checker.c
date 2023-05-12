/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:08:57 by dowon             #+#    #+#             */
/*   Updated: 2023/05/12 21:12:47 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/include/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"
#include "utils/stack_ab.h"
#include <stdlib.h>

void	handle_error(char *message, int exit_code)
{
	ft_printf(message);
	exit(exit_code);
}

int	main(int argc, char *argv[])
{
	t_stack_ab	*stack_ab;
	t_dbl_list	*cmd;

	stack_ab = new_t_stack_ab(parse_args(argc, argv), new_t_stack());
	// while (read(STDIN_FILENO, ))
	stack_ab->destructor(stack_ab);
	return (0);
}
