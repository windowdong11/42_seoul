/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:42:35 by dowon             #+#    #+#             */
/*   Updated: 2022/12/28 08:53:03 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUTBASE_H
# define FT_PUTBASE_H

# include <unistd.h>

ssize_t	ft_putbase(unsigned long long num, const char *base, size_t base_len);
ssize_t	ft_putbase_prefix(unsigned long long num, const char *base,
			size_t base_len, const char *prefix);
ssize_t	ft_putbase_signed(long long num, const char *base, size_t base_len,
			const char *prefix);

#endif