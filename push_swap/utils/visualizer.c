#include "stack_ab.h"
#include "../ft_printf/include/ft_printf.h"
#include <stdlib.h>

static void	visualize(t_stack *s)
{
	t_dbl_list	*node;
	long long	idx;

	idx = 0;
	node = s->top;
	if (node == NULL)
	{
		ft_printf("\n");
		return ;
	}
	while (node->prev)
	{
		node = node->prev;
		idx--;
	}
	while (node)
	{
		ft_printf("[%d] %d -> ", idx, node->value);
		node = node->next;
		idx++;
	}
	ft_printf("[END]\n");
}

void	visualize_ab(t_stack_ab *st, const char *prefix, int d)
{
	ft_printf("(%d) %s", d, prefix);
	ft_printf("stack_a: ");
	visualize(st->stack_a);
	ft_printf("stack_b: ");
	visualize(st->stack_b);
}