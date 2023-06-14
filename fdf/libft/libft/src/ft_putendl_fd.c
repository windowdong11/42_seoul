/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:02:24 by dowon             #+#    #+#             */
/*   Updated: 2023/06/14 20:52:37 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

ssize_t	ft_putendl_fd(char *s, int fd)
{
	ssize_t	result;

	result = ft_putstr_fd(s, fd);
	if (result == -1)
		return (-1);
	if (ft_putchar_fd('\n', fd) == -1)
		return (-1);
	return (result + 1);
}
