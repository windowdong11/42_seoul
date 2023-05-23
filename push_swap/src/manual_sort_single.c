/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sort_single.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 22:45:57 by dowon             #+#    #+#             */
/*   Updated: 2023/05/12 22:45:59 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils/stack_ab.h"

void	manual_sort_single(t_stack_ab *st, t_position dst)
{
	if (dst == A_BOTTOM)
		st->ra(st, OPTIMIZE);
	else if (dst == B_TOP)
		st->pb(st, OPTIMIZE);
	else if (dst == B_BOTTOM)
	{
		st->pb(st, OPTIMIZE);
		st->rb(st, OPTIMIZE);
	}
}
