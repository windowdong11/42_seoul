/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:02:16 by dowon             #+#    #+#             */
/*   Updated: 2022/12/09 23:11:08 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *p, int value, size_t num)
{
	const unsigned char	*ptr = (unsigned char *)p;

	while (num--)
	{
		if (*ptr == (unsigned char)value)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}
