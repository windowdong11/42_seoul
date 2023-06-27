/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_release.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:13:56 by dowon             #+#    #+#             */
/*   Updated: 2023/06/27 20:20:07 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handler.h"
#include "../utils/float.h"
#include "../utils/angle.h"

static void	handle_release_angle(mlx_key_data_t keydata, t_fdf *fdf)
{
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S)
		fdf->d_rad.x = 0.0;
	else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
		fdf->d_rad.y = 0.0;
	else if (keydata.key == MLX_KEY_Q || keydata.key == MLX_KEY_E)
		fdf->d_rad.z = 0.0;
}

static void	handle_release_position(mlx_key_data_t keydata, t_fdf *fdf)
{
	if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
		fdf->d_pos.x = 0.0;
	else if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN)
		fdf->d_pos.y = 0.0;
}

static void	handle_release_scale(mlx_key_data_t keydata, t_fdf *fdf)
{
	if (keydata.key == MLX_KEY_I || keydata.key == MLX_KEY_K)
		fdf->d_scale.x = 0.0;
	else if (keydata.key == MLX_KEY_J || keydata.key == MLX_KEY_L)
		fdf->d_scale.y = 0.0;
	else if (keydata.key == MLX_KEY_U || keydata.key == MLX_KEY_O)
		fdf->d_scale.z = 0.0;
}

void	handle_key_release(mlx_key_data_t keydata, t_fdf *fdf)
{
	handle_release_angle(keydata, fdf);
	handle_release_position(keydata, fdf);
	handle_release_scale(keydata, fdf);
}
