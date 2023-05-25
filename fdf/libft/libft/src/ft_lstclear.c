/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:02:06 by dowon             #+#    #+#             */
/*   Updated: 2022/12/09 20:43:30 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur_list;

	if (!*lst)
		return ;
	while (*lst)
	{
		cur_list = *lst;
		*lst = cur_list->next;
		del(cur_list->content);
		free(cur_list);
	}
}
