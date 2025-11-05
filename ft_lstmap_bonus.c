/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:37:38 by aoukaamo          #+#    #+#             */
/*   Updated: 2025/11/05 09:37:46 by aoukaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_list;
	t_list	*n_node;
	void	*n_content;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	n_list = NULL;
	while (lst != NULL)
	{
		n_content = f(lst->content);
		if (n_content == NULL)
		{
			ft_lstclear(&n_list, del);
			return (NULL);
		}
		n_node = ft_lstnew(n_content);
		if (n_node == NULL)
		{
			ft_lstclear(&n_list, del);
			return (NULL);
		}
		ft_lstadd_back(&n_list, n_node);
		lst = lst->next;
	}
	return (n_list);
}
