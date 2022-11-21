/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:02:49 by dowon             #+#    #+#             */
/*   Updated: 2022/11/21 21:28:46 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*last_found;

	last_found = NULL;
	while (1)
	{
		if (*str == ch)
			last_found = (char *)str;
		if (*str == '\0')
			return (last_found);
		str++;
	}
}
