/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:12:43 by dowon             #+#    #+#             */
/*   Updated: 2023/08/25 17:44:59 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "utils/utils.h"

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

/*
@param str string to convert to integer
@param result converted result
@returns 
0 - success. If return value is not zero, it has error
1 - It does not contain any digits (-)
2 - It does not match this regex. ^[-+]?[0-9]*$
	Usually it contains other characters. (-1?abc)
	Or starts with two or more operators. (--+-1)
3 - It occurs overflow or underflow
*/
static int	parse_int(char *str, int *result)
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
		if (str[idx] < '0' || '9' < str[idx])
			return (2);
		idx++;
	}
	if (len > 10 + is_op || !is_int_str_equal(str_int, str))
		return (3);
	*result = str_int;
	return (0);
}

int	parse_args(int argc, char *argv[], int result[6], int *size)
{
	int		idx;
	int		s_idx;
	char	**split;

	*size = 0;
	idx = 1;
	while (idx < argc && *size <= 5)
	{
		split = ft_split(argv[idx], ' ');
		if (split == NULL || *split == NULL)
		{
			ft_split_free(split);
			return (-1);
		}
		s_idx = 0;
		while (split[s_idx] != NULL && *size <= 5)
		{
			if (parse_int(split[s_idx++], result + *size))
				return (-1);
			(*size) += 1;
		}
		ft_split_free(split);
		idx++;
	}
	return (-!(*size == 4 || *size == 5));
}
