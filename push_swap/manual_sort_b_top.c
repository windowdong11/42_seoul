#include "utils/stack_ab.h"

// static void	sort_b_top_order(t_stack_ab *st, int order)
// {
// 	if (order == 123)
// 	{
// 		st->pb(st, OPTIMIZE);
// 		st->sa(st, 1);
// 		st->pb(st, OPTIMIZE);
// 		st->sb(st, 1);
// 		st->pb(st, OPTIMIZE);
// 		st->sb(st, 1);
// 	}
// 	else if (order == 132)
// 	{
// 		st->sa(st, 1);
// 		st->pb(st, OPTIMIZE);
// 		st->sa(st, 1);
// 		st->pb(st, OPTIMIZE);
// 		st->pb(st, OPTIMIZE);
// 	}
// 	else if (order == 231)
// 	{
// 		st->sa(st, 1);
// 		st->pb(st, OPTIMIZE);
// 		st->pb(st, OPTIMIZE);
// 		st->pb(st, OPTIMIZE);
// 	}
// }

// static void	sort_b_top_order2(t_stack_ab *st, int order)
// {
// 	if (order == 213)
// 	{
// 		st->pb(st, OPTIMIZE);
// 		st->sa(st, 1);
// 		st->pb(st, OPTIMIZE);
// 		st->sb(st, 1);
// 		st->pb(st, OPTIMIZE);
// 	}
// 	else if (order == 312)
// 	{
// 		st->pb(st, OPTIMIZE);
// 		st->sa(st, 1);
// 		st->pb(st, OPTIMIZE);
// 		st->pb(st, OPTIMIZE);
// 	}
// 	else if (order == 321)
// 	{
// 		st->pb(st, OPTIMIZE);
// 		st->pb(st, OPTIMIZE);
// 		st->pb(st, OPTIMIZE);
// 	}
// }

// void	manual_sort_b_top(t_stack_ab *st, int (*cmp)(int, int))
// {
// 	if (cmp(st->stack_a->top->value, st->stack_a->top->next->value))
// 	{
// 		if (cmp(st->stack_a->top->next->value,
// 				st->stack_a->top->next->next->value))
// 			sort_b_top_order(st, 123);
// 		else if (cmp(st->stack_a->top->value,
// 				st->stack_a->top->next->next->value))
// 			sort_b_top_order(st, 132);
// 		else
// 			sort_b_top_order(st, 231);
// 	}
// 	else
// 	{
// 		if (cmp(st->stack_a->top->value, st->stack_a->top->next->next->value))
// 			sort_b_top_order2(st, 213);
// 		else if (cmp(st->stack_a->top->next->value,
// 				st->stack_a->top->next->next->value))
// 			sort_b_top_order2(st, 312);
// 		else
// 			sort_b_top_order2(st, 321);
// 	}
// }
