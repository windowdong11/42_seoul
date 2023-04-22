/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:02:07 by dowon             #+#    #+#             */
/*   Updated: 2023/04/21 21:04:34 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst->content)
		del(lst->content);
	free(lst);
}

void	ft_lstpop_front(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst != NULL)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	if (tmp->content != NULL)
		del(tmp->content);
	free(tmp);
}
