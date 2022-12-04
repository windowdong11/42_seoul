/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wondong-gyu <wondong-gyu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:00:28 by dowon             #+#    #+#             */
/*   Updated: 2022/12/04 16:31:19 by wondong-gyu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>

// int		ft_atoi(char *str);
// void	ft_bzero(void *s, size_t n);
// void	*ft_calloc(size_t count, size_t size);
// int		ft_isalpha(int ch);
// int		ft_isalnum(int ch);
// int		ft_isascii(int ch);
// int		ft_isdigit(int ch);
// int		ft_isprint(int ch);
// char	*ft_itoa(int n);
// int		ft_memcmp(const void *p1, const void *p2, size_t num);
// void	*ft_memcpy(void *dest, const void *src, size_t cnt);
// void	*ft_memmove(void *dest, const void *src, size_t cnt);
// void	*ft_memchr(const void *p, int value, size_t num);
void	*ft_memset(void *b, int c, size_t len);
// char	*ft_substr(char const *s, unsigned int start, size_t len);
// char	*ft_strchr(const char *str, int ch);
// int		ft_strcmp(char *s1, char *s2);
// char	*strdup(const char *s1);
// char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
// size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
// int		ft_strncmp(char *s1, char *s2, unsigned int n);
// char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	**ft_split(char const *s, char c);
// char	*ft_strrchr(const char *str, int ch);
// char	*ft_strtrim(char const *s1, char const *set);
// int		ft_tolower(int ch);
// int		ft_toupper(int ch);
// void	ft_putchar(char c);
// void	ft_swap(int *a, int *b);
// void	ft_putstr(char *str);

#endif 
