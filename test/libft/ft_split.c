/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:40:24 by iczarnie          #+#    #+#             */
/*   Updated: 2021/11/30 21:40:24 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_all(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static unsigned int	ft_count(const char *s, char c)
{
	unsigned int	count;
	unsigned int	flag;

	count = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		if (*s == c)
			flag = 0;
		s++;
	}
	return (count);
}

static char	*duplicate(char const *s, int start, int end, char **split)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *)malloc((end - start + 1) * sizeof(char));
	if (!word)
		split = ft_free_all(split);
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static char	**ft_splitted(char const *s, char c, char **splitted)
{
	int				flag;
	unsigned int	word_count;
	int				start;
	size_t			i;

	i = 0;
	word_count = 0;
	flag = 0;
	while (word_count < ft_count(s, c))
	{
		if (s[i] != c && flag == 0)
		{
			flag = 1;
			start = i;
		}
		else if (((s[i] == c || i == ft_strlen(s)) && flag == 1))
		{
			splitted[word_count++] = duplicate(s, start, i, splitted);
			flag = 0;
		}
		i++;
	}
	splitted[word_count] = NULL;
	return (splitted);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;

	if (!s)
		return (NULL);
	if (ft_strlen(s) == 0)
	{
		splitted = malloc(1 * sizeof(char *));
		splitted[0] = NULL;
		return (splitted);
	}	
	splitted = (char **)malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!splitted)
		return (NULL);
	splitted = ft_splitted(s, c, splitted);
	return (splitted);
}
