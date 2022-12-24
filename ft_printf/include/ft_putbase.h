/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:42:35 by dowon             #+#    #+#             */
/*   Updated: 2022/12/24 20:44:24 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUTBASE_H
# define FT_PUTBASE_H

# include <unistd.h>

ssize_t	ft_putbase_unsigned(long long num, const char *base, size_t base_len);
ssize_t	ft_putbase_prefix(int num, const char *base, size_t base_len,
			const char *prefix);
ssize_t	ft_putbase_signed(int num, const char *base, size_t base_len,
			const char *prefix);

#endif