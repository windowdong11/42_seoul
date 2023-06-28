/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_adv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:10:37 by dowon             #+#    #+#             */
/*   Updated: 2023/06/28 19:19:08 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include "./gnl_inner.h"
#include <stdlib.h>

t_gnl_fd	*static_gnl_fd(void)
{
	static t_gnl_fd	dummy_fd = {-1, "", 0, NULL, NULL};

	return (&dummy_fd);
}

void	gnl_cleanup(void)
{
	free_gnl_fd(static_gnl_fd()->front);
}
