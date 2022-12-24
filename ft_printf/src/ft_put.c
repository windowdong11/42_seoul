/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 14:18:55 by dowon             #+#    #+#             */
/*   Updated: 2022/12/24 20:45:29 by dowon            ###   ########.fr       */
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
	return (write(STDOUT_FILENO, str, ft_strlen(str)));
}
