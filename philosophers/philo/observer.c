/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:08:29 by dowon             #+#    #+#             */
/*   Updated: 2023/08/26 21:50:10 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>

static void	broadcast_finished(t_philo_general *data);

int	check_eat_all(t_philo_general *data)
{
	int	idx;

	if (data->must_eat_cnt < 0)
		return (0);
	idx = 1;
	while (idx < data->philo_count)
	{
		if (data->philosophers[idx].eat_cnt < data->must_eat_cnt)
			return (0);
		++idx;
	}
	return (1);
}

void	*observe(void *arg)
{
	t_philo_general*const	data = arg;
	int						idx;

	while (1)
	{
		idx = 1;
		while (idx <= data->philo_count)
		{
			if (data->philosophers[idx].last_eat_time + data->time_to_die
				<= get_timestamp_ms())
			{
				pthread_mutex_lock(&data->print_mutex);
				if (!data->philosophers[idx].is_finished)
					printf("%ldms %d died\n", get_timestamp_ms(), idx);
				broadcast_finished(data);
				pthread_mutex_unlock(&data->print_mutex);
				return (NULL);
			}
			if (check_eat_all(data))
			{
				pthread_mutex_lock(&data->print_mutex);
				broadcast_finished(data);
				pthread_mutex_unlock(&data->print_mutex);
				return (NULL);
			}
			++idx;
		}
		usleep(1000);
	}
	return (NULL);
}

static void	broadcast_finished(t_philo_general *data)
{
	int	idx;

	idx = 1;
	while (idx <= data->philo_count)
	{
		data->philosophers[idx].is_finished = 1;
		++idx;
	}
	return ;
}
