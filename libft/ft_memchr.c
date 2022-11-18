/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:02:16 by dowon             #+#    #+#             */
/*   Updated: 2022/11/18 23:31:10 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *p, int value, size_t num)
{
	const unsigned char	*ptr = (unsigned char *)p;

	while (*ptr && *ptr != (unsigned char)value && num--)
		ptr++;
	return (ptr);
}
