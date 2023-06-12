/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_manageer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:17:05 by dowon             #+#    #+#             */
/*   Updated: 2023/06/11 17:17:16 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ptr_manager.h"

t_smart_manager	*ptr_manager(void)
{
	static t_smart_manager	manager;

	return (&manager);
}
