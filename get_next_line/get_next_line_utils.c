/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:13:20 by dowon             #+#    #+#             */
/*   Updated: 2023/01/14 16:04:50 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	const char	*start = str;

	while (*str)
		str++;
	return (str - start);
}

char	*ft_strlchr(char *str, char ch, size_t len)
{
	size_t idx;

	idx = 0;
	while (idx < len)
	{
		if (*str == ch)
			return (str);
		str++;
	}
	return (str);
}

char	*ft_strchrset(char *str, char *charset, size_t charset_len)
{
	size_t	idx;

	while (*str)
	{
		idx = 0;
		while (idx < charset_len)
		{
			if (*str == charset[idx])
				return (str);
			idx++;
		}
		str++;
	}
	return (NULL);
}

void	ft_strcat_until_end(char *dest, char *src, char *str_end)
{
	while (*dest)
		dest++;
	while (*src && src != str_end)
		*dest++ = *src++;
	*dest = *str_end;
	*(dest + 1) = '\0';
}
