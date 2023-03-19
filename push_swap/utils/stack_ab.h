/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ab.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:24:22 by dowon             #+#    #+#             */
/*   Updated: 2023/02/27 22:11:00 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_AB_H
# define STACK_AB_H

/*
sa (swap a): Swap the first 2 elements at the top of stack a.
			Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
			Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
			Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
			Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
			The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
			The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
					The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
					The last element becomes the first one.
rrr : rra and rrb at the same time.
*/

typedef struct s_dbl_list
{
	struct s_dbl_list	*next;
	struct s_dbl_list	*prev;
	int					value;
	void				(*append)();
	void				(*remove)();
	void				(*get_value)();
	void				(*set_value)();
}	t_dbl_list;

typedef struct s_deque
{
	struct s_dbl_list	*head;
	struct s_dbl_list	*tail;
	int					size;
	void				(*push)();
	int					(*pop)();
	int					(*top)();
	int					(*bottom)();
	int					(*reverse)();
	int					(*get_size)();
}	t_deque;

typedef struct s_stack_ab
{
	t_deque	stack_a;
	t_deque	stack_b;
	void	(*sa)();
	void	(*sb)();
	void	(*ss)();
	void	(*pa)();
	void	(*pb)();
	void	(*ra)();
	void	(*rb)();
	void	(*rr)();
	void	(*rra)();
	void	(*rrb)();
	void	(*rrr)();
	t_deque	(*get_stack_a)();
	t_deque	(*get_stack_b)();
}	t_stack_ab;

t_dbl_list	*new_t_dbl_list(void);
t_deque		*new_t_deque(void);
t_stack_ab	*new_t_stack_ab(t_deque *stack_a, t_deque *stack_b);

#endif