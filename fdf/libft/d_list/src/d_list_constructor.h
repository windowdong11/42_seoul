/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_list_constructor.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:27:46 by dowon             #+#    #+#             */
/*   Updated: 2023/06/27 20:28:46 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef D_LIST_CONSTRUCTOR_H
# define D_LIST_CONSTRUCTOR_H
# include "../d_list.h"

void	init_d_list(t_d_list *this, void *value, t_destructor destructor);
void	delete_d_list(t_d_list *this);

#endif