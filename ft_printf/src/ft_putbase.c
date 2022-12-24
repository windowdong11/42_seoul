/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:44:33 by dowon             #+#    #+#             */
/*   Updated: 2022/12/24 22:47:50 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_put.h"
#include "../include/ft_str.h"
#include <limits.h>

ssize_t	ft_putbase(unsigned long long num, const char *base, size_t base_len)
{
	int		idx;
	char	arr[sizeof(unsigned int) * 8];

	if (num == 0)
		return (write(STDOUT_FILENO, base, 1));
	idx = 0;
	while (num)
	{
		arr[sizeof(unsigned int) * 8 - 1 - idx] = base[num % base_len];
		num /= base_len;
		idx++;
	}
	return (write(STDOUT_FILENO, arr + sizeof(unsigned int) * 8 - idx, idx));
}

ssize_t	ft_putbase_prefix(unsigned long long num, const char *base, size_t base_len,
	const char *prefix)
{
	const size_t	prefix_len = ft_strlen(prefix);
	ssize_t			putbase_result;

	if (write(1, prefix, prefix_len) == -1)
		return (-1);
	putbase_result = ft_putbase(num, base, base_len);
	if (putbase_result == -1)
		return (-1);
	return (prefix_len + putbase_result);
}

ssize_t	ft_putbase_signed(long long num, const char *base, size_t base_len,
	const char *prefix)
{
	if (num >= 0)
		return (ft_putbase(num, base, base_len));
	return (ft_putbase_prefix(-num, base, base_len, prefix));
}
