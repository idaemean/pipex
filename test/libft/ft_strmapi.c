/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:06:20 by iczarnie          #+#    #+#             */
/*   Updated: 2021/11/30 12:06:20 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*modified;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	modified = ft_strdup(s);
	if (!modified)
		return (NULL);
	while (s[i])
	{
		modified[i] = f(i, s[i]);
		i++;
	}
	return (modified);
}
