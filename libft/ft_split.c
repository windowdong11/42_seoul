/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wondong-gyu <wondong-gyu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:02:32 by dowon             #+#    #+#             */
/*   Updated: 2022/12/04 17:04:20 by wondong-gyu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_word(char const *str, char c)
{
	size_t	word_len;

	word_len = 0;
	while (*str != '\0')
	{
		if (*str == c && *(str + 1) != c)
			word_len++;
		str++;
	}
	return (word_len);
}

char	*ft_strndup(char const *src, size_t length)
{
	char	*ptr;
	size_t	index;

	if (!length)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (length + 1));
	if (!ptr)
		return (NULL);
	index = 0;
	while (index < length)
	{
		ptr[index] = src[index];
		index++;
	}
	ptr[length] = 0;
	return (ptr);
}

void	*ft_free(char **ptr, int idx)
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

char	**ft_split(char const *s, char c)
{
	size_t		word_idx;
	size_t		word_len;
	char		**ptr;

	ptr = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (ptr == 0)
		return (NULL);
	word_idx = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		word_len = 0;
		while (*(s + word_len) != c && *(s + word_len) != '\0')
			word_len++;
		ptr[word_idx++] = ft_strndup(s, word_len);
		if (!ptr)
			return (ft_free(ptr, word_idx - 1));
		s += word_len;
	}
	ptr[word_idx] = 0;
	return (ptr);
}
