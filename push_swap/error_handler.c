/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:07:28 by dowon             #+#    #+#             */
/*   Updated: 2023/05/15 18:02:08 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

void	handle_error(char *message, int exit_code)
{
	ft_putstr_fd(message, STDERR_FILENO);
	exit(exit_code);
}
