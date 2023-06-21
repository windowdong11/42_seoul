/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:53:04 by dowon             #+#    #+#             */
/*   Updated: 2023/06/19 16:51:25 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"
#include "../fdf_struct/fdf_struct.h"
#include "../utils/float.h"
#include "../utils/angle.h"

void	handle_key_press(mlx_key_data_t keydata, t_fdf *fdf)
{
	if (keydata.key == MLX_KEY_W)
		fdf->d_rad.x = -radf(1.0);
	else if (keydata.key == MLX_KEY_S)
		fdf->d_rad.x = radf(1.0);
	else if (keydata.key == MLX_KEY_A)
		fdf->d_rad.y = -radf(1.0);
	else if (keydata.key == MLX_KEY_D)
		fdf->d_rad.y = radf(1.0);
	else if (keydata.key == MLX_KEY_Q)
		fdf->d_rad.z = -radf(1.0);
	else if (keydata.key == MLX_KEY_E)
		fdf->d_rad.z = radf(1.0);
	else if (keydata.key == MLX_KEY_LEFT)
		fdf->d_pos.x = -1.0;
	else if (keydata.key == MLX_KEY_RIGHT)
		fdf->d_pos.x = 1.0;
	else if (keydata.key == MLX_KEY_UP)
		fdf->d_pos.y = -1.0;
	else if (keydata.key == MLX_KEY_DOWN)
		fdf->d_pos.y = 1.0;
	else if (keydata.key == MLX_KEY_I)
		fdf->d_scale.x = -0.05;
	else if (keydata.key == MLX_KEY_K)
		fdf->d_scale.x = 0.05;
	else if (keydata.key == MLX_KEY_J)
		fdf->d_scale.y = -0.05;
	else if (keydata.key == MLX_KEY_L)
		fdf->d_scale.y = 0.05;
	else if (keydata.key == MLX_KEY_U)
		fdf->d_scale.z = -0.05;
	else if (keydata.key == MLX_KEY_O)
		fdf->d_scale.z = 0.05;
	else if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(fdf->mlx);
	else if (keydata.key == MLX_KEY_1)
		fdf->with_axis = !fdf->with_axis;
	else if (keydata.key == MLX_KEY_2)
		vector3(&fdf->rad, 0.0, 0.0, 0.0);
}

void	handle_key_release(mlx_key_data_t keydata, t_fdf *fdf)
{
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S)
		fdf->d_rad.x = 0.0;
	else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
		fdf->d_rad.y = 0.0;
	else if (keydata.key == MLX_KEY_Q || keydata.key == MLX_KEY_E)
		fdf->d_rad.z = 0.0;
	else if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
		fdf->d_pos.x = 0.0;
	else if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN)
		fdf->d_pos.y = 0.0;
	else if (keydata.key == MLX_KEY_I || keydata.key == MLX_KEY_K)
		fdf->d_scale.x = 0.0;
	else if (keydata.key == MLX_KEY_J || keydata.key == MLX_KEY_L)
		fdf->d_scale.y = 0.0;
	else if (keydata.key == MLX_KEY_U || keydata.key == MLX_KEY_O)
		fdf->d_scale.z = 0.0;
}

void	handle_key_repeat(mlx_key_data_t keydata, t_fdf *fdf)
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
	else if (keydata.key == MLX_KEY_LEFT)
		fdf->d_pos.x = maxf(-fdf->max_dpos.x, fdf->d_pos.x - 1.0);
	else if (keydata.key == MLX_KEY_RIGHT)
		fdf->d_pos.x = minf(fdf->max_dpos.x, fdf->d_pos.x + 1.0);
	else if (keydata.key == MLX_KEY_UP)
		fdf->img->instances[0].x++;
		// fdf->d_pos.y = maxf(-fdf->max_dpos.y, fdf->d_pos.y - 1.0);
	else if (keydata.key == MLX_KEY_DOWN)
		fdf->img->instances[0].x--;
		// fdf->d_pos.y = minf(fdf->max_dpos.y, fdf->d_pos.y + 1.0);
	else if (keydata.key == MLX_KEY_I)
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
