/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_inner.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:04:10 by dowon             #+#    #+#             */
/*   Updated: 2023/06/27 23:09:25 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_INNER_H
# define PARSE_INNER_H

# include "parse_map.h"

int			parse_line(char *line, t_map_data *map);
t_fdf_obj	*map_data_to_obj(t_map_data map);
int			mlx_parse_hex_rgba(const char *str, t_rgba *color);

#endif