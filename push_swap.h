/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:38:22 by moben-ta          #+#    #+#             */
/*   Updated: 2025/01/28 15:38:26 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_list {
	int				value;
	int				index;
	struct s_list	*next;
}	t_list;

/*-------------- rules --------------*/
void	sa(t_list **stack, int check);
void	pa(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack, int check);
void	rra(t_list **stack, int check);
void	sb(t_list **stack, int check);
void	pb(t_list **stack_b, t_list **stack_a);
void	rb(t_list **stack, int check);
void	rrb(t_list **stack, int check);
void	ss(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

/*------ linked list operations -------*/
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

/*----------- check errors -----------*/
int		*ft_get_numbers(int arc, char **arv, int *size);

/*-------------- utils_1 --------------*/
void	ft_free(char **tab);
void	ft_print_error(void *p);
void	ft_check_is_sorted(t_list **stack);
void	ft_index_stack(t_list **stack);
void	ft_free(char **tab);

/*-------------- utils_2 --------------*/
int		ft_get_max_pos(t_list **stack);
void	aditional(int *start, int *end);
int		ft_get_min_pos(t_list **stack);
void	ft_free_stack(t_list **stack);

/*-------------- sort --------------*/
void	ft_sort_three(t_list **stack);
void	ft_sort(t_list **stack_a, t_list **stack_b, int size);
void	ft_sort_five(t_list **stack_a, t_list **stack_b);
void	ft_sort_four(t_list **stack_a, t_list **stack_b);

#endif