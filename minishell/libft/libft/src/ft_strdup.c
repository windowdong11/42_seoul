/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:02:35 by dowon             #+#    #+#             */
/*   Updated: 2023/06/14 20:52:37 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
