/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:02:45 by dowon             #+#    #+#             */
/*   Updated: 2023/06/14 20:52:37 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	size_t			str_len;
	unsigned int	idx;

	str_len = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!ptr)
		return (NULL);
	idx = 0;
	while (s[idx])
	{
		ptr[idx] = f(idx, s[idx]);
		idx++;
	}
	ptr[idx] = '\0';
	return (ptr);
}
