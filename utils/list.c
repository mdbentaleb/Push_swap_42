/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:33:34 by moben-ta          #+#    #+#             */
/*   Updated: 2025/01/24 17:40:37 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*------------new node------------*/
t_list	*ft_lstnew(int content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->value = content;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

/*------------last node------------*/
t_list	*ft_lstlast(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*------------add back------------*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		(*lst)->next = NULL;
	}
	else
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
		new->next = NULL;
	}
}
