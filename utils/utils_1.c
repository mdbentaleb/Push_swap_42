/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:35:37 by moben-ta          #+#    #+#             */
/*   Updated: 2025/01/24 16:46:22 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*----------- print error ----------*/
void	ft_print_error(void *p)
{
	if (p)
		free(p);
	ft_putendl_fd("Error", 2);
	exit (1);
}

/*-------------- free -------------*/
void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	while (i > 0)
	{
		i--;
		free(tab[i]);
	}
	free (tab);
}

/*---------- get min value ---------*/
t_list	*ft_get_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		check;

	head = *stack;
	min = NULL;
	check = 0;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (check == 0 || head->value < min->value))
			{
				min = head;
				check = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

/*---------- stack indexing --------*/
void	ft_index_stack(t_list **stack)
{
	t_list	*head;
	int		index;

	head = ft_get_min(stack);
	index = 0;
	while (head)
	{
		head->index = index++;
		head = ft_get_min(stack);
	}
}

/*---------- check if stack sorted ---------*/
void	ft_check_is_sorted(t_list **stack)
{
	t_list	*head;
	int		i;

	head = *stack;
	i = 0;
	while (head)
	{
		if (i == head->index)
		{
			if (head->next == NULL)
				exit(0);
			i++;
		}
		else
			break ;
		head = head->next;
	}
}
