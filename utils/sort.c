/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:39:06 by moben-ta          #+#    #+#             */
/*   Updated: 2025/01/28 15:39:08 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_three(t_list **stack)
{
	if (ft_get_min_pos(stack) == 2)
	{
		if ((*stack)->index < (*stack)->next->index)
			rra(stack, 0);
		else if ((*stack)->index > (*stack)->next->index)
		{
			sa(stack, 0);
			rra(stack, 0);
		}
	}
	else if (ft_get_min_pos(stack) == 1)
	{
		if ((*stack)->index < (*stack)->next->next->index)
			sa(stack, 0);
		else if ((*stack)->index > (*stack)->next->next->index)
			ra(stack, 0);
	}
	else if (ft_get_min_pos(stack) == 0)
	{
		if ((*stack)->next->index > (*stack)->next->next->index)
		{
			rra(stack, 0);
			sa(stack, 0);
		}
	}
}

void	ft_sort_four(t_list **stack_a, t_list **stack_b)
{
	int		min_pos;

	min_pos = ft_get_min_pos(stack_a);
	if (min_pos == 0)
		pb(stack_b, stack_a);
	else
	{
		if (min_pos == 2)
			ra(stack_a, 0);
		if (min_pos == 1 || min_pos == 2)
			sa(stack_a, 0);
		if (min_pos == 3)
			rra(stack_a, 0);
		pb(stack_b, stack_a);
	}
	ft_sort_three(stack_a);
	pa(stack_a, stack_b);
}


void	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	int		min_pos;

	min_pos = ft_get_min_pos(stack_a);
	if (min_pos == 0)
		pb(stack_b, stack_a);
	else
	{
		if (min_pos == 2)
			ra(stack_a, 0);
		if (min_pos == 1 || min_pos == 2)
			sa(stack_a, 0);
		if (min_pos == 3)
			rra(stack_a, 0);
		if (min_pos == 3 || min_pos == 4)
			rra(stack_a, 0);
		pb(stack_b, stack_a);
	}
	ft_sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	fill_stack_a(t_list **stack_a, t_list **stack_b, int size)
{
	int	pos;

	while (*stack_b)
	{
		pos = ft_get_max_pos(stack_b);
		if (pos == 0)
		{
			pa(stack_a, stack_b);
			size--;
		}
		else if (pos <= size / 2)
			rb(stack_b, 0);
		else if (pos > size / 2)
			rrb (stack_b, 0);
	}
}

void	ft_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	start;
	int	end;

	start = 0;
	end = 15;
	if (size > 100)
		end = 35;
	while (*stack_a)
	{
		if ((*stack_a)->index <= start)
		{
			pb(stack_b, stack_a);
			rb(stack_b, 0);
			aditional(&start, &end);
		}
		else if ((*stack_a)->index > start && (*stack_a)->index <= end)
		{
			pb(stack_b, stack_a);
			aditional(&start, &end);
		}
		else if ((*stack_a)->index > end)
			ra(stack_a, 0);
	}
	fill_stack_a(stack_a, stack_b, size);
}
