/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:36:54 by dowon             #+#    #+#             */
/*   Updated: 2023/06/14 21:18:49 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	is_int_str_equal(int num, char *num_str)
{
	const int	is_minus = num < 0;
	int			sign;
	int			idx;

	sign = 1;
	if (is_minus)
		sign = -1;
	if (is_minus && num_str[0] != '-')
		return (0);
	idx = ft_strlen(num_str) - 1;
	while (is_minus <= idx)
	{
		if (num_str[idx] != num % 10 * sign + '0')
			return (0);
		num /= 10;
		idx--;
	}
	return (1);
}
#include <stdio.h>

/*
@param str string to convert to integer
@param result converted result
@return [RETURNS 0] : success. If return value is not zero, it has error \n
@return [RETURNS 1] : It does not contain any digits (-) \n
@return [RETURNS 2] : It does not match this regexp. ^[-+]?[0-9]*$ \n
@return Usually it contains other characters. ex : -1?abc \n
@return Or starts with two or more operators. ex : --+-1 \n
@return [RETURNS 3] : It occurs overflow or underflow \n
*/
int	ft_parse_int(char *str, int *result)
{
	const int	is_op = str[0] == '-' || str[0] == '+';
	const int	len = ft_strlen(str);
	const int	str_int = ft_atoi(str);
	int			idx;

	idx = is_op;
	if (str[idx] == '\0')
		return (1);
	while (str[idx])
	{
		if (!ft_isdigit(str[idx]))
			return (2);
		idx++;
	}
	if (len > 10 + is_op || !is_int_str_equal(str_int, str))
		return (3);
	*result = str_int;
	return (0);
}
