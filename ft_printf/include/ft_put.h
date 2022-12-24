/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 14:19:13 by dowon             #+#    #+#             */
/*   Updated: 2022/12/24 17:17:17 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUT_H
# define FT_PUT_H

# include <unistd.h>

ssize_t	ft_putchar(int c);
ssize_t	ft_putstr(const char *str);
ssize_t	ft_putbase(int num, char *prefix, const char *base, size_t base_len);

#endif