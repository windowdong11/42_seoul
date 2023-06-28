/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:06:13 by dowon             #+#    #+#             */
/*   Updated: 2023/06/28 19:28:33 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fdf_struct.h"
#include "../utils/angle.h"
#include "../exception/exception.h"
#include "../ptr_manager/ptr_manager.h"

t_fdf	*new_fdf(int32_t w, int32_t h, const char *title, bool resize)
{
	t_fdf*const	fdf = smart_malloc(ptr_manager(), sizeof(t_fdf), delete_fdf);

	if (fdf == NULL)
		ft_error("malloc error\n");
	ft_bzero(fdf, sizeof(t_fdf));
	fdf->mlx = mlx_init(w, h, title, resize);
	if (fdf->mlx == NULL)
		ft_error("mlx init failed\n");
	fdf->img = mlx_new_image(fdf->mlx, w, h);
	if (fdf->img == NULL || (mlx_image_to_window(fdf->mlx, fdf->img, 0, 0) < 0))
		ft_error("mlx image creation failed\n");
	ft_memset(fdf->img->pixels, 0,
		fdf->img->width * fdf->img->height * sizeof(int));
	fdf->with_axis = 0;
	vector3(&fdf->rad, 0.0f, 0.0f, 0.0f);
	vector3(&fdf->d_rad, 0.0f, 0.0f, 0.0f);
	vector3(&fdf->max_drad, radf(1.0f), radf(1.0f), radf(1.0f));
	vector3(&fdf->position, 0.0f, 0.0f, 0.0f);
	vector3(&fdf->d_pos, 0.0f, 0.0f, 0.0f);
	vector3(&fdf->max_dpos, 10.0f, 10.0f, 10.0f);
	vector3(&fdf->scale, 1.0f, 1.0f, 1.0f);
	vector3(&fdf->d_scale, 0.0f, 0.0f, 0.0f);
	vector3(&fdf->max_dscale, 1.5f, 1.5f, 0.15f);
	fdf->is_updated = fdf_changed;
	return (fdf);
}

void	delete_fdf(void *ptr)
{
	t_fdf*const	fdf = ptr;

	if (fdf->img)
		mlx_delete_image(fdf->mlx, fdf->img);
	if (fdf->mlx)
		mlx_terminate(fdf->mlx);
	if (fdf->obj)
		smart_free(ptr_manager(), fdf->obj);
	if (fdf->tmp_obj)
		smart_free(ptr_manager(), fdf->tmp_obj);
	if (fdf->axis)
		smart_free(ptr_manager(), fdf->axis);
	if (fdf->tmp_axis)
		smart_free(ptr_manager(), fdf->tmp_axis);
	free(ptr);
}
