/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:57:07 by dowon             #+#    #+#             */
/*   Updated: 2023/08/28 16:20:53 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	print_take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->finish_mutex);
	if (*philo->is_finished)
		pthread_mutex_unlock(&philo->finish_mutex);
	else
	{
		pthread_mutex_lock(philo->print_mutex);
		printf("%ld %d has taken a fork\n", get_timestamp_ms(), philo->idx);
		pthread_mutex_unlock(philo->print_mutex);
		pthread_mutex_unlock(&philo->finish_mutex);
	}
}

void	print_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->finish_mutex);
	if (*philo->is_finished)
		pthread_mutex_unlock(&philo->finish_mutex);
	else
	{
		pthread_mutex_lock(philo->print_mutex);
		printf("%d %d is eating\n", philo->last_eat_time, philo->idx);
		pthread_mutex_unlock(philo->print_mutex);
		pthread_mutex_unlock(&philo->finish_mutex);
	}
}

void	print_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->finish_mutex);
	if (*philo->is_finished)
		pthread_mutex_unlock(&philo->finish_mutex);
	else
	{
		pthread_mutex_lock(philo->print_mutex);
		printf("%ld %d is sleeping\n", get_timestamp_ms(), philo->idx);
		pthread_mutex_unlock(philo->print_mutex);
		pthread_mutex_unlock(&philo->finish_mutex);
	}
}

void	print_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->finish_mutex);
	if (*philo->is_finished)
		pthread_mutex_unlock(&philo->finish_mutex);
	else
	{
		pthread_mutex_lock(philo->print_mutex);
		printf("%ld %d is thinking\n", get_timestamp_ms(), philo->idx);
		pthread_mutex_unlock(philo->print_mutex);
		pthread_mutex_unlock(&philo->finish_mutex);
	}
}

void	print_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->finish_mutex);
	if (*philo->is_finished)
		pthread_mutex_unlock(&philo->finish_mutex);
	else
	{
		pthread_mutex_lock(philo->print_mutex);
		printf("%ld %d died\n", get_timestamp_ms(), philo->idx);
		*philo->is_finished = 1;
		pthread_mutex_unlock(philo->print_mutex);
		pthread_mutex_unlock(&philo->finish_mutex);
	}
}
