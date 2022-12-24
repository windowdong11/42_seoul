/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:36:33 by dowon             #+#    #+#             */
/*   Updated: 2022/12/24 17:33:56 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/ft_put.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

ssize_t	ft_format_handler(const char *format, va_list *args)
{
	const char	*base_hex_lower = "0123456789abcdef";
	const char	*base_hex_upper = "0123456789ABCDEF";
	const char	*base_dec = "0123456789";

	if (*format == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (*format == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (*format == 'p')
		return (ft_putbase(va_arg(*args, int), "0x", base_hex_lower, 16));
	else if (*format == 'd' || *format == 'i')
		return (ft_putbase(va_arg(*args, int), "", base_dec, 10));
	else if (*format == 'u')
		return (ft_putbase(va_arg(*args, int), "", base_dec, 10));
	else if (*format == 'x')
		return (ft_putbase(va_arg(*args, int), "", base_hex_lower, 16));
	else if (*format == 'X')
		return (ft_putbase(va_arg(*args, int), "", base_hex_upper, 16));
	else if (*format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		size;
	int		result;

	va_start(args, format);
	size = 0;
	while (*format)
	{
		if (*format == '%')
			result = ft_format_handler(++format, &args);
		else
			result = ft_putchar(*format);
		if (result == -1)
			return (size);
		size += result;
		format++;
	}
	va_end(args);
	return (size);
}
