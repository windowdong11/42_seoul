/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:36:33 by dowon             #+#    #+#             */
/*   Updated: 2023/05/25 16:07:47 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../include/ft_put.h"
#include "../include/ft_putbase.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

ssize_t	ft_format_handler(const char *format, va_list *args)
{
	const char	*hex_lower = "0123456789abcdef";
	const char	*hex_upper = "0123456789ABCDEF";
	const char	*dec = "0123456789";

	if (*format == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (*format == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (*format == 'p')
		return (ft_putbase_prefix((unsigned long long)va_arg(*args, void *),
				hex_lower, 16, "0x"));
	else if (*format == 'd' || *format == 'i')
		return (ft_putbase_signed(va_arg(*args, int), dec, 10, "-"));
	else if (*format == 'u')
		return (ft_putbase(va_arg(*args, unsigned int), dec, 10));
	else if (*format == 'x')
		return (ft_putbase(va_arg(*args, unsigned int), hex_lower, 16));
	else if (*format == 'X')
		return (ft_putbase(va_arg(*args, unsigned int), hex_upper, 16));
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
		{
			result = ft_format_handler(format + 1, &args);
			if (result >= 0)
				format++;
		}
		else
			result = ft_putchar(*format);
		if (result == -1)
			return (-1);
		size += result;
		format++;
	}
	va_end(args);
	return (size);
}
