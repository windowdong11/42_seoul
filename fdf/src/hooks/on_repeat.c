/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_repeat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:11:47 by dowon             #+#    #+#             */
/*   Updated: 2023/06/27 20:19:16 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handler.h"
#include "../utils/float.h"
#include "../utils/angle.h"

static void	handle_repeat_angle(mlx_key_data_t keydata, t_fdf *fdf)
{
	if (keydata.key == MLX_KEY_W)
		fdf->d_rad.x = maxf(-fdf->max_drad.x, fdf->d_rad.x - radf(0.1));
	else if (keydata.key == MLX_KEY_S)
		fdf->d_rad.x = minf(fdf->max_drad.x, fdf->d_rad.x + radf(0.1));
	else if (keydata.key == MLX_KEY_A)
		fdf->d_rad.y = maxf(-fdf->max_drad.y, fdf->d_rad.y - radf(0.1));
	else if (keydata.key == MLX_KEY_D)
		fdf->d_rad.y = minf(fdf->max_drad.y, fdf->d_rad.y + radf(0.1));
	else if (keydata.key == MLX_KEY_Q)
		fdf->d_rad.z = maxf(-fdf->max_drad.z, fdf->d_rad.z - radf(0.1));
	else if (keydata.key == MLX_KEY_E)
		fdf->d_rad.z = minf(fdf->max_drad.z, fdf->d_rad.z + radf(0.1));
}

static void	handle_repeat_position(mlx_key_data_t keydata, t_fdf *fdf)
{
	if (keydata.key == MLX_KEY_LEFT)
		fdf->d_pos.x = maxf(-fdf->max_dpos.x, fdf->d_pos.x - 1.0);
	else if (keydata.key == MLX_KEY_RIGHT)
		fdf->d_pos.x = minf(fdf->max_dpos.x, fdf->d_pos.x + 1.0);
	else if (keydata.key == MLX_KEY_UP)
		fdf->d_pos.y = maxf(-fdf->max_dpos.y, fdf->d_pos.y - 1.0);
	else if (keydata.key == MLX_KEY_DOWN)
		fdf->d_pos.y = minf(fdf->max_dpos.y, fdf->d_pos.y + 1.0);
}

static void	handle_repeat_scale(mlx_key_data_t keydata, t_fdf *fdf)
{
	if (keydata.key == MLX_KEY_I)
		fdf->d_scale.x = maxf(-fdf->max_dscale.x, fdf->d_scale.x - 0.01);
	else if (keydata.key == MLX_KEY_K)
		fdf->d_scale.x = minf(fdf->max_dscale.x, fdf->d_scale.x + 0.01);
	else if (keydata.key == MLX_KEY_J)
		fdf->d_scale.y = maxf(-fdf->max_dscale.y, fdf->d_scale.y - 0.01);
	else if (keydata.key == MLX_KEY_L)
		fdf->d_scale.y = minf(fdf->max_dscale.y, fdf->d_scale.y + 0.01);
	else if (keydata.key == MLX_KEY_U)
		fdf->d_scale.z = maxf(-fdf->max_dscale.z, fdf->d_scale.z - 0.01);
	else if (keydata.key == MLX_KEY_O)
		fdf->d_scale.z = minf(fdf->max_dscale.z, fdf->d_scale.z + 0.01);
}

void	handle_key_repeat(mlx_key_data_t keydata, t_fdf *fdf)
{
	handle_repeat_angle(keydata, fdf);
	handle_repeat_position(keydata, fdf);
	handle_repeat_scale(keydata, fdf);
}
