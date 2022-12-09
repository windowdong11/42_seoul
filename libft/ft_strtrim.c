/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wondong-gyu <wondong-gyu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:02:49 by dowon             #+#    #+#             */
/*   Updated: 2022/12/08 20:18:48 by wondong-gyu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

static char	*ft_strndup(const char *src, size_t length)
{
	char	*ptr;
	size_t	index;

	ptr = (char *)malloc(sizeof(char) * (length + 1));
	if (!ptr)
		return (NULL);
	index = 0;
	while (index < length)
	{
		ptr[index] = src[index];
		index++;
	}
	ptr[length] = '\0';
	return (ptr);
}

char const	*ft_move_head(char const *s1, char const *set)
{
	char const	*set_ptr;

	while (*s1)
	{
		set_ptr = set;
		while (*set_ptr && *set_ptr != *s1)
			set_ptr++;
		if (*set_ptr == '\0')
			break ;
		s1++;
	}
	return (s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*s1_end_ptr;
	char const	*set_ptr;

	s1 = ft_move_head(s1, set);
	s1_end_ptr = s1 + ft_strlen(s1) - 1;
	while (s1 < s1_end_ptr)
	{
		set_ptr = set;
		while (*set_ptr && *set_ptr != *s1_end_ptr)
			set_ptr++;
		if (*set_ptr == '\0')
			break ;
		s1_end_ptr--;
	}
	return (ft_strndup(s1, s1_end_ptr + 1 - s1));
}