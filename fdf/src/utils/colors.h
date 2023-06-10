/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:31:30 by dowon             #+#    #+#             */
/*   Updated: 2023/06/10 18:00:23 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include <stdint.h>

typedef uint32_t	t_rgba;
t_rgba	my_mlx_rgba(unsigned char r,
			unsigned char g, unsigned char b, unsigned char a);
float	lerp(float p1, float p2, float d1);

#endif