/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:02:29 by dowon             #+#    #+#             */
/*   Updated: 2023/04/01 07:13:54 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putnbr_fd(int n, int fd)
{
	char	num_str[11];
	int		idx;

	idx = 0;
	num_str[10] = '\0';
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num_str[9 - idx++] = -(n % 10) + '0';
		n = -(n / 10);
	}
	else if (n == 0)
		num_str[9 - idx++] = '0';
	while (n)
	{
		num_str[9 - idx++] = n % 10 + '0';
		n /= 10;
	}
	return (ft_putstr_fd(num_str + (10 - idx), fd));
}
