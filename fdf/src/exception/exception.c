/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:11:49 by dowon             #+#    #+#             */
/*   Updated: 2023/06/28 19:00:05 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42/MLX42.h>
#include <stdlib.h>
#include <libft.h>
#include <smart_ptr.h>
#include "../ptr_manager/ptr_manager.h"

/* ft_putstr_fd(mlx_strerror(mlx_errno), STDERR_FILENO); */
void	ft_error(const char *msg)
{
	ft_putstr_fd("[Error] : ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	smart_exit(ptr_manager(), EXIT_FAILURE);
}
