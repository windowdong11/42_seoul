/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:07:09 by dowon             #+#    #+#             */
/*   Updated: 2023/06/21 14:58:54 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../smart_ptr.h"

void	smart_init(t_smart_manager*const manager)
{
	manager->head.next = NULL;
	manager->head.destructor = NULL;
	manager->head.ptr = NULL;
}
