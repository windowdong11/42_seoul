/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ab_getter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:28:50 by dowon             #+#    #+#             */
/*   Updated: 2023/05/12 21:49:38 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_ab.h"

static int	a_top(t_stack_ab *this)
{
	return (this->stack_a->top->value);
}

static int	a_bottom(t_stack_ab *this)
{
	return (this->stack_a->bottom->value);
}

static int	b_top(t_stack_ab *this)
{
	return (this->stack_b->top->value);
}

static int	b_bottom(t_stack_ab *this)
{
	return (this->stack_b->bottom->value);
}

int	get_value(t_stack_ab *this, t_position pos)
{
	const t_getter	func[4] = {a_top, a_bottom, b_top, b_bottom};

	return (func[pos](this));
}
