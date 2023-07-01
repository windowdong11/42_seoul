/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:56:52 by dowon             #+#    #+#             */
/*   Updated: 2023/07/01 22:47:03 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptr_manager/ptr_manager.h"
#include "fdf_struct/fdf_struct.h"
#include "parse_map/parse_map.h"
#include "hooks/hooks.h"
#include "exception/exception.h"
#include <libft.h>
#include <MLX42/MLX42.h>
#include <math.h>
#include <fcntl.h>

static void	loop_hook(void *param)
{
	t_fdf*const	fdf = param;

	if (fdf->is_updated == fdf_rendered)
		return ;
	ft_memset(fdf->img->pixels, 0,
		fdf->img->width * fdf->img->height * sizeof(int));
	fdf_proj(fdf);
	fdf->is_updated = fdf_rendered;
}

static int	is_valid_args(int argc, char *argv[])
{
	return (
		argc == 2
		&& ft_strlen(argv[1]) >= 4
		&& ft_ends_with(argv[1], ".fdf")
	);
}

static void	init_fdf(t_fdf *fdf)
{
	move_coord_to_center(fdf->obj);
	fdf->tmp_obj = dup_fdf_obj(fdf->obj);
	fdf->axis = new_axis((t_vector3){
			fdf->obj->width_x / 2.0f + 3.0f,
			fdf->obj->length_y / 2.0f + 3.0f,
			fabsf(fdf->obj->max_depth_z) + 5.0f});
	fdf->tmp_axis = dup_fdf_obj(fdf->axis);
	isometric(fdf);
	fdf->is_updated = fdf_changed;
}

int	main(int argc, char *argv[])
{
	int			fd;
	t_fdf		*fdf;
	t_map_data	map_data;

	if (!is_valid_args(argc, argv))
		ft_error("Invalid arguments. Run as ex)./fdf test_maps/file_name.fdf\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error("Invalid file.\n");
	map_data = parse_map(fd);
	close(fd);
	fdf = new_fdf(1920, 1080, "fdf", true);
	fdf->obj = map_data_to_obj(map_data);
	init_fdf(fdf);
	mlx_key_hook(fdf->mlx, key_hook, fdf);
	mlx_loop_hook(fdf->mlx, loop_hook, fdf);
	mlx_loop(fdf->mlx);
	smart_exit(ptr_manager(), EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
