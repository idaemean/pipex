/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:16:04 by iczarnie          #+#    #+#             */
/*   Updated: 2021/11/26 13:16:04 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	stop;
	char	*trimmed;
	size_t	i;

	start = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	stop = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (stop > start && ft_strchr(set, s1[stop - 1]))
		stop--;
	trimmed = (char *)malloc(sizeof(char) * (stop - start + 1));
	if (!trimmed)
		return (NULL);
	while (start < stop)
	{
		trimmed[i] = s1[start];
		i++;
		start++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}
