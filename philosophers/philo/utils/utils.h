/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:22:45 by dowon             #+#    #+#             */
/*   Updated: 2023/08/27 18:55:20 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>

size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
char	**ft_split(const char *s, char c);
void	ft_split_free(char **ptr);

#endif