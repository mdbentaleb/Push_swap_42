/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:25:27 by moben-ta          #+#    #+#             */
/*   Updated: 2024/10/31 14:13:02 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	num_len(long nbr)
{
	int	nbr_len;

	nbr_len = 0;
	if (nbr < 0)
	{
		nbr_len++;
		nbr *= -1;
	}
	if (nbr == 0)
		nbr_len++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		nbr_len++;
	}
	return (nbr_len);
}

char	*ft_itoa(int nb)
{
	int		nbr_len;
	char	*tmp;
	int		last;
	long	n;

	n = nb;
	nbr_len = num_len(n);
	tmp = (char *)malloc(sizeof(char) * (nbr_len + 1));
	if (!tmp)
		return (NULL);
	if (n < 0)
	{
		tmp[0] = '-';
		n *= -1;
	}
	if (n == 0)
		tmp[0] = '0';
	last = nbr_len;
	while (n != 0)
	{
		tmp[--nbr_len] = n % 10 + '0';
		n = n / 10;
	}
	tmp[last] = '\0';
	return (tmp);
}
