/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wondong-gyu <wondong-gyu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:01:54 by dowon             #+#    #+#             */
/*   Updated: 2022/12/10 11:41:57 by wondong-gyu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*original_ptr;
	size_t	total_size;

	total_size = count * size;
	original_ptr = malloc(total_size);
	if (!original_ptr)
		return (NULL);
	ft_memset(original_ptr, 0, total_size);
	return (original_ptr);
}
