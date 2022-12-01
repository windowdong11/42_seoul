/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:02:49 by dowon             #+#    #+#             */
/*   Updated: 2022/12/01 23:15:56 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char const	*ft_strtrim_head(char const *s1, char const *set)
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
	size_t		s1_remain_len;
	char const	*s1_end_ptr;
	char const	*set_ptr;
	char		*ptr;

	s1 = ft_strtrim_head(s1, set);
	s1_remain_len = ft_strlen(s1);
	s1_end_ptr = s1;
	while (*s1_end_ptr)
		s1_end_ptr++;
	if (s1 != s1_end_ptr)
		s1_end_ptr--;
	while (s1 < s1_end_ptr)
	{
		set_ptr = set;
		while (*set_ptr && *set_ptr != *s1_end_ptr)
			set_ptr++;
		if (*set_ptr == '\0')
			break ;
		s1_end_ptr--;
	}
	ptr = (char *)malloc(sizeof(char) * (s1_end_ptr - s1 + 2));
	if (ptr)
		ft_strlcpy(ptr, s1, s1_end_ptr - s1 + 2);
	return (ptr);
}
