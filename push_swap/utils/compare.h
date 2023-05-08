
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