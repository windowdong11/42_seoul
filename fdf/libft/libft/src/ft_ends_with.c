/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ends_with.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:27:40 by dowon             #+#    #+#             */
/*   Updated: 2023/06/14 17:30:56 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_ends_with(const char *str, const char *end)
{
	const char*const	str_start = str;
	const char*const	end_start = str;

	while (*str != '\0')
		str++;
	while (*end != '\0')
		end++;
	if (str - str_start < end - end_start)
		return (0);
	while (str >= str_start && end >= end_start)
	{
		if (*str != *end)
			return (0);
		--str;
		--end;
	}
	return (1);
}
