/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:02:01 by dowon             #+#    #+#             */
/*   Updated: 2022/12/09 23:10:22 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		int_len;
	int		is_unsigned;

	int_len = ft_intlen(n);
	is_unsigned = n < 0;
	str = (char *)malloc(sizeof(char) * (int_len + 1 + is_unsigned));
	if (str == 0)
		return (NULL);
	str[int_len + is_unsigned] = '\0';
	if (is_unsigned)
	{
		str[0] = '-';
		str[int_len - 1 + is_unsigned] = -(n % 10) + '0';
		int_len--;
		n = -(n / 10);
	}
	while (int_len)
	{
		str[int_len - 1 + is_unsigned] = n % 10 + '0';
		n /= 10;
		int_len--;
	}
	return (str);
}
