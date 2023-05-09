/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:48:49 by mrami             #+#    #+#             */
/*   Updated: 2023/05/07 15:52:01 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_words(const char *s, char c)
{
	int	word;
	int	i;

	word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != '\0' && s[i] != c)
			{
				i++;
			}
			if (s[i] == '\0')
				return (word);
		}
		i++;
	}
	return (word);
}

char	**ft_free(char **dst, int len)
{
	int	j;

	j = 0;
	while (j < len)
	{
		free(dst[j]);
		j++;
	}
	free(dst);
	return (NULL);
}

char	**ft_allocation(char **dst, char const *s, char c)
{
	size_t	i;
	size_t	index;
	int		j;

	i = 0;
	j = 0;
	while (j < ft_words(s, c))
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		index = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (index < i)
		{
			dst[j] = ft_substr(s, index, i - index);
			if (!dst[j])
				return (ft_free(dst, j));
		}
		j++;
	}
	dst[j] = 0;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;

	if (!s)
		return (NULL);
	dest = (char **)malloc((ft_words(s, c) + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	dest = ft_allocation(dest, s, c);
	return (dest);
}
