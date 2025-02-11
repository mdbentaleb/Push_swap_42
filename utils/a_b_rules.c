/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_b_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:59:13 by moben-ta          #+#    #+#             */
/*   Updated: 2025/01/17 18:33:17 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a, 1);
	sb(stack_b, 1);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a, 1);
	rb(stack_b, 1);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a, 1);
	rrb(stack_b, 1);
}
