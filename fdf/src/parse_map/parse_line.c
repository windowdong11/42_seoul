/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:43:22 by dowon             #+#    #+#             */
/*   Updated: 2023/06/28 17:48:31 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"
#include "parse_inner.h"
#include <libft.h>
#include <stdlib.h>

int	parse_node(char *str, t_color_point *point)
{
	char	**words;
	int		z;

	if (ft_strchr(str, ',') != NULL)
	{
		words = ft_split(str, ',');
		if (words == NULL)
			return (1);
		if (words[0] == NULL || words[1] == NULL || words[2] != NULL
			|| (ft_parse_int(words[0], &z)
				|| mlx_parse_hex_rgba(words[1], &point->color)))
		{
			ft_free_split(words, words);
			return (1);
		}
		ft_free_split(words, words);
	}
	else
	{
		if (ft_parse_int(str, &z))
			return (1);
		point->color = my_mlx_rgba(0, 0, 0, 0xff);
	}
	point->point.z = z;
	return (0);
}

static void	set_point_xy(t_color_point *point, int x, int y)
{
	point->point.x = x;
	point->point.y = y;
}

int	parse_line(char *line, t_map_data *map)
{
	char	**splitted;
	int		count;

	count = 0;
	splitted = ft_split(line, ' ');
	if (splitted == NULL)
		return (1);
	while (splitted[count] != NULL)
	{
		if (d_list_push_next(map->nodes, new_d_list(
					malloc(sizeof(t_color_point)), free)) == NULL || parse_node(
				splitted[count], (t_color_point *)map->nodes->next->value))
		{
			ft_free_split(splitted, splitted + count);
			return (1);
		}
		set_point_xy(map->nodes->next->value, count, map->y);
		free(splitted[count++]);
	}
	free(splitted);
	if (count == 0)
		return (1);
	if (map->x == -1)
		map->x = count;
	return (map->x != count);
}
