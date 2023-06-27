/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:53:04 by dowon             #+#    #+#             */
/*   Updated: 2023/06/27 20:19:29 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"
#include "handler.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_fdf*const	fdf = param;

	if (keydata.action == MLX_PRESS)
		handle_key_press(keydata, fdf);
	else if (keydata.action == MLX_RELEASE)
		handle_key_release(keydata, fdf);
	else if (keydata.action == MLX_REPEAT)
		handle_key_repeat(keydata, fdf);
	fdf->is_updated = fdf_changed;
}
