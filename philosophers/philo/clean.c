/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:53:16 by dowon             #+#    #+#             */
/*   Updated: 2023/08/27 18:35:06 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

void	clean_all(t_philo_general *data)
{
	int	idx;

	idx = 1;
	while (idx <= data->philo_count)
	{
		pthread_join(data->philosophers[idx].thread, NULL);
		pthread_mutex_destroy(&data->philosophers[idx].eat_mutex);
		pthread_mutex_destroy(data->forks_mutex + idx);
		++idx;
	}
	free(data->philosophers);
	data->philosophers = NULL;
	free(data->forks_mutex);
	data->forks_mutex = NULL;
	pthread_mutex_destroy(&data->finish_mutex);
	pthread_mutex_destroy(&data->print_mutex);
}
