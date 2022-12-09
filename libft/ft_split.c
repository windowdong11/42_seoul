/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wondong-gyu <wondong-gyu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:02:32 by dowon             #+#    #+#             */
/*   Updated: 2022/12/08 00:38:30 by wondong-gyu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_word(const char *str, char c)
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

const char	*ft_strtok_ch(const char *s, char c)
{
	if (!s)
		return (NULL);
	while (*s == c)
		s++;
	if (*s == '\0')
		return (NULL);
	while (*s != c && *s != '\0')
		s++;
	return (s);
}

char	**ft_split(const char *s, char c)
{
	size_t		word_idx;
	size_t		word_cnt;
	char		**ptr;
	const char	*start;

	word_cnt = ft_count_word(s, c);
	ptr = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (ptr == 0)
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

// #include <stdio.h>

// int main () {
// 	char **ptr;
// 	// ptr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
// 	// printf(">> [1]\n");
// 	// for (int i = 0; ptr[i]; i++)
// 	// 	printf("[%s]\n", ptr[i]);
// 	// ptr = ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');
// 	// printf(">> [2]\n");
// 	// for (int i = 0; ptr[i]; i++)
// 	// 	printf("[%s]\n", ptr[i]);
// 	// ptr = ft_split("--1-2--3---4----5-----42", '-');
// 	// printf(">> [3]\n");
// 	// for (int i = 0; ptr[i]; i++)
// 	// 	printf("[%s]\n", ptr[i]);
// 	ptr = ft_split("hello!", ' ');
// 	printf(">> [4]\n");
// 	for (int i = 0; ptr[i]; i++)
// 		printf("[%s]\n", ptr[i]);
// 	ft_free(ptr, 1);
// 	// ptr = ft_split("", '\0');
// 	// printf(">> [5]\n");
// 	// for (int i = 0; ptr[i]; i++)
// 	// 	printf("[%s]\n", ptr[i]);
// 	return 0;
// }