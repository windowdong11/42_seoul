/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:23:14 by dowon             #+#    #+#             */
/*   Updated: 2023/06/28 20:15:48 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <get_next_line.h>
#include <libft.h>
#include "../utils/colors.h"
#include "../exception/exception.h"
#include "../ptr_manager/ptr_manager.h"
#include "parse_map.h"
#include "parse_inner.h"

static char	*remove_endl(char *str)
{
	char*const	start = str;

	while (*str != '\0')
	{
		if (*str == '\n')
		{
			*str = '\0';
			break ;
		}
		++str;
	}
	return (start);
}

static void	handle_parse_error(char *line, t_d_list *map_nodes, int fd)
{
	free(line);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	delete_all_d_list(map_nodes);
	ft_error("parse_error\n");
}

static void	init_map_data(t_map_data *map)
{
	map->nodes = new_d_list(NULL, NULL);
	if (map->nodes == NULL)
		ft_error("Failed to alloc memory.\n");
	map->x = -1;
	map->y = 0;
}

static void	remove_dummy_node(t_map_data *map, int fd)
{
	t_d_list	*delete_node;

	if (map->nodes->next == NULL)
		handle_parse_error(NULL, map->nodes, fd);
	delete_node = map->nodes;
	map->nodes = map->nodes->next;
	free(delete_node);
}

t_map_data	parse_map(int fd)
{
	char		*line;
	int			is_last;
	t_map_data	map;

	init_map_data(&map);
	is_last = 0;
	line = NULL;
	while (1)
	{
		free(line);
		line = get_next_line(fd);
		if (is_last && line != NULL)
			handle_parse_error(line, map.nodes, fd);
		if (line == NULL)
			break ;
		is_last = ft_strlen(remove_endl(line)) == 0;
		if (is_last)
			continue ;
		if (parse_line(line, &map))
			handle_parse_error(line, map.nodes, fd);
		++map.y;
	}
	remove_dummy_node(&map, fd);
	return (map);
}
