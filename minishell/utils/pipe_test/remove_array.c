/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:12:19 by bena              #+#    #+#             */
/*   Updated: 2023/06/29 19:17:09 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**remove_matrix(char **array)
{
	char	**ptr;

	if (array == NULL)
		return (NULL);
	ptr = array;
	while (*ptr != NULL)
	{
		free(*ptr);
		ptr++;
	}
	free(array);
	return (NULL);
}

char	***remove_tensor(char ***array)
{
	char	***ptr;
	char	**ptr_sub;

	if (array == NULL)
		return (NULL);
	ptr = array;
	while (*ptr != NULL)
	{
		ptr_sub = *ptr;
		while (*ptr_sub != NULL)
		{
			free(*ptr_sub);
			ptr_sub++;
		}
		free(*ptr);
		ptr++;
	}
	free(array);
	return (NULL);
}
