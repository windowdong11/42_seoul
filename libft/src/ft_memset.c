/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:02:21 by dowon             #+#    #+#             */
/*   Updated: 2022/12/09 23:11:59 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ub;
	size_t			idx;

	ub = (unsigned char *)b;
	idx = 0;
	while (idx < len)
	{
		ub[idx] = (unsigned char)c;
		idx++;
	}
	return (b);
}
