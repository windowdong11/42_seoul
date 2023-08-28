/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:08:29 by dowon             #+#    #+#             */
/*   Updated: 2023/08/28 16:50:48 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>

int	check_eat_all(t_philo_general *data)
{
	int	idx;

	if (data->must_eat_cnt < 0)
		return (0);
	idx = 1;
	while (idx < data->philo_count)
	{
		pthread_mutex_lock(&data->philosophers[idx].eat_mutex);
		if (data->philosophers[idx].eat_cnt < data->must_eat_cnt)
		{
			pthread_mutex_unlock(&data->philosophers[idx].eat_mutex);
			return (0);
		}
		pthread_mutex_unlock(&data->philosophers[idx].eat_mutex);
		++idx;
	}
	return (1);
}

void	lock_all_finish(t_philo_general	*data)
{
	int	idx;

	idx = 1;
	while (idx <= data->philo_count)
	{
		pthread_mutex_lock(&data->philosophers[idx].finish_mutex);
		++idx;
	}
}

void	unlock_all_finish(t_philo_general	*data)
{
	int	idx;

	idx = 1;
	while (idx <= data->philo_count)
	{
		pthread_mutex_unlock(&data->philosophers[idx].finish_mutex);
		++idx;
	}
}

static int	anyone_dead(t_philo_general *data)
{
	int	idx;

	idx = 1;
	while (idx <= data->philo_count)
	{
		pthread_mutex_lock(&data->philosophers[idx].eat_mutex);
		if (data->philosophers[idx].last_eat_time + data->time_to_die
			< get_timestamp_ms())
		{
			pthread_mutex_unlock(&data->philosophers[idx].eat_mutex);
			lock_all_finish(data);
			data->is_finished = 1;
			printf("%ld %d died\n", get_timestamp_ms(), idx);
			unlock_all_finish(data);
			return (1);
		}
		pthread_mutex_unlock(&data->philosophers[idx].eat_mutex);
		++idx;
	}
	return (0);
}

void	*observe(void *arg)
{
	t_philo_general*const	data = arg;

	usleep(3000);
	while (1)
	{
		if (anyone_dead(data))
			return (NULL);
		if (check_eat_all(data))
		{
			lock_all_finish(data);
			data->is_finished = 1;
			unlock_all_finish(data);
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}
