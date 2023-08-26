/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:08:29 by dowon             #+#    #+#             */
/*   Updated: 2023/08/26 22:36:59 by dowon            ###   ########.fr       */
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

void	*observe(void *arg)
{
	t_philo_general*const	data = arg;
	int						idx;

	while (1)
	{
		idx = 1;
		while (idx <= data->philo_count)
		{
			pthread_mutex_lock(&data->philosophers[idx].eat_mutex);
			if (data->philosophers[idx].last_eat_time + data->time_to_die
				<= get_timestamp_ms())
			{
				pthread_mutex_unlock(&data->philosophers[idx].eat_mutex);
				pthread_mutex_lock(&data->philosophers[idx].finish_mutex);
				if (!data->philosophers[idx].is_finished)
				{
					pthread_mutex_unlock(&data->philosophers[idx].finish_mutex);
					pthread_mutex_lock(&data->print_mutex);
					printf("%ldms %d died\n", get_timestamp_ms(), idx);
					pthread_mutex_unlock(&data->print_mutex);
				}
				else
					pthread_mutex_unlock(&data->philosophers[idx].finish_mutex);
				broadcast_finished(data);
				return (NULL);
			}
			pthread_mutex_unlock(&data->philosophers[idx].eat_mutex);
			if (check_eat_all(data))
			{
				broadcast_finished(data);
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
		pthread_mutex_lock(&data->philosophers[idx].finish_mutex);
		data->philosophers[idx].is_finished = 1;
		pthread_mutex_unlock(&data->philosophers[idx].finish_mutex);
		++idx;
	}
	return ;
}
