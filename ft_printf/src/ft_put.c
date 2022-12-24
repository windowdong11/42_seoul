/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 14:18:55 by dowon             #+#    #+#             */
/*   Updated: 2022/12/24 17:32:19 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_put.h"
#include "../include/ft_str.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

ssize_t	ft_putchar(int c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

ssize_t	ft_putstr(const char *str)
{
	return (write(STDOUT_FILENO, str, strlen(str)));
}

ssize_t	ft_putbase(int num, char *prefix, const char *base, size_t base_len)
{
	int		idx;
	char	arr[sizeof(int) * 8];

	idx = 0;
	if (*prefix)
		write(STDOUT_FILENO, prefix, ft_strlen(prefix));
	if (num == 0)
		return (write(STDOUT_FILENO, base, 1));
	while (num)
	{
		arr[idx] = base[num / base_len];
		num %= base_len;
		idx++;
	}
	return (write(STDOUT_FILENO, arr, idx));
}
