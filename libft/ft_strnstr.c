/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wondong-gyu <wondong-gyu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:02:48 by dowon             #+#    #+#             */
/*   Updated: 2022/12/10 11:43:12 by wondong-gyu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	idx;
	size_t	offset;

	if (*to_find == '\0')
		return ((char *)str);
	idx = 0;
	while (*str && idx < len)
	{
		offset = 0;
		while (idx + offset <= len)
		{
			if (to_find[offset] == '\0')
				return ((char *)str);
			if (str[offset] != to_find[offset])
				break ;
			offset++;
		}
		str++;
		idx++;
	}
	return (NULL);
}
