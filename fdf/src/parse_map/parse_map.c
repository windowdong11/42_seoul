/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:23:14 by dowon             #+#    #+#             */
/*   Updated: 2023/06/27 23:10:00 by dowon            ###   ########.fr       */
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

void	delete_t_map_data(void *ptr)
{
	t_map_data*const	data = ptr;

	if (ptr != NULL)
		smart_free(ptr_manager(), data->nodes);
	free(data);
}

static void	remove_endl(char *str)
{
	while (*str != '\n')
		++str;
	if (*str == '\n')
		*str = '\0';
}

static void	handle_parse_error(char *line, t_d_list *head)
{
	free(line);
	delete_all_d_list(head);
	ft_error();
}

static void	init_map_data(t_map_data *map)
{
	map->nodes = new_d_list(NULL, NULL);
	if (map->nodes == NULL)
		ft_error();
	map->x = -1;
	map->y = 0;
}

t_map_data	parse_map(int fd)
{
	char		*line;
	int			is_last;
	t_map_data	map;

	init_map_data(&map);
	is_last = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (is_last && line != NULL)
			handle_parse_error(line, map.nodes);
		if (line == NULL)
			break ;
		remove_endl(line);
		is_last = ft_strlen(line) == 0;
		if (is_last)
			continue ;
		if (parse_line(line, &map))
			handle_parse_error(line, map.nodes);
		++map.y;
		free(line);
	}
	map.nodes = map.nodes->next;
	free(map.nodes->prev);
	return (map);
}
