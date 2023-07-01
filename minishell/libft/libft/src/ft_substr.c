/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:02:50 by dowon             #+#    #+#             */
/*   Updated: 2023/06/14 20:52:37 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	size_t	copy_len;
	char	*ptr;

	str_len = ft_strlen(s);
	if (start >= str_len || len == 0)
	{
		ptr = (char *)malloc(sizeof(char));
		if (ptr)
			*ptr = '\0';
		return (ptr);
	}
	if (str_len - start < len)
		copy_len = str_len - start;
	else
		copy_len = len;
	ptr = (char *)malloc(sizeof(char) * (copy_len + 1));
	if (ptr)
		ft_strlcpy(ptr, s + start, copy_len + 1);
	return (ptr);
}
