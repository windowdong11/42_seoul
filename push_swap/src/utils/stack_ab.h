/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ab.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:24:22 by dowon             #+#    #+#             */
/*   Updated: 2023/05/30 18:30:57 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_AB_H
# define STACK_AB_H
# define OPTIMIZE 1

typedef enum e_command
{
	cmd_none = 0,
	cmd_ss = 10,
	cmd_sa = 11,
	cmd_sb = 12,
	cmd_rr = 20,
	cmd_ra = 21,
	cmd_rb = 22,
	cmd_rrr = 30,
	cmd_rra = 31,
	cmd_rrb = 32,
	cmd_pa = 41,
	cmd_pb = 42,
}						t_command;

typedef enum e_position
{
	A_TOP,
	A_BOTTOM,
	B_TOP,
	B_BOTTOM,
	POS_NULL
}						t_position;

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

typedef struct s_stack_ab	t_stack_ab;
typedef void				(*t_stack_ab_method)(t_stack_ab *, int);
struct s_stack_ab
{
	t_stack				*command;
	t_stack				*stack_a;
	t_stack				*stack_b;
	void				(*destructor)(struct s_stack_ab *this);
	t_stack_ab_method	sa;
	t_stack_ab_method	sb;
	t_stack_ab_method	ss;
	t_stack_ab_method	pa;
	t_stack_ab_method	pb;
	t_stack_ab_method	ra;
	t_stack_ab_method	rb;
	t_stack_ab_method	rr;
	t_stack_ab_method	rra;
	t_stack_ab_method	rrb;
	t_stack_ab_method	rrr;
};

int						is_a_command(t_command command);
int						is_b_command(t_command command);
void					print_command(t_command command);
int						remove_rev_cmd(t_stack_ab *this,
							t_command command, int view_history);
t_dbl_list				*new_t_dbl_list(int value);
t_stack					*new_t_stack(void);
t_stack_ab				*new_t_stack_ab(int argc, char *argv[]);
void					delete_t_dbl_list(t_dbl_list *this);
void					delete_t_stack(t_stack *this);
void					delete_t_stack_ab(t_stack_ab *this);
void					dbl_list_push_next(
							t_dbl_list *this, t_dbl_list *new_node);
void					dbl_list_push_prev(
							t_dbl_list *this, t_dbl_list *new_node);
t_dbl_list				*dbl_list_pop_prev(t_dbl_list *this);
t_dbl_list				*dbl_list_pop_next(t_dbl_list *this);
void					t_dbl_list_swap(t_dbl_list *this, t_dbl_list *node);
t_dbl_list				*dbl_list_find(t_dbl_list *this, int value);
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
typedef int					(*t_getter)(t_stack_ab *);
int						get_value(t_stack_ab *this, t_position pos);
void					visualize_ab(t_stack_ab *st, const char *prefix, int d);
#endif