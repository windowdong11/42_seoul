#include "MLX42/MLX42.h"
typedef struct s_point2d {
	int	x;
	int	y;
}	t_point2d;
void draw8way(t_mlx_image *img)
{
	// top -> right_top
	draw_line(img, (t_point2d){500, 500}, (t_point2d){500, 600});
	draw_line(img, (t_point2d){500, 500}, (t_point2d){530, 600});
	draw_line(img, (t_point2d){500, 500}, (t_point2d){550, 600});
	draw_line(img, (t_point2d){500, 500}, (t_point2d){570, 600});
	// right_top -> right
	draw_line(img, (t_point2d){500, 500}, (t_point2d){600, 600});
	draw_line(img, (t_point2d){500, 500}, (t_point2d){600, 570});
	draw_line(img, (t_point2d){500, 500}, (t_point2d){600, 550});
	draw_line(img, (t_point2d){500, 500}, (t_point2d){600, 530});
	draw_line(img, (t_point2d){500, 500}, (t_point2d){600, 500});
	// right -> bottom_right
	draw_line(img, (t_point2d){500, 500}, (t_point2d){600, 470});
	draw_line(img, (t_point2d){500, 500}, (t_point2d){600, 450});
	draw_line(img, (t_point2d){500, 500}, (t_point2d){600, 430});
	draw_line(img, (t_point2d){500, 500}, (t_point2d){600, 400});
	// bottom_right -> bottom
	draw_line(img, (t_point2d){500, 500}, (t_point2d){570, 400});
	draw_line(img, (t_point2d){500, 500}, (t_point2d){550, 400});
	draw_line(img, (t_point2d){500, 500}, (t_point2d){530, 400});
	draw_line(img, (t_point2d){500, 500}, (t_point2d){500, 400});
	// bottom -> bottom_left
	draw_line(img, (t_point2d){500, 500}, (t_point2d){470, 400});
	draw_line(img, (t_point2d){500, 500}, (t_point2d){450, 400});
	draw_line(img, (t_point2d){500, 500}, (t_point2d){430, 400});
	draw_line(img, (t_point2d){500, 500}, (t_point2d){400, 400});
	// bottom_left -> left
	draw_line(img, (t_point2d){500, 500}, (t_point2d){400, 430});
	draw_line(img, (t_point2d){500, 500}, (t_point2d){400, 450});
	draw_line(img, (t_point2d){500, 500}, (t_point2d){400, 470});
	draw_line(img, (t_point2d){500, 500}, (t_point2d){400, 500});
	// left -> left_top
	draw_line(img, (t_point2d){500, 500}, (t_point2d){400, 530});
	draw_line(img, (t_point2d){500, 500}, (t_point2d){400, 550});
	draw_line(img, (t_point2d){500, 500}, (t_point2d){400, 570});
	draw_line(img, (t_point2d){500, 500}, (t_point2d){400, 600});
	// left_top -> top
	draw_line(img, (t_point2d){500, 500}, (t_point2d){430, 600});
	draw_line(img, (t_point2d){500, 500}, (t_point2d){450, 600});
	draw_line(img, (t_point2d){500, 500}, (t_point2d){470, 600});
	// box
	draw_line(img, (t_point2d){400, 400}, (t_point2d){600, 400});
	draw_line(img, (t_point2d){400, 400}, (t_point2d){400, 600});
	draw_line(img, (t_point2d){400, 600}, (t_point2d){600, 600});
	draw_line(img, (t_point2d){600, 400}, (t_point2d){600, 600});
}