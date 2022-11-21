/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:02:20 by dowon             #+#    #+#             */
/*   Updated: 2022/11/21 16:59:04 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_ptr;
	const char	*src_ptr;

	dst_ptr = dst;
	src_ptr = src;
	if (src_ptr < dst_ptr && dst_ptr <= src_ptr + len)
	{
		while (len--)
			*(dst_ptr + len) = *(src_ptr + len);
	}
	else
	{
		while (len--)
		{
			*dst_ptr = *src_ptr;
			dst_ptr++;
			src_ptr++;
		}
	}
	return (dst);
}
