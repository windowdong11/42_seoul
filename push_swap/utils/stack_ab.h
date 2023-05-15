/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ab.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:24:22 by dowon             #+#    #+#             */
/*   Updated: 2023/05/15 14:39:12 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_AB_H
# define STACK_AB_H
# define OPTIMIZE 1

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

typedef enum e_command
{
	NONE = 0,
	SS = 10,
	RR = 20,
	RRR = 30,
	SA = 11,
	RA = 21,
	RRA = 31,
	PA = 41,
	SB = 12,
	RB = 22,
	RRB = 32,
	PB = 42,
}	t_command;

typedef enum e_position
{
	A_TOP,
	A_BOTTOM,
	B_TOP,
	B_BOTTOM,
	POS_NULL
}	t_position;

typedef struct s_dbl_list
{
	struct s_dbl_list	*next;
	struct s_dbl_list	*prev;
	int					value;
	void				(*destructor)(struct s_dbl_list *this);
	void				(*push_next)(struct s_dbl_list *this,
			struct s_dbl_list *new_node);
	void				(*push_prev)(struct s_dbl_list *this,
			struct s_dbl_list *new_node);
	struct s_dbl_list	*(*pop_prev)(struct s_dbl_list *this);
	struct s_dbl_list	*(*pop_next)(struct s_dbl_list *this);
	void				(*swap)(struct s_dbl_list *this,
			struct s_dbl_list *node);
}						t_dbl_list;

typedef struct s_stack
{
	t_dbl_list			*top;
	t_dbl_list			*bottom;
	int					size;
	void				(*destructor)(struct s_stack *this);
	void				(*push)(struct s_stack *this, t_dbl_list *new_node);
	void				(*push_back)(struct s_stack *this,
			t_dbl_list *new_node);
	t_dbl_list			*(*pop)(struct s_stack *this);
	void				(*swap)(struct s_stack *this);
	void				(*rotate)(struct s_stack *this);
	void				(*rrotate)(struct s_stack *this);
}						t_stack;

typedef struct s_stack_ab
{
	t_stack				*command;
	t_stack				*stack_a;
	t_stack				*stack_b;
	void				(*destructor)(struct s_stack_ab *this);
	void				(*sa)(struct s_stack_ab *this, int optimize);
	void				(*sb)(struct s_stack_ab *this, int optimize);
	void				(*ss)(struct s_stack_ab *this, int optimize);
	void				(*pa)(struct s_stack_ab *this, int optimize);
	void				(*pb)(struct s_stack_ab *this, int optimize);
	void				(*ra)(struct s_stack_ab *this, int optimize);
	void				(*rb)(struct s_stack_ab *this, int optimize);
	void				(*rr)(struct s_stack_ab *this, int optimize);
	void				(*rra)(struct s_stack_ab *this, int optimize);
	void				(*rrb)(struct s_stack_ab *this, int optimize);
	void				(*rrr)(struct s_stack_ab *this, int optimize);
}						t_stack_ab;

int						is_a_command(t_command command);
int						is_b_command(t_command command);
void					print_command(t_command command);
int						remove_rev_cmd(t_stack_ab *this, t_command command,
							int view_history);

t_dbl_list				*new_t_dbl_list(int value);
t_stack					*new_t_stack(void);
t_stack_ab				*new_t_stack_ab(t_stack *stack_a, t_stack *stack_b);

void					delete_t_dbl_list(t_dbl_list *this);
void					delete_t_stack(t_stack *this);
void					delete_t_stack_ab(t_stack_ab *this);

void					t_dbl_list_push_next(t_dbl_list *this,
							t_dbl_list *new_node);
void					t_dbl_list_push_prev(t_dbl_list *this,
							t_dbl_list *new_node);
t_dbl_list				*t_dbl_list_pop_prev(t_dbl_list *this);
t_dbl_list				*t_dbl_list_pop_next(t_dbl_list *this);
void					t_dbl_list_swap(t_dbl_list *this, t_dbl_list *node);
t_dbl_list				*t_dbl_list_find(t_dbl_list *this, int value);

void					t_stack_push(t_stack *this, t_dbl_list *new_node);
void					t_stack_push_back(t_stack *this, t_dbl_list *new_node);
t_dbl_list				*t_stack_pop(t_stack *this);
void					t_stack_swap(t_stack *this);
void					t_stack_rotate(t_stack *this);
void					t_stack_rrotate(t_stack *this);

void					sa(t_stack_ab *this, int optimize);
void					sb(t_stack_ab *this, int optimize);
void					ss(t_stack_ab *this, int optimize);
void					pa(t_stack_ab *this, int optimize);
void					pb(t_stack_ab *this, int optimize);
void					ra(t_stack_ab *this, int optimize);
void					rb(t_stack_ab *this, int optimize);
void					rr(t_stack_ab *this, int optimize);
void					rra(t_stack_ab *this, int optimize);
void					rrb(t_stack_ab *this, int optimize);
void					rrr(t_stack_ab *this, int optimize);

typedef int	(*t_getter)(t_stack_ab*);
int						get_value(t_stack_ab *this, t_position pos);

void					visualize_ab(t_stack_ab *st, const char *prefix, int d);
#endif