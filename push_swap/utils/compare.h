/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:09:06 by dowon             #+#    #+#             */
/*   Updated: 2023/05/15 17:10:29 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPARE_H
# define COMPARE_H

typedef enum e_order
{
	DESC,
	ASC
}	t_order;

typedef int	(*t_compare)(int, int);

t_compare	get_cmp(const t_order order);
t_compare	get_rcmp(const t_order order);

#endif