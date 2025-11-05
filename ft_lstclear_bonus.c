/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:26:51 by aoukaamo          #+#    #+#             */
/*   Updated: 2025/11/05 09:27:20 by aoukaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*current_item;

	if (lst == NULL || del == NULL)
		return ;
	temp = *lst;
	while (temp != NULL)
	{
		current_item = temp->next;
		del(temp->content);
		free(temp);
		temp = current_item;
	}
	*lst = NULL;
}
