/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:56:52 by dowon             #+#    #+#             */
/*   Updated: 2023/06/10 23:29:29 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "./utils/colors.h"
#include "./mlx_utils/mlx_utils.h"
#include "utils/angle.h"
#include "utils_3d/utils_3d.h"
#include "fdf_obj/fdf_obj.h"
#include "test/test.h"
#include <smart_ptr.h>
#include "MLX42/MLX42.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef	struct s_fdf
{
	int			is_updated;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_fdf_obj	*obj;
	t_vector3	position;
	t_vector3	d_pos;
	t_vector3	d_rad;
	t_vector3	max_dpos;
	t_vector3	max_drad;
}	t_fdf;

// Exit the program as failure.
static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	smart_exit(fdf_obj_manager(), EXIT_FAILURE);
}

// Print the window width and height.
static void	ft_hook(void *param)
{
	t_fdf*const	fdf = param;

	if (fdf->is_updated == 0)
		return ;
	// draw(fdf->img);
	fdf_rotate_x(fdf->obj, fdf->d_rad.x);
	fdf_rotate_y(fdf->obj, fdf->d_rad.y);
	fdf_rotate_z(fdf->obj, fdf->d_rad.z);
	v3_add(&fdf->position, &fdf->position, &fdf->d_pos);
	ft_memset(fdf->img->pixels, 0,
		fdf->img->width * fdf->img->height * sizeof(int));
	fdf_draw_at(fdf->img, fdf->obj, fdf->position);
	// mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
	fdf->is_updated = 0;
}

void	delete_fdf(void *ptr)
{
	t_fdf*const	fdf = ptr;

	if (fdf->img)
		smart_free(fdf_obj_manager(), fdf->img);
	if (fdf->mlx)
		smart_free(fdf_obj_manager(), fdf->mlx);
	if (fdf->obj)
		smart_free(fdf_obj_manager(), fdf->obj);
	free(ptr);
}

t_fdf_obj	*cube()
{
	t_fdf_obj*const obj = new_obj(8, 12);
	if (obj == NULL)
		return (NULL);
	obj->node[0].point = (t_point3d){-25, -25, -25};
	obj->node[1].point = (t_point3d){25, -25, -25};
	obj->node[2].point = (t_point3d){25, 25, -25};
	obj->node[3].point = (t_point3d){-25, 25, -25};
	obj->node[4].point = (t_point3d){-25, -25, 25};
	obj->node[5].point = (t_point3d){25, -25, 25};
	obj->node[6].point = (t_point3d){25, 25, 25};
	obj->node[7].point = (t_point3d){-25, 25, 25};
	obj->edge[0][0] = &obj->node[0];
	obj->edge[0][1] = &obj->node[1];
	obj->edge[1][0] = &obj->node[1];
	obj->edge[1][1] = &obj->node[2];
	obj->edge[2][0] = &obj->node[2];
	obj->edge[2][1] = &obj->node[3];
	obj->edge[3][0] = &obj->node[3];
	obj->edge[3][1] = &obj->node[0];
	obj->edge[4][0] = &obj->node[4];
	obj->edge[4][1] = &obj->node[5];
	obj->edge[5][0] = &obj->node[5];
	obj->edge[5][1] = &obj->node[6];
	obj->edge[6][0] = &obj->node[6];
	obj->edge[6][1] = &obj->node[7];
	obj->edge[7][0] = &obj->node[7];
	obj->edge[7][1] = &obj->node[4];
	obj->edge[8][0] = &obj->node[0];
	obj->edge[8][1] = &obj->node[4];
	obj->edge[9][0] = &obj->node[1];
	obj->edge[9][1] = &obj->node[5];
	obj->edge[10][0] = &obj->node[2];
	obj->edge[10][1] = &obj->node[6];
	obj->edge[11][0] = &obj->node[3];
	obj->edge[11][1] = &obj->node[7];
	return (obj);
}

t_fdf	*fdf_init(int32_t w, int32_t h, const char *title, bool resize)
{
	t_fdf*const	fdf = smart_malloc(fdf_obj_manager(), sizeof(t_fdf),
			delete_fdf);

	fdf->mlx = mlx_init(w, h, title, resize);
	if (!fdf->mlx)
		ft_error();
	fdf->img = mlx_new_image(fdf->mlx, w, h);
	ft_memset(fdf->img->pixels, 0,
		fdf->img->width * fdf->img->height * sizeof(int));
	if (!fdf->img || (mlx_image_to_window(fdf->mlx, fdf->img, 0, 0) < 0))
		ft_error();
	fdf->obj = cube();
	vector3(&fdf->max_drad, radf(2.0), radf(2.0), radf(2.0));
	vector3(&fdf->max_dpos, 10.0, 10.0, 10.0);
	vector3(&fdf->position, 0, 0, 0);
	fdf->is_updated = 0;
	return (fdf);
}

float	max(float n1, float n2)
{
	if (n1 < n2)
		return (n2);
	return (n1);
}
float	min(float n1, float n2)
{
	if (n1 > n2)
		return (n2);
	return (n1);
}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	t_fdf*const	fdf = param;

	if (keydata.action == MLX_PRESS)
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
	}
	else if (keydata.action == MLX_RELEASE)
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
	}
	else if (keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_W)
			fdf->d_rad.x = min(-fdf->max_drad.x, fdf->d_rad.x - radf(0.1));
		else if (keydata.key == MLX_KEY_S)
			fdf->d_rad.x = max(fdf->max_drad.x, fdf->d_rad.x + radf(0.1));
		else if (keydata.key == MLX_KEY_A)
			fdf->d_rad.y = min(-fdf->max_drad.y, fdf->d_rad.y - radf(0.1));
		else if (keydata.key == MLX_KEY_D)
			fdf->d_rad.y = max(fdf->max_drad.y, fdf->d_rad.y + radf(0.1));
		else if (keydata.key == MLX_KEY_Q)
			fdf->d_rad.z = min(-fdf->max_drad.z, fdf->d_rad.z - radf(0.1));
		else if (keydata.key == MLX_KEY_E)
			fdf->d_rad.z = max(fdf->max_drad.z, fdf->d_rad.z + radf(0.1));
		else if (keydata.key == MLX_KEY_LEFT)
			fdf->d_pos.x = min(-fdf->max_dpos.x, fdf->d_pos.x - 1.0);
		else if (keydata.key == MLX_KEY_RIGHT)
			fdf->d_pos.x = max(fdf->max_dpos.x, fdf->d_pos.x + 1.0);
		else if (keydata.key == MLX_KEY_UP)
			fdf->d_pos.y = min(-fdf->max_dpos.y, fdf->d_pos.y - 1.0);
		else if (keydata.key == MLX_KEY_DOWN)
			fdf->d_pos.y = max(fdf->max_dpos.y, fdf->d_pos.y + 1.0);
	}
	fdf->is_updated = 1;
}

int	main(void)
{
	t_fdf*const	fdf = fdf_init(1920, 1080, "fdf", true);

	mlx_key_hook(fdf->mlx, &my_keyhook, fdf);
	mlx_loop_hook(fdf->mlx, ft_hook, fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	return (EXIT_SUCCESS);
}
