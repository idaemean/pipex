/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:40:51 by iczarnie          #+#    #+#             */
/*   Updated: 2021/11/25 19:40:51 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_joined(char const *s1, char const *s2, char *joined)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < ft_strlen(s1))
	{
		joined[k] = s1[i];
		i++;
		k++;
	}
	while (j < ft_strlen(s2))
	{
		joined[k] = s2[j];
		j++;
		k++;
	}
	joined[k] = '\0';
	return (joined);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;

	if (!s1 || !s2)
		return (NULL);
	joined = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
		return (NULL);
	joined = ft_joined(s1, s2, joined);
	return (joined);
}
