/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:26:57 by dowon             #+#    #+#             */
/*   Updated: 2023/06/28 18:46:31 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAP_H
# define PARSE_MAP_H

# include "../fdf_obj/fdf_obj.h"
# include <d_list.h>

typedef struct s_map_data
{
	t_d_list	*nodes;
	int			x;
	int			y;
}	t_map_data;

t_map_data	parse_map(int fd);
t_fdf_obj	*map_data_to_obj(t_map_data map);

#endif