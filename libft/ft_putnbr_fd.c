/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:35:10 by moben-ta          #+#    #+#             */
/*   Updated: 2024/11/06 09:56:56 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd ('-', fd);
		nb *= -1;
	}
	if (nb < 10)
		ft_putchar_fd (nb + '0', fd);
	else
	{
		ft_putnbr_fd (nb / 10, fd);
		ft_putchar_fd ((nb % 10) + '0', fd);
	}
}
