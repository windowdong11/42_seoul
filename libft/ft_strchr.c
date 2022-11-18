/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:02:34 by dowon             #+#    #+#             */
/*   Updated: 2022/11/18 22:05:07 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	const char	*last_found;

	last_found = NULL;
	while (*str)
	{
		if (*str == ch)
			last_found = str;
		str++;
	}
	return (NULL);
}
