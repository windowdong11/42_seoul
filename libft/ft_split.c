/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wondong-gyu <wondong-gyu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:02:32 by dowon             #+#    #+#             */
/*   Updated: 2022/12/10 11:08:12 by wondong-gyu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_count_word(const char *str, char c)
{
	size_t	word_len;

	word_len = 0;
	while (*str != '\0' && *str == c)
		str++;
	while (*str != '\0')
	{
		if (*str != c && (*(str + 1) == c || *(str + 1) == '\0'))
			word_len++;
		str++;
	}
	return (word_len);
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

static void	*ft_free(char **ptr, int idx)
{
	while (idx >= 0)
	{
		free(ptr[idx]);
		ptr[idx] = NULL;
		idx--;
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	size_t		word_idx;
	char		**ptr;
	const char	*start;

	ptr = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!ptr)
		return (NULL);
	word_idx = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		start = s;
		while (*s != c && *s != '\0')
			s++;
		ptr[word_idx] = ft_strndup(start, s - start);
		if (!ptr[word_idx])
			return (ft_free(ptr, word_idx));
		word_idx++;
	}
	ptr[word_idx] = NULL;
	return (ptr);
}
