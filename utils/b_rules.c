/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_rules.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:09:22 by moben-ta          #+#    #+#             */
/*   Updated: 2025/01/23 16:00:03 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sb(t_list **stack, int check)
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
			ft_putstr_fd("sb\n", 1);
	}
}

void	pb(t_list **stack_b, t_list **stack_a)
{
	t_list	*tmp;

	if (*stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
		ft_putstr_fd("pb\n", 1);
	}
}

void	rb(t_list **stack, int check)
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
			ft_putstr_fd("rb\n", 1);
	}
}

void	rrb(t_list **stack, int check)
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
			ft_putstr_fd("rrb\n", 1);
	}
}
