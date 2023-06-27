/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:16:34 by dowon             #+#    #+#             */
/*   Updated: 2023/06/27 20:18:17 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLER_H
# define HANDLER_H

# include <MLX42/MLX42.h>
# include "../fdf_struct/fdf_struct.h"

void	handle_key_press(mlx_key_data_t keydata, t_fdf *fdf);
void	handle_key_release(mlx_key_data_t keydata, t_fdf *fdf);
void	handle_key_repeat(mlx_key_data_t keydata, t_fdf *fdf);

#endif