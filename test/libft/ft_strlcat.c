/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:57:04 by iczarnie          #+#    #+#             */
/*   Updated: 2021/11/23 17:57:04 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_l;
	size_t	src_l;

	j = 0;
	dst_l = ft_strlen(dst);
	src_l = ft_strlen(src);
	i = dst_l;
	if (size < dst_l)
		return (size + src_l);
	while (src[j] && j < (size - dst_l - 1) && dst_l < size)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (dst_l + src_l);
}
