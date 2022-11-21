/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:01:54 by dowon             #+#    #+#             */
/*   Updated: 2022/11/21 16:29:14 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*original_ptr;
	char	*moving_ptr;
	size_t	cnt;

	original_ptr = malloc(count * size);
	if (!original_ptr)
		return (NULL);
	moving_ptr = (char *)original_ptr;
	while (size--)
	{
		cnt = count;
		while (cnt--)
			*moving_ptr++ = 0;
	}
	return (original_ptr);
}
