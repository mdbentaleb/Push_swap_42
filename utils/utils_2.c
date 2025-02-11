/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:44:14 by moben-ta          #+#    #+#             */
/*   Updated: 2025/01/24 17:48:41 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	aditional(int *start, int *end)
{
	(*start)++;
	(*end)++;
}

/*---------- get min value ---------*/
int	ft_get_min_pos(t_list **stack)
{
	t_list	*head;
	int		pos;
	int		min_value;
	int		min_pos;

	head = *stack;
	min_value = head->value;
	min_pos = 0;
	pos = 0;
	while (head)
	{
		if (head->value < min_value)
		{
			min_value = head->value;
			min_pos = pos;
		}
		head = head->next;
		pos++;
	}
	return (min_pos);
}

/*---------- get min value ---------*/
int	ft_get_max_pos(t_list **stack)
{
	t_list	*head;
	int		pos;
	int		max_value;
	int		max_pos;

	head = *stack;
	max_value = head->value;
	max_pos = 0;
	pos = 0;
	while (head)
	{
		if (head->value > max_value)
		{
			max_value = head->value;
			max_pos = pos;
		}
		head = head->next;
		pos++;
	}
	return (max_pos);
}

void	ft_free_stack(t_list **stack)
{
	t_list	*tmp;

	while (*stack)
	{
		tmp = *stack; 
		*stack = (*stack)->next;
		free(tmp);
	}
}
