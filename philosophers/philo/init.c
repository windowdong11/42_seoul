/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:28:35 by dowon             #+#    #+#             */
/*   Updated: 2023/08/31 15:34:03 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

static void	init_philosophers(t_philo_general *data);
static void	init_forks(t_philo_general *data);

void	init_general(t_philo_general *data, int result[6], int size)
{
	data->philo_count = result[0];
	data->time_to_die = result[1];
	data->time_to_eat = result[2];
	data->time_to_sleep = result[3];
	data->is_finished = 0;
	data->must_eat_cnt = -1;
	if (size == 5)
		data->must_eat_cnt = result[4];
	data->philosophers = malloc(sizeof(t_philo) * (result[0] + 1));
	data->forks_mutex = malloc(sizeof(pthread_mutex_t) * (result[0] + 1));
	data->forks = malloc(sizeof(int) * (result[0] + 1));
	init_philosophers(data);
	init_forks(data);
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->finish_mutex, NULL);
}

static void	init_philosophers(t_philo_general *data)
{
	t_philo*const	philosophers = data->philosophers;
	int				idx;

	idx = 1;
	while (idx <= data->philo_count)
	{
		philosophers[idx].idx = idx;
		philosophers[idx].is_finished = &data->is_finished;
		philosophers[idx].eat_cnt = 0;
		philosophers[idx].left_mutex = &data->forks_mutex[idx];
		philosophers[idx].right_mutex
			= &data->forks_mutex[idx % data->philo_count + 1];
		philosophers[idx].left_fork = &data->forks[idx];
		philosophers[idx].right_fork
			= &data->forks[idx % data->philo_count + 1];
		philosophers[idx].print_mutex = &data->print_mutex;
		philosophers[idx].finish_mutex = &data->finish_mutex;
		pthread_mutex_init(&philosophers[idx].eat_mutex, NULL);
		philosophers[idx].last_eat_time = 0;
		philosophers[idx].time_to_die = data->time_to_die;
		philosophers[idx].time_to_eat = data->time_to_eat;
		philosophers[idx].time_to_sleep = data->time_to_sleep;
		philosophers[idx].must_eat_cnt = data->must_eat_cnt;
		++idx;
	}
}

static void	init_forks(t_philo_general *data)
{
	pthread_mutex_t*const	forks = data->forks_mutex;
	int						idx;

	idx = 1;
	while (idx <= data->philo_count)
	{
		data->forks[idx] = 0;
		pthread_mutex_init(&forks[idx], NULL);
		idx++;
	}
}
