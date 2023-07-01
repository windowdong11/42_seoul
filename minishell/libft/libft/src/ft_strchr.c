/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:02:34 by dowon             #+#    #+#             */
/*   Updated: 2023/06/14 17:01:16 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
@brief Returns the pointer address of the first `ch` contained in `str`. \n
@brief If it does not exist, return `NULL`. \n
*/
char	*ft_strchr(const char *str, int ch)
{
	while (1)
	{
		if (*str == (char)ch)
			return ((char *)str);
		if (!*str)
			return (NULL);
		str++;
	}
}
