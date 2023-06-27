/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_press.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:03:23 by dowon             #+#    #+#             */
/*   Updated: 2023/06/27 20:19:19 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handler.h"
#include "../utils/float.h"
#include "../utils/angle.h"

static void	handle_press_angle(mlx_key_data_t keydata, t_fdf *fdf)
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
}

static void	handle_press_position(mlx_key_data_t keydata, t_fdf *fdf)
{
	if (keydata.key == MLX_KEY_LEFT)
		fdf->d_pos.x = -1.0;
	else if (keydata.key == MLX_KEY_RIGHT)
		fdf->d_pos.x = 1.0;
	else if (keydata.key == MLX_KEY_UP)
		fdf->d_pos.y = -1.0;
	else if (keydata.key == MLX_KEY_DOWN)
		fdf->d_pos.y = 1.0;
}

static void	handle_press_scale(mlx_key_data_t keydata, t_fdf *fdf)
{
	if (keydata.key == MLX_KEY_I)
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
}

static void	handle_press_views(mlx_key_data_t keydata, t_fdf *fdf)
{
	if (keydata.key == MLX_KEY_1)
		fdf->with_axis = !fdf->with_axis;
	else if (keydata.key == MLX_KEY_2)
		isometric(fdf);
	else if (keydata.key == MLX_KEY_3)
		vector3(&fdf->rad, 0.0, 0.0, 0.0);
	else if (keydata.key == MLX_KEY_4)
		vector3(&fdf->rad, 90.0f, 0.0, 0.0);
	else if (keydata.key == MLX_KEY_5)
		vector3(&fdf->rad, 0.0, 90.0f, 0.0);
	else if (keydata.key == MLX_KEY_6)
		vector3(&fdf->rad, 0.0, 0.0, 90.0f);
}

void	handle_key_press(mlx_key_data_t keydata, t_fdf *fdf)
{
	handle_press_angle(keydata, fdf);
	handle_press_position(keydata, fdf);
	handle_press_scale(keydata, fdf);
	handle_press_views(keydata, fdf);
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(fdf->mlx);
}
