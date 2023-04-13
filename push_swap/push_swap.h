/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:13:53 by dowon             #+#    #+#             */
/*   Updated: 2023/04/13 14:52:57 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils/stack_ab.h"

typedef struct s_merge_data
{
	int			size[2];
	t_position	src[2];
	void		(*merge)(t_stack_ab*, t_position);
	int			(*cmp)(int, int);
}	t_merge_data;


void			handle_error(char *message, int exit_code);
t_stack			*parse_args(int argc, char *argv[]);
void			merge_a_top(t_stack_ab *st, t_position src);
void			merge_a_bottom(t_stack_ab *st, t_position src);
void			merge_b_top(t_stack_ab *st, t_position src);
void			merge_b_bottom(t_stack_ab *st, t_position src);
void			manual_sort_a_top_empty(t_stack_ab *st, int (*cmp)(int, int));
void			manual_sort_a_top(t_stack_ab *st, int (*cmp)(int, int));
void			manual_sort_b_top(t_stack_ab *st, int (*cmp)(int, int));
void			manual_sort_b_bottom(t_stack_ab *st, int (*cmp)(int, int));
void			manual_sort_a_bottom(t_stack_ab *st, int (*cmp)(int, int));
int				greater(int a, int b);
int				smaller(int a, int b);
void			merge_any2(t_stack_ab *st, t_merge_data meta);

int				merge_sort_double(t_stack_ab *st,
					int (*cmp)(int, int), t_position dst);
void			merge3_a_top(t_stack_ab *st, int sizes[4],
					int (*cmp)(int, int));
void			adv_merge_3way(t_stack_ab *st, const int sizes[4],
					int (*cmp)(int, int), int (*rcmp)(int, int),
					t_position dst);
t_merge_data	get_merge_data(int size[2], t_position src[2],
					t_position dst, int (*cmp)(int, int));
int				handle_sorted(t_stack_ab *st, const int total_size,
					int (*cmp)(int, int), int (*rcmp)(int, int),
					t_position dst);
int				is_sorted(t_stack_ab *st, int (*cmp)(int, int), int count);

#endif