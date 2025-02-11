/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:17:25 by moben-ta          #+#    #+#             */
/*   Updated: 2024/11/06 14:44:14 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	tmp = ft_calloc(len + 1, (sizeof(char)));
	if (!tmp)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && i < len)
	{
		tmp[i] = s[start];
		i++;
		start++;
	}
	return (tmp);
}
