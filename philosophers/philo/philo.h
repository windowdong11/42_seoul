/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:41:19 by dowon             #+#    #+#             */
/*   Updated: 2023/08/26 22:03:15 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>

typedef long	t_ms;

typedef struct s_philo
{
	int				idx;
	int				is_finished;
	int				eat_cnt;
	int				last_eat_time;
	pthread_t		thread;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	finish_mutex;
	pthread_mutex_t	eat_mutex;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_cnt;
}	t_philo;

typedef struct s_philo_general
{
	t_philo			*philosophers;
	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t	print_mutex;
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_cnt;
}	t_philo_general;

/* init & clean */
void	init_general(t_philo_general *data, int result[6], int size);
void	clean_all(t_philo_general *data);

/* timestamp */
void	init_timestamp(void);
t_ms	get_timestamp_ms(void);

/* observe */
void	*observe(void *arg);

/* print - with mutex lock */
void	print_take_fork(t_philo *philo);
void	print_eat(t_philo *philo);
void	print_sleep(t_philo *philo);
void	print_think(t_philo *philo);
void	print_died(t_philo *philo);

#endif