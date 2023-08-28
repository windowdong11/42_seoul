/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:40:52 by dowon             #+#    #+#             */
/*   Updated: 2023/08/28 17:17:05 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils/utils.h"
#include <unistd.h>

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
		usleep(300);
		pthread_mutex_lock(&me->finish_mutex);
		if (*me->is_finished)
		{
			pthread_mutex_unlock(&me->finish_mutex);
			return ;
		}
		pthread_mutex_unlock(&me->finish_mutex);
	}
}

static void	drop_fork(pthread_mutex_t *mutex, int *owner_info)
{
	pthread_mutex_lock(mutex);
	*owner_info = 0;
	pthread_mutex_unlock(mutex);
}

static void	eat_rl(t_philo *me)
{
	retry_take_fork(me, me->right_mutex, me->right_fork, me->idx);
	print_take_fork(me);
	retry_take_fork(me, me->left_mutex, me->left_fork, me->idx);
	print_take_fork(me);
	pthread_mutex_lock(&me->eat_mutex);
	me->last_eat_time = get_timestamp_ms();
	++me->eat_cnt;
	pthread_mutex_unlock(&me->eat_mutex);
	print_eat(me);
	ft_msleep(me->time_to_eat);
	drop_fork(me->left_mutex, me->left_fork);
	drop_fork(me->right_mutex, me->right_fork);
}

void	*philo_rl(void *args)
{
	t_philo*const	me = (t_philo *)args;

	while (1)
	{
		pthread_mutex_lock(&me->finish_mutex);
		if (*me->is_finished)
		{
			pthread_mutex_unlock(&me->finish_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&me->finish_mutex);
		eat_rl(me);
		print_sleep(me);
		ft_msleep(me->time_to_sleep);
		print_think(me);
	}
	return (NULL);
}
