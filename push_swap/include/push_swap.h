/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:13:53 by dowon             #+#    #+#             */
/*   Updated: 2023/05/23 18:29:43 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../src/utils/stack_ab.h"
# include "../src/utils/compare.h"

typedef void	(*t_merger)(t_stack_ab*, t_position);

void			handle_error(char *message, int exit_code);
t_stack			*parse_args(int argc, char *argv[]);
void			merge_sort(
					t_stack_ab *st, int size, t_order order, t_position dst);
void			merge_to_dst(
					t_stack_ab *st, int sizes[4],
					t_order order, t_position dst);
void			manual_sort(
					t_stack_ab *st, int size, t_order order, t_position dst);
void			manual_sort_single(t_stack_ab *st, t_position dst);
int				manual_sort_double(t_stack_ab *st,
					int (*cmp)(int, int), t_position dst);
void			manual_sort_triple(t_stack_ab *st, t_position dst,
					int (*cmp)(int, int));
int				greater(int a, int b);
int				smaller(int a, int b);

int				is_sorted(t_stack *st, int (*cmp)(int, int), int count);
t_merger		get_merge_func(t_position dst);

#endif