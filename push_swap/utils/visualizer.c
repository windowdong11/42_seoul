#include "stack_ab.h"
#include "../ft_printf/include/ft_printf.h"
#include <stdlib.h>

void	visualize(t_stack* s)
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
	ft_printf("\n");
}