/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:11:49 by dowon             #+#    #+#             */
/*   Updated: 2023/06/11 17:35:37 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42/MLX42.h>
#include <stdlib.h>
#include <libft.h>
#include <smart_ptr.h>
#include "../ptr_manager/ptr_manager.h"

void	ft_error(void)
{
	ft_putstr_fd(mlx_strerror(mlx_errno), STDERR_FILENO);
	smart_clean(ptr_manager());
	exit(EXIT_FAILURE);
}
