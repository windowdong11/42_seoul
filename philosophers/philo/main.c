/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:04:40 by dowon             #+#    #+#             */
/*   Updated: 2023/08/26 23:15:13 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "philo.h"

int	parse_args(int argc, char *argv[], int result[], int *size);

static void	print_usage(void)
{
	printf("usage: ./philosopher number_of_philosophers \
time_to_die time_to_eat time_to_sleep \
[number_of_times_each_philosopher_must_eat]\n");
}

void	ft_msleep(long ms)
{
	const t_ms		begin = get_timestamp_ms();
	long			left_time;

	while (1)
	{
		left_time = get_timestamp_ms() - begin;
		if (left_time >= ms)
			break ;
		usleep(((ms - left_time) * 1000) / 4);
	}
}

void	*philo_lr(void *args)
{
	t_philo*const	me = (t_philo *)args;

	while (1)
	{
		pthread_mutex_lock(&me->finish_mutex);
		if (me->is_finished)
			return (NULL);
		pthread_mutex_unlock(&me->finish_mutex);
		pthread_mutex_lock(me->left);
		print_take_fork(me);
		pthread_mutex_lock(me->right);
		print_take_fork(me);
		pthread_mutex_lock(&me->eat_mutex);
		me->last_eat_time = get_timestamp_ms();
		++me->eat_cnt;
		pthread_mutex_unlock(&me->eat_mutex);
		print_eat(me);
		ft_msleep(me->time_to_eat);
		pthread_mutex_unlock(me->right);
		pthread_mutex_unlock(me->left);
		print_sleep(me);
		ft_msleep(me->time_to_sleep);
		print_think(me);
	}
	return (NULL);
}

void	*philo_rl(void *args)
{
	t_philo*const	me = (t_philo *)args;

	while (1)
	{
		pthread_mutex_lock(&me->finish_mutex);
		if (me->is_finished)
			return (NULL);
		pthread_mutex_unlock(&me->finish_mutex);
		pthread_mutex_lock(me->right);
		print_take_fork(me);
		pthread_mutex_lock(me->left);
		print_take_fork(me);
		pthread_mutex_lock(&me->eat_mutex);
		me->last_eat_time = get_timestamp_ms();
		++me->eat_cnt;
		pthread_mutex_unlock(&me->eat_mutex);
		print_eat(me);
		ft_msleep(me->time_to_eat);
		pthread_mutex_unlock(me->left);
		pthread_mutex_unlock(me->right);
		print_sleep(me);
		ft_msleep(me->time_to_sleep);
		print_think(me);
	}
	return (NULL);
}

void	run_philosophers(t_philo_general *data)
{
	int	idx;

	printf("start %ld\n", get_timestamp_ms());
	idx = 1;
	while (idx <= data->philo_count)
	{
		pthread_create(&data->philosophers[idx].thread, NULL,
			philo_rl, &data->philosophers[idx]);
		idx += 2;
	}
	idx = 2;
	while (idx <= data->philo_count)
	{
		pthread_create(&data->philosophers[idx].thread, NULL,
			philo_lr, &data->philosophers[idx]);
		idx += 2;
	}
}

int	main(int argc, char *argv[])
{
	int				result[6];
	int				size;
	pthread_t		observer;
	t_philo_general	data;

	if (parse_args(argc, argv, result, &size))
	{
		print_usage();
		return (1);
	}
	init_general(&data, result, size);
	init_timestamp();
	run_philosophers(&data);
	pthread_create(&observer, NULL,
		observe, (void *)&data);
	pthread_join(observer, NULL);
	clean_all(&data);
	return (0);
}
