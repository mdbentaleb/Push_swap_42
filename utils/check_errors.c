/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:22:57 by moben-ta          #+#    #+#             */
/*   Updated: 2025/01/25 13:59:58 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_is_dupnbr(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
				ft_print_error(tab);
			j++;
		}
		i++;
	}
}

void	ft_check_errors(char *str, char *merged)
{
	int		i;
	char	c;

	i = 0;
	if (str[0] == '\0')
		ft_print_error(merged);
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
	{
		if ((str[i] == ' ' || str[i] == '\t') && str[i + 1] == '\0')
			ft_print_error (merged);
		i++;
	}
	while (*str)
	{
		c = *str;
		if (c == ' ' || c == '\t' || c == '+' || c == '-' || ft_isdigit(c))
		{
			if (((c == '-' || c == '+') && !ft_isdigit(*(str + 1)))
				|| (ft_isdigit(c) && (*(str + 1) == '-' || *(str + 1) == '+')))
				ft_print_error(merged);
		}
		else
			ft_print_error(merged);
		str++;
	}
}

char	*ft_merge_args(int argc, char **argv)
{
	char	*merged;
	char	*temp;
	int		i;

	merged = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		ft_check_errors(argv[i], merged);
		temp = ft_strjoin(merged, argv[i]);
		free(merged);
		merged = temp;
		if (i + 1 < argc)
		{
			temp = ft_strjoin(merged, " ");
			free(merged);
			merged = temp;
		}
		i++;
	}
	return (merged);
}

char	**ft_extract_args(int argc, char **argv)
{
	char	*merged;
	char	**result;

	merged = ft_merge_args(argc, argv);
	result = ft_split(merged, ' ');
	free(merged);
	return (result);
}

int	*ft_get_numbers(int arc, char **arv, int *size)
{
	char	**args;
	int		*tab;
	int		i;

	i = 0;
	args = ft_extract_args(arc, arv);
	while (args[i])
		i++;
	*size += i;
	tab = malloc(sizeof(int) * i);
	if (!tab)
	{
		ft_free(args);
		return (NULL);
	}
	i = 0;
	while (i < *size)
	{
		tab[i] = ft_atoi(args[i], tab);
		i++;
	}
	ft_free(args);
	ft_is_dupnbr(tab, *size);
	return (tab);
}
