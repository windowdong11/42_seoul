/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:09:03 by dowon             #+#    #+#             */
/*   Updated: 2023/06/11 17:09:13 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	maxf(float n1, float n2)
{
	if (n1 < n2)
		return (n2);
	return (n1);
}

float	minf(float n1, float n2)
{
	if (n1 > n2)
		return (n2);
	return (n1);
}
