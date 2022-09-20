/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:09:13 by iczarnie          #+#    #+#             */
/*   Updated: 2021/11/25 11:09:13 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	size_t			i;

	i = 0;
	if (!s)
		return (NULL);
	substring = (char *)malloc(len + 1 * sizeof(char));
	if (!substring)
		return (NULL);
	while (i < len && start < ft_strlen((char *)s))
	{
		substring[i++] = s[start++];
	}
	substring[i] = '\0';
	return (substring);
}
