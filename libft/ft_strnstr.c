/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:02:48 by dowon             #+#    #+#             */
/*   Updated: 2022/11/21 17:00:56 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int	idx;
	int	i;

	if (*to_find == '\0')
		return ((char *)str);
	idx = 0;
	while (str[idx] != '\0' && len--)
	{
		i = 0;
		while (str[idx + i] == to_find[i] && to_find[i] != '\0')
			i++;
		if (to_find[i] == '\0')
			return ((char *)(str + idx));
		idx++;
	}
	return (0);
}
