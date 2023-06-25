/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:48:15 by dowon             #+#    #+#             */
/*   Updated: 2023/06/25 20:09:51 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_obj.h"
#include "../mlx_utils/mlx_utils.h"
#include <math.h>

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:17:14 by dowon             #+#    #+#             */
/*   Updated: 2023/06/25 17:33:31 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_utils/mlx_utils.h"
#include "../utils/swap.h"
#include <stdlib.h>
#include <libft.h>

void	fdf_draw(mlx_image_t *img, t_fdf_obj *obj)
{
	size_t	i;

	i = 0;
	while (i < obj->cnt_edge)
	{
		draw_line3d(img,
			obj->edge[i][0]->point, obj->edge[i][1]->point,
			my_mlx_rgba(125, 125, 0, 255));
		++i;
	}
}

void	fdf_draw_at(mlx_image_t *img, t_fdf_obj *obj, t_vector3 at)
{
	fdf_translate(obj, at);
	fdf_draw(img, obj);
	fdf_translate(obj, *v3_negate(&at, &at));
}
