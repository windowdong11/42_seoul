#ifndef FDF_H
# define FDF_H

# include "MLX42/MLX42.h"
typedef struct s_point2d {
	int	x;
	int	y;
}	t_point2d;
void	draw_line(mlx_image_t *img, int p1[2], int p2[2], t_rgba color);
void draw8way(mlx_image_t *img);
#endif