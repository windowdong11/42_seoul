/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:02:17 by dowon             #+#    #+#             */
/*   Updated: 2022/12/09 23:11:22 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *p1, const void *p2, size_t num)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = (unsigned char *)p1;
	ptr2 = (unsigned char *)p2;
	while (num--)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
	}
	return (0);
}
