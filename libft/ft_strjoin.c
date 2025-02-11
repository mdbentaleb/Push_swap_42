/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:03:18 by moben-ta          #+#    #+#             */
/*   Updated: 2024/11/06 09:43:08 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	tmp = (char *)malloc((s1_len + s2_len) * sizeof(char) + 1);
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, s1, s1_len + 1);
	ft_strlcat(tmp + s1_len, s2, s2_len + 1);
	return (tmp);
}
