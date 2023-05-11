/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dowon <dowon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:02:13 by dowon             #+#    #+#             */
/*   Updated: 2023/05/11 21:18:53 by dowon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	dummy_node;
	t_list	*ptr;
	void	*new_content;

	dummy_node.next = NULL;
	ptr = &dummy_node;
	while (lst)
	{
		new_content = f(lst->content);
		ptr->next = ft_lstnew(new_content);
		if (!(ptr->next && new_content))
		{
			ft_lstclear(&dummy_node.next, del);
			del(new_content);
			return (NULL);
		}
		ptr = ptr->next;
		lst = lst->next;
	}
	ptr = dummy_node.next;
	return (ptr);
}
