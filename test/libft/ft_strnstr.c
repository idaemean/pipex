/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:53:11 by iczarnie          #+#    #+#             */
/*   Updated: 2021/11/24 12:53:11 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (*needle == '\0')
		return ((char *) haystack);
	while (*haystack != '\0' && (len-- >= ft_strlen(needle)))
	{
		if (*haystack == *needle
			&& ft_memcmp(haystack, needle, ft_strlen(needle)) == 0)
			return ((char *) haystack);
		haystack++;
	}
	return (NULL);
}
