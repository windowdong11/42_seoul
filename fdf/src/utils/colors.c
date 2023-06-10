/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:30:34 by dowon             #+#    #+#             */
/*   Updated: 2023/06/10 18:01:21 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	my_mlx_rgba(
	unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

float	lerp(float p1, float p2, float d1)
{
	return (1-d1)*p1 + d1*p2;
}
