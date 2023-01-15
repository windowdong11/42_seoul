/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:25:19 by dowon             #+#    #+#             */
/*   Updated: 2022/12/29 03:58:29 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_UTILS_H
# define GET_NEXT_LINE_UTILS_H

# include <stdlib.h>

int		ft_strlen(char *str);
char	*ft_strchrset(char *str, char *charset, size_t len);
char	*ft_strlchr(char *str, char ch, size_t len);
void	ft_strcat_until_end(char *dest, char *src, char *str_end);

#endif