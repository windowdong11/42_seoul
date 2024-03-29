/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:12:43 by dowon             #+#    #+#             */
/*   Updated: 2023/05/23 22:15:33 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

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
		if (!ft_isdigit(str[idx]))
			return (2);
		idx++;
	}
	if (len > 10 + is_op || !is_int_str_equal(str_int, str))
		return (3);
	*result = str_int;
	return (0);
}

static void	parse_each_word(char **words, t_stack *stack_a)
{
	int	num;

	while (*words != NULL)
	{
		if (parse_int(*words, &num))
		{
			stack_a->destructor(stack_a);
			handle_error("Error\n", EXIT_FAILURE);
		}
		if (dbl_list_find(stack_a->top, num) != NULL)
		{
			stack_a->destructor(stack_a);
			handle_error("Error\n", EXIT_FAILURE);
		}
		stack_a->push_back(stack_a, new_t_dbl_list(num));
		free(*words);
		words++;
	}
}

t_stack	*parse_args(int argc, char *argv[])
{
	int				idx;
	t_stack*const	stack_a = new_t_stack();
	char			**split;

	if (argc < 2)
		handle_error("", EXIT_FAILURE);
	if (stack_a == NULL)
		handle_error("Error\n", EXIT_FAILURE);
	idx = 1;
	while (idx < argc)
	{
		split = ft_split(argv[idx], ' ');
		if (split == NULL || *split == NULL)
		{
			stack_a->destructor(stack_a);
			handle_error("Error\n", EXIT_FAILURE);
		}
		parse_each_word(split, stack_a);
		free(split);
		idx++;
	}
	return (stack_a);
}
