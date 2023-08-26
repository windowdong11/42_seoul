/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:54:32 by dowon             #+#    #+#             */
/*   Updated: 2023/08/26 18:54:04 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

static t_ms	*start_time(void)
{
	static t_ms	time = 0;

	return (&time);
}

static t_ms	get_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	init_timestamp(void)
{
	*start_time() = get_ms();
}

t_ms	get_timestamp_ms(void)
{
	return (get_ms() - *start_time());
}
