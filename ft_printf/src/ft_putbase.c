/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:44:33 by dowon             #+#    #+#             */
/*   Updated: 2022/12/24 20:52:36 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_put.h"
#include "../include/ft_str.h"
#include <limits.h>

ssize_t	ft_putbase_unsigned(int num, const char *base, size_t base_len)
{
	int		idx;
	char	arr[sizeof(int) * 8];

	if (num == 0)
		return (write(STDOUT_FILENO, base, 1));
	idx = sizeof(int) * 8 - 1;
	while (num)
	{
		arr[idx] = base[num / base_len];
		num /= base_len;
		idx--;
	}
	return (write(STDOUT_FILENO, arr + idx, sizeof(int) * 8 - idx));
}

ssize_t	ft_putbase_prefix(int num, const char *base, size_t base_len,
	const char *prefix)
{
	const size_t	prefix_len = ft_strlen(prefix);
	int				putbase_result;

	if (write(1, prefix, prefix_len) == -1)
		return (-1);
	putbase_result = ft_putbase_unsigned(num, base, base_len);
	if (putbase_result == -1)
		return (-1);
	return (prefix_len + putbase_result);
}

ssize_t	ft_putbase_signed(int num, const char *base, size_t base_len,
	const char *prefix)
{
	ssize_t	putbase_result;
	ssize_t	lastnumber_result;

	if (num >= 0)
		return (ft_putbase_unsigned(num, base, base_len));
	else if (num != INT_MIN)
		return (ft_putbase_prefix(-num, base, base_len, prefix));
	putbase_result = ft_putbase_prefix(-(num / 10), base, base_len, prefix);
	if (putbase_result == -1)
		return (-1);
	lastnumber_result = write(1, base + -(INT_MIN % base_len), 1);
	if (lastnumber_result == -1)
		return (-1);
	return (putbase_result + lastnumber_result);
}
