/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:40:52 by dowon             #+#    #+#             */
/*   Updated: 2023/09/01 03:43:35 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils/utils.h"
#include <unistd.h>
#include <stdio.h>

static int	try_take_fork(pthread_mutex_t *mutex, int *owner_info, int my_info)
{
	pthread_mutex_lock(mutex);
	{
		if (*owner_info)
		{
			pthread_mutex_unlock(mutex);
			return (0);
		}
		*owner_info = my_info;
	}
	pthread_mutex_unlock(mutex);
	return (1);
}

static void	retry_take_fork(t_philo *me, pthread_mutex_t *mutex,
	int *owner_info, int my_info)
{
	while (try_take_fork(mutex, owner_info, my_info) == 0)
	{
		usleep(200);
		pthread_mutex_lock(me->finish_mutex);
		if (*me->is_finished)
		{
			pthread_mutex_unlock(me->finish_mutex);
			return ;
		}
		pthread_mutex_unlock(me->finish_mutex);
	}
	print_take_fork(me);
}

static int	try_eat(t_philo *me)
{
	me->last_eat_time = get_timestamp_ms();
	if (me->last_eat_time + me->time_to_die <= get_timestamp_ms())
	{
		pthread_mutex_lock(me->finish_mutex);
		if (!*me->is_finished)
		{
			*me->is_finished = 1;
			pthread_mutex_lock(me->print_mutex);
			printf("%ld %d died\n", get_timestamp_ms(), me->idx);
			pthread_mutex_unlock(me->print_mutex);
		}
		pthread_mutex_unlock(me->finish_mutex);
		pthread_mutex_unlock(&me->eat_mutex);
		return (1);
	}
	++me->eat_cnt;
	pthread_mutex_lock(me->finish_mutex);
	if (!*me->is_finished)
	{
		pthread_mutex_lock(me->print_mutex);
		printf("%d %d is eating\n", me->last_eat_time, me->idx);
		pthread_mutex_unlock(me->print_mutex);
	}
	pthread_mutex_unlock(me->finish_mutex);
	return (0);
}

static void	eat_rl(t_philo *me)
{
	retry_take_fork(me, me->right_mutex, me->right_fork, me->idx);
	retry_take_fork(me, me->left_mutex, me->left_fork, me->idx);
	pthread_mutex_lock(&me->eat_mutex);
	if (try_eat(me))
	{
		pthread_mutex_unlock(&me->eat_mutex);
		return ;
	}
	pthread_mutex_unlock(&me->eat_mutex);
	ft_msleep(me->time_to_eat);
	pthread_mutex_lock(me->left_mutex);
	*me->left_fork = 0;
	pthread_mutex_unlock(me->left_mutex);
	pthread_mutex_lock(me->right_mutex);
	*me->right_fork = 0;
	pthread_mutex_unlock(me->right_mutex);
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
	}
	return (NULL);
}
