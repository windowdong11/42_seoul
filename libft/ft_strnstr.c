/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:02:48 by dowon             #+#    #+#             */
/*   Updated: 2022/11/21 21:53:00 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	pivot;
	size_t	pos;

	if (*to_find == '\0')
		return ((char *)str);
	pivot = 0;
	while (len--)
	{
		pos = 0;
		while (pivot + pos <= len
			&& str[pivot + pos] == to_find[pos] && to_find[pos] != '\0')
			pos++;
		if (to_find[pos] == '\0')
			return ((char *)(str + pivot));
		pivot++;
	}
	return (NULL);
}
