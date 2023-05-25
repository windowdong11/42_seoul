/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:13:20 by dowon             #+#    #+#             */
/*   Updated: 2023/05/25 16:08:32 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdlib.h>

char	*gnl_strcat(char *src, t_gnl_fd *gnl_fd, size_t src_len)
{
	char	*result;
	size_t	idx;
	size_t	offset;

	if (src_len == 0 && gnl_fd->len == 0)
		return (NULL);
	result = malloc(sizeof(char) * (gnl_fd->len + src_len + 1));
	idx = -1;
	while (++idx < src_len)
		result[idx] = src[idx];
	idx = 0;
	while (idx < gnl_fd->len)
	{
		result[src_len + idx] = gnl_fd->buffer[idx];
		if (gnl_fd->buffer[idx++] == '\n')
			break ;
	}
	result[src_len + idx] = '\0';
	offset = idx;
	idx = -1;
	while (offset + ++idx < gnl_fd->len)
		gnl_fd->buffer[idx] = gnl_fd->buffer[offset + idx];
	gnl_fd->len = gnl_fd->len - offset;
	free(src);
	return (result);
}
