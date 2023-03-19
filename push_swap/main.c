/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:14:56 by dowon             #+#    #+#             */
/*   Updated: 2023/03/19 12:53:56 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/include/ft_printf.h"
#include "libft/libft.h"
#include "utils/stack_ab.h"
#include "push_swap.h"
#include <stdlib.h>

// ! Warning : stderr or stdout
void	handle_error(char *message, int exit_code)
{
	ft_printf(message);
	exit(exit_code);
}

int	main(int argc, char *argv[])
{
	is_valid_args(argc, argv);
	return (0);
}
