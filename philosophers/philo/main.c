/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:04:40 by dowon             #+#    #+#             */
/*   Updated: 2023/08/28 17:20:41 by dowon            ###   ########.fr       */
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
	printf("usage: ./philo number_of_philosophers \
time_to_die time_to_eat time_to_sleep \
[number_of_times_each_philosopher_must_eat]\n");
}

static void	run_philosophers(t_philo_general *data)
{
	int	idx;

	idx = 1;
	while (idx <= data->philo_count)
	{
		pthread_create(&data->philosophers[idx].thread, NULL,
			philo_rl, &data->philosophers[idx]);
		idx += 2;
	}
	if (data->time_to_die > data->time_to_eat)
		usleep(data->time_to_eat * 500);
	else
		usleep(data->time_to_die * 500);
	idx = 2;
	while (idx <= data->philo_count)
	{
		pthread_create(&data->philosophers[idx].thread, NULL,
			philo_rl, &data->philosophers[idx]);
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
	if (result[0] <= 0 || result[1] <= 0 || result[2] <= 0
		|| result[3] <= 0 || (size == 5 && result[4] <= 0))
	{
		printf("arguments should be greater than 0\n");
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
