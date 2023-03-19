/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:12:43 by dowon             #+#    #+#             */
/*   Updated: 2023/03/13 23:17:55 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static int	is_proper_int(char *str)
{
	const int	len = ft_strlen(str);
	const int	is_op = str[0] == '-' || str[0] == '+';
	int			str_int;
	int			idx;

	idx = is_op;
	while (str[idx])
	{
		if (!ft_isdigit(str[idx]))
			return (0);
		idx++;
	}
	if (len > 10 + is_op)
		return (0);
	str_int = ft_atoi(str);
	idx = len - 1;
	while (idx >= is_op)
	{
		if (str[idx] != (str_int % 10) * (-1 + 2 * (str[0] != '-')) + '0')
			return (0);
		str_int /= 10;
		idx--;
	}
	return (len > is_op);
}

// some arguments aren’t integers, some arguments are
// bigger than an integer and/or there are duplicates
void	is_valid_args(int argc, char *argv[])
{
	int	idx;

	if (argc < 2)
		handle_error("Error\n", 0);
	idx = 1;
	while (idx < argc)
	{
		if (!is_proper_int(argv[idx]))
			handle_error("Error\n", 0);
		idx++;
	}
}
