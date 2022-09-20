/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:13:46 by iczarnie          #+#    #+#             */
/*   Updated: 2021/11/23 18:13:46 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	b;

	b = (unsigned char) c;
	while (*s)
	{
		if (*s == b)
			return ((char *)s);
		s++;
	}
	if (*s == b)
		return ((char *)s);
	return (NULL);
}
