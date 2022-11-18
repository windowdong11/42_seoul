/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:02:17 by dowon             #+#    #+#             */
/*   Updated: 2022/11/18 23:34:42 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *p1, const void *p2, size_t num)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = (unsigned char *)p1;
	ptr2 = (unsigned char *)p2;
	while (*ptr1 == *ptr2 && num--)
	{
		if (*ptr1 == '\0')
			return (0);
		ptr1++;
		ptr2++;
	}
	if (num == 0)
		return (0);
	return (*ptr1 - *ptr2);
}
