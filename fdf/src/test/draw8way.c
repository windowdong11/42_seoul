#include "../utils/colors.h"
#include "../utils_3d/utils_3d.h"
#include "../mlx_utils/mlx_utils.h"
#include <MLX42/MLX42.h>

void draw8way(mlx_image_t *img)
{
	// top -> right_top
	draw_line(img, (int [2]){500, 500}, (int [2]){500, 600}, my_mlx_rgba(255, 0, 0, 255));
	draw_line(img, (int [2]){500, 500}, (int [2]){530, 600}, my_mlx_rgba(255, 0, 0, 255));
	draw_line(img, (int [2]){500, 500}, (int [2]){550, 600}, my_mlx_rgba(255, 0, 0, 255));
	draw_line(img, (int [2]){500, 500}, (int [2]){570, 600}, my_mlx_rgba(255, 0, 0, 255));
	draw_line(img, (int [2]){500, 500}, (int [2]){600, 600}, my_mlx_rgba(255, 0, 0, 255));
	// right_top -> right
	draw_line(img, (int [2]){500, 500}, (int [2]){600, 570}, my_mlx_rgba(255, 255, 0, 255));
	draw_line(img, (int [2]){500, 500}, (int [2]){600, 550}, my_mlx_rgba(255, 255, 0, 255));
	draw_line(img, (int [2]){500, 500}, (int [2]){600, 530}, my_mlx_rgba(255, 255, 0, 255));
	draw_line(img, (int [2]){500, 500}, (int [2]){600, 500}, my_mlx_rgba(255, 255, 0, 255));
	// right -> bottom_right
	draw_line(img, (int [2]){500, 500}, (int [2]){600, 470}, my_mlx_rgba(0, 255, 0, 255));
	draw_line(img, (int [2]){500, 500}, (int [2]){600, 450}, my_mlx_rgba(0, 255, 0, 255));
	draw_line(img, (int [2]){500, 500}, (int [2]){600, 430}, my_mlx_rgba(0, 255, 0, 255));
	draw_line(img, (int [2]){500, 500}, (int [2]){600, 400}, my_mlx_rgba(0, 255, 0, 255));
	// bottom_right -> bottom
	draw_line(img, (int [2]){500, 500}, (int [2]){570, 400}, my_mlx_rgba(0, 255, 255, 255));
	draw_line(img, (int [2]){500, 500}, (int [2]){550, 400}, my_mlx_rgba(0, 255, 255, 255));
	draw_line(img, (int [2]){500, 500}, (int [2]){530, 400}, my_mlx_rgba(0, 255, 255, 255));
	draw_line(img, (int [2]){500, 500}, (int [2]){500, 400}, my_mlx_rgba(0, 255, 255, 255));
	// bottom -> bottom_left
	draw_line(img, (int [2]){500, 500}, (int [2]){470, 400}, my_mlx_rgba(0, 0, 255, 255));
	draw_line(img, (int [2]){500, 500}, (int [2]){450, 400}, my_mlx_rgba(0, 0, 255, 255));
	draw_line(img, (int [2]){500, 500}, (int [2]){430, 400}, my_mlx_rgba(0, 0, 255, 255));
	draw_line(img, (int [2]){500, 500}, (int [2]){400, 400}, my_mlx_rgba(0, 0, 255, 255));
	// bottom_left -> left
	draw_line(img, (int [2]){500, 500}, (int [2]){400, 430}, my_mlx_rgba(255, 0, 255, 255));
	draw_line(img, (int [2]){500, 500}, (int [2]){400, 450}, my_mlx_rgba(255, 0, 255, 255));
	draw_line(img, (int [2]){500, 500}, (int [2]){400, 470}, my_mlx_rgba(255, 0, 255, 255));
	draw_line(img, (int [2]){500, 500}, (int [2]){400, 500}, my_mlx_rgba(255, 0, 255, 255));
	// left -> left_top
	draw_line(img, (int [2]){500, 500}, (int [2]){400, 530}, my_mlx_rgba(255, 0, 0, 255));
	draw_line(img, (int [2]){500, 500}, (int [2]){400, 550}, my_mlx_rgba(255, 0, 0, 255));
	draw_line(img, (int [2]){500, 500}, (int [2]){400, 570}, my_mlx_rgba(255, 0, 0, 255));
	draw_line(img, (int [2]){500, 500}, (int [2]){400, 600}, my_mlx_rgba(255, 0, 0, 255));
	// left_top -> top
	draw_line(img, (int [2]){500, 500}, (int [2]){430, 600}, my_mlx_rgba(255, 255, 0, 255));
	draw_line(img, (int [2]){500, 500}, (int [2]){450, 600}, my_mlx_rgba(255, 255, 0, 255));
	draw_line(img, (int [2]){500, 500}, (int [2]){470, 600}, my_mlx_rgba(255, 255, 0, 255));
	draw_line(img, (int [2]){500, 500}, (int [2]){500, 600}, my_mlx_rgba(255, 255, 0, 255));
	// box
	draw_line(img, (int [2]){400, 400}, (int [2]){600, 400}, my_mlx_rgba(0, 255, 0, 255));
	draw_line(img, (int [2]){400, 400}, (int [2]){400, 600}, my_mlx_rgba(0, 255, 0, 255));
	draw_line(img, (int [2]){400, 600}, (int [2]){600, 600}, my_mlx_rgba(0, 255, 0, 255));
	draw_line(img, (int [2]){600, 400}, (int [2]){600, 600}, my_mlx_rgba(0, 255, 0, 255));
}