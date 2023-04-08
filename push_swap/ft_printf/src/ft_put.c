/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 14:18:55 by dowon             #+#    #+#             */
/*   Updated: 2023/04/01 07:11:57 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_put.h"
#include "../include/ft_str.h"

ssize_t	ft_putchar(int c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

ssize_t	ft_putstr(const char *str)
{
	if (str == NULL)
		return (write(STDOUT_FILENO, "(null)", 6));
	return (write(STDOUT_FILENO, str, pf_strlen(str)));
}
