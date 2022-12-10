/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wondong-gyu <wondong-gyu@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:02:35 by dowon             #+#    #+#             */
/*   Updated: 2022/12/10 11:13:50 by wondong-gyu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	length;
	char	*new_str;

	length = ft_strlen(s1);
	new_str = malloc(sizeof(char) * (length + 1));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, (length + 1));
	return (new_str);
}
