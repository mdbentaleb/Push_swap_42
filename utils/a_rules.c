/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_rules.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:55:36 by moben-ta          #+#    #+#             */
/*   Updated: 2025/01/23 15:57:42 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list **stack, int check)
{
	t_list	*head;
	t_list	*tmp;

	if (*stack && (*stack)->next)
	{
		head = *stack;
		tmp = head->next;
		head->next = tmp->next;
		tmp->next = head;
		*stack = tmp;
		if (check == 0)
			ft_putstr_fd("sa\n", 1);
		else if (check == 1)
			ft_putstr_fd("ss\n", 1);
	}
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_b)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
		ft_putstr_fd("pa\n", 1);
	}
}

void	ra(t_list **stack, int check)
{
	t_list	*tmp;
	t_list	*last;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = tmp;
		tmp->next = NULL;
		if (check == 0)
			ft_putstr_fd("ra\n", 1);
		else if (check == 1)
			ft_putstr_fd("rr\n", 1);
	}
}

void	rra(t_list **stack, int check)
{
	t_list	*tmp;
	t_list	*last;

	if (*stack && (*stack)->next)
	{
		last = *stack;
		while (last->next)
		{
			tmp = last;
			last = last->next;
		}
		tmp->next = NULL;
		last->next = *stack;
		*stack = last;
		if (check == 0)
			ft_putstr_fd("rra\n", 1);
		else if (check == 1)
			ft_putstr_fd("rrr\n", 1);
	}
}
