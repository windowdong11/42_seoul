/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:06:13 by dowon             #+#    #+#             */
/*   Updated: 2023/06/25 20:52:21 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fdf_struct.h"
#include "../utils/angle.h"
#include "../exception/exception.h"
#include "../ptr_manager/ptr_manager.h"

t_fdf	*new_fdf(int32_t w, int32_t h, const char *title, bool resize)
{
	t_fdf*const	fdf = smart_malloc(ptr_manager(), sizeof(t_fdf),
			delete_fdf);

	if (fdf == NULL)
		ft_error();
	fdf->with_axis = 0;
	fdf->axis = NULL;
	fdf->tmp_axis = NULL;
	fdf->obj = NULL;
	fdf->tmp_obj = NULL;
	fdf->mlx = mlx_init(w, h, title, resize);
	if (!fdf->mlx)
		ft_error();
	fdf->img = mlx_new_image(fdf->mlx, w, h);
	ft_memset(fdf->img->pixels, 0,
		fdf->img->width * fdf->img->height * sizeof(int));
	if (!fdf->img || (mlx_image_to_window(fdf->mlx, fdf->img, 0, 0) < 0))
		ft_error();
	vector3(&fdf->rad, 0.0f, 0.0f, 0.0f);
	vector3(&fdf->d_rad, 0.0f, 0.0f, 0.0f);
	vector3(&fdf->max_drad, radf(1.0f), radf(1.0f), radf(1.0f));
	vector3(&fdf->position, 0.0f, 0.0f, 0.0f);
	vector3(&fdf->d_pos, 0.0f, 0.0f, 0.0f);
	vector3(&fdf->max_dpos, 10.0f, 10.0f, 10.0f);
	vector3(&fdf->scale, 1.0f, 1.0f, 1.0f);
	vector3(&fdf->d_scale, 0.0f, 0.0f, 0.0f);
	vector3(&fdf->max_dscale, 1.5f, 1.5f, 0.15f);
	fdf->is_updated = 1;
	return (fdf);
}
#include <stdio.h>
void	delete_fdf(void *ptr)
{
	t_fdf*const	fdf = ptr;

	if (fdf->img)
		smart_free(ptr_manager(), fdf->img);
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
