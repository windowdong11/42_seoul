/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:41:12 by bena              #+#    #+#             */
/*   Updated: 2023/07/13 18:49:40 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		**remove_matrix(char **array);
char		***remove_tensor(char ***array);
static char	**split_args(const char *str);
static int	get_number_of_tokens(const char *str);
static char	*get_next_token(const char **str);
static int	push_to_the_next_token(const char **str);

char	***read_args(const char **args, int size)
{
	int		i;
	char	***output;

	output = (char ***)malloc(sizeof(char **) * (size + 1));
	if (output == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		output[i] = split_args(args[i]);
		if (output[i] == NULL)
			return (remove_tensor(output));
		i++;
	}
	output[size] = NULL;
	return (output);
}

static char	**split_args(const char *str)
{
	int		size;
	char	**output;
	int		i;

	size = get_number_of_tokens(str);
	if (size == 0)
		return (NULL);
	output = (char **)malloc(sizeof(char *) * (size + 1));
	if (output == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		output[i] = get_next_token(&str);
		if (output[i] == NULL)
			return (remove_matrix(output));
		i++;
	}
	output[size] = NULL;
	return (output);
}

static int	get_number_of_tokens(const char *str)
{
	int	output;
	int	token_size;

	output = 0;
	while (*str)
	{
		token_size = push_to_the_next_token(&str);
		if (token_size > 0)
			output++;
		str += token_size;
	}
	return (output);
}

static char	*get_next_token(const char **str)
{
	char	*output;
	int		token_size;
	int		i;

	if (str == NULL || *str == NULL)
		return (NULL);
	token_size = push_to_the_next_token(str);
	if (token_size == 0)
		return (NULL);
	output = (char *)malloc(sizeof(char) * (token_size + 1));
	if (output == NULL)
		return (NULL);
	i = -1;
	while (++i < token_size)
		output[i] = (*str)[i];
	output[token_size] = '\0';
	*str += token_size;
	return (output);
}

static int	push_to_the_next_token(const char **str)
{
	const char	*ptr;
	int			in_brace;
	int			in_double_brace;

	if (str == NULL || *str == NULL)
		return (0);
	in_brace = 0;
	in_double_brace = 0;
	while (**str && (**str == ' ' || **str == '|' || **str == '<' || **str == '>'))
		(*str)++;
	ptr = *str;
	while (*ptr)
	{
		if (*ptr == '\'' && in_double_brace == 0)
			in_brace ^= 1;
		else if (*ptr == '\"' && in_brace == 0)
			in_double_brace ^= 1;
		if (in_brace == 0 && in_double_brace == 0 && (*ptr == ' ' || *ptr == '|' || *ptr == '<' || *ptr == '>'))
			break ;
		ptr++;
	}
	return (ptr - *str);
}
