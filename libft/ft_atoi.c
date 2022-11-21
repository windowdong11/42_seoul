/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:01:37 by dowon             #+#    #+#             */
/*   Updated: 2022/11/21 21:20:23 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int	number;
	int	sign;

	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	number = 0;
	while ('0' <= *str && *str <= '9')
	{
		number *= 10;
		number += *str - '0';
		str++;
	}
	return (number * sign);
}
