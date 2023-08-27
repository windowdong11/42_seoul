/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:40:52 by dowon             #+#    #+#             */
/*   Updated: 2023/08/27 21:10:53 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils/utils.h"
#include <unistd.h>

static void	eat_lr(t_philo *me)
{
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
	pthread_mutex_unlock(me->left);
	pthread_mutex_unlock(me->right);
}

void	*philo_lr(void *args)
{
	t_philo*const	me = (t_philo *)args;

	ft_msleep(me->time_to_eat / 2);
	while (1)
	{
		pthread_mutex_lock(me->finish_mutex);
		if (*me->is_finished)
		{
			pthread_mutex_unlock(me->finish_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(me->finish_mutex);
		eat_lr(me);
		print_sleep(me);
		ft_msleep(me->time_to_sleep);
		print_think(me);
		usleep(100);
	}
	return (NULL);
}

static void	eat_rl(t_philo *me)
{
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
}

void	*philo_rl(void *args)
{
	t_philo*const	me = (t_philo *)args;

	while (1)
	{
		pthread_mutex_lock(me->finish_mutex);
		if (*me->is_finished)
		{
			pthread_mutex_unlock(me->finish_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(me->finish_mutex);
		eat_rl(me);
		print_sleep(me);
		ft_msleep(me->time_to_sleep);
		print_think(me);
		usleep(100);
	}
	return (NULL);
}
