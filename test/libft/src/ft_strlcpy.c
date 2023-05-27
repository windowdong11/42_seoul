/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:02:42 by dowon             #+#    #+#             */
/*   Updated: 2022/12/09 15:46:07 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dstsize != 0)
	{
		dstsize--;
		while (dstsize-- && *src)
		{
			*dst = *src;
			dst++;
			src++;
		}
		*dst = '\0';
	}
	return (src_len);
}
