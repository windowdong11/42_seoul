/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:04:40 by dowon             #+#    #+#             */
/*   Updated: 2023/08/23 17:54:52 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>

int	parse_args(int argc, char *argv[], int result[], int *size);

static void	print_usage(void)
{
	printf("usage: ./philosopher number_of_philosophers \
time_to_die time_to_eat time_to_sleep \
[number_of_times_each_philosopher_must_eat]\n");
}

int	main(int argc, char *argv[])
{
	int	result[6];
	int	size;

	if (parse_args(argc, argv, result, &size))
	{
		print_usage();
		return (1);
	}
	return (0);
}
