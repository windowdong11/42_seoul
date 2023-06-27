/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgba.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:35:28 by dowon             #+#    #+#             */
/*   Updated: 2023/06/27 18:35:45 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"
#include <libft.h>

/*
@param str string to convert to rgba
@param color converted result
@return [RETURNS 0] : success. If return value is not zero, it has error \n
@return [RETURNS 1] : error \n
*/
int	mlx_parse_hex_rgba(const char *str, t_rgba *color)
{
	const size_t	len = ft_strlen(str);

	if (len <= 2 || 8 < len || !ft_starts_with(str, "0x"))
		return (1);
	str += 2;
	*color = 0;
	while (*str != '\0')
	{
		*color *= 16;
		if ('0' <= *str && *str <= '9')
			*color += *str - '0';
		else if ('a' <= *str && *str <= 'f')
			*color += *str + 10 - 'a';
		else if ('A' <= *str && *str <= 'F')
			*color += *str + 10 - 'A';
		else
			return (1);
		++str;
	}
	*color = *color << 8 | 255;
	return (0);
}
