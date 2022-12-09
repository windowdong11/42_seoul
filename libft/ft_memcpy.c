/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:02:18 by dowon             #+#    #+#             */
/*   Updated: 2022/12/09 23:11:33 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	while (n--)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dst);
}
