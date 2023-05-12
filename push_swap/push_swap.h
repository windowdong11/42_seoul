/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:13:53 by dowon             #+#    #+#             */
/*   Updated: 2023/05/12 21:11:22 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils/stack_ab.h"

typedef void	(*t_merger)(t_stack_ab*, t_position);


void			handle_error(char *message, int exit_code);
t_stack			*parse_args(int argc, char *argv[]);
void			manual_sort_a_top_empty(t_stack_ab *st, int (*cmp)(int, int));
int				manual_sort_double(t_stack_ab *st,
					int (*cmp)(int, int), t_position dst);
void			manual_sort_triple(t_stack_ab *st, t_position dst,
					int (*cmp)(int, int));
int				greater(int a, int b);
int				smaller(int a, int b);

void			merge_all_a_top(t_stack_ab *st, int sizes[4],
					int (*cmp)(int, int));
void			adv_merge_3way(t_stack_ab *st, const int sizes[4],
					int (*cmp)(int, int), int (*rcmp)(int, int),
					t_position dst);
int				handle_sorted(t_stack_ab *st, const int total_size,
					int (*cmp)(int, int), int (*rcmp)(int, int),
					t_position dst);
int				is_sorted(t_stack_ab *st, int (*cmp)(int, int), int count);
t_merger		get_merge_func(t_position dst);

#endif