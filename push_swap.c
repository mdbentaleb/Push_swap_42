/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:38:31 by moben-ta          #+#    #+#             */
/*   Updated: 2025/02/26 12:33:52 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_stack(t_list **stack, int *tab, int size)
{
	t_list	*new_node;
	int		i;

	i = 0;
	while (i < size)
	{
		new_node = ft_lstnew(tab[i]);
		if (!new_node)
		{
			ft_free_stack(stack);
			return ;
		}
		ft_lstadd_back(stack, new_node);
		i++;
	}
	ft_index_stack(stack);
}

void	ft_select_sort(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2)
		sa(stack_a, 0);
	else if (size == 3)
		ft_sort_three(stack_a);
	else if (size == 4)
		ft_sort_four(stack_a, stack_b);
	else if (size == 5)
		ft_sort_five(stack_a, stack_b);
	else
		ft_sort(stack_a, stack_b, size);
}

int	main(int arc, char **arv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*tab;
	int		size;

	if (arc < 2)
		return (-1);
	stack_a = NULL;
	stack_b = NULL;
	tab = NULL;
	size = 0;
	tab = ft_get_numbers(arc, arv, &size);
	if (!tab || size == 1)
	{
		free (tab);
		return (-1);
	}
	ft_init_stack(&stack_a, tab, size);
	free(tab);
	ft_check_is_sorted(&stack_a);
	ft_select_sort(&stack_a, &stack_b, size);
	ft_free_stack(&stack_a);
	return (0);
}
