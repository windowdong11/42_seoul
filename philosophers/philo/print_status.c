/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:57:07 by dowon             #+#    #+#             */
/*   Updated: 2023/08/26 22:45:03 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	print_take_fork(t_philo *philo)
{
	// pthread_mutex_lock(&philo->finish_mutex);
	if (philo->is_finished)
		return ;
		// pthread_mutex_unlock(&philo->finish_mutex);
	else
	{
		// pthread_mutex_unlock(&philo->finish_mutex);
		pthread_mutex_lock(philo->print_mutex);
		printf("%ldms %d has taken a fork\n", get_timestamp_ms(), philo->idx);
		pthread_mutex_unlock(philo->print_mutex);
	}
}

void	print_eat(t_philo *philo)
{
	// pthread_mutex_lock(&philo->finish_mutex);
	if (philo->is_finished)
		return ;
		// pthread_mutex_unlock(&philo->finish_mutex);
	else
	{
		// pthread_mutex_unlock(&philo->finish_mutex);
		pthread_mutex_lock(philo->print_mutex);
		printf("%dms %d is eating\n", philo->last_eat_time, philo->idx);
		pthread_mutex_unlock(philo->print_mutex);
	}
}

void	print_sleep(t_philo *philo)
{
	// pthread_mutex_lock(&philo->finish_mutex);
	if (philo->is_finished)
		return ;
		// pthread_mutex_unlock(&philo->finish_mutex);
	else
	{
		// pthread_mutex_unlock(&philo->finish_mutex);
		pthread_mutex_lock(philo->print_mutex);
		printf("%ldms %d is sleeping\n", get_timestamp_ms(), philo->idx);
		pthread_mutex_unlock(philo->print_mutex);
	}
}

void	print_think(t_philo *philo)
{
	// pthread_mutex_lock(&philo->finish_mutex);
	if (philo->is_finished)
		return ;
		// pthread_mutex_unlock(&philo->finish_mutex);
	else
	{
		// pthread_mutex_unlock(&philo->finish_mutex);
		pthread_mutex_lock(philo->print_mutex);
		printf("%ldms %d is thinking\n", get_timestamp_ms(), philo->idx);
		pthread_mutex_unlock(philo->print_mutex);
	}
}

void	print_died(t_philo *philo)
{
	// pthread_mutex_lock(&philo->finish_mutex);
	if (philo->is_finished)
		return ;
		// pthread_mutex_unlock(&philo->finish_mutex);
	else
	{
		// pthread_mutex_unlock(&philo->finish_mutex);
		pthread_mutex_lock(philo->print_mutex);
		printf("%ldms %d died\n", get_timestamp_ms(), philo->idx);
		philo->is_finished = 1;
		pthread_mutex_unlock(philo->print_mutex);
	}
}
