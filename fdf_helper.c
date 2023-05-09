/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:49:18 by mrami             #+#    #+#             */
/*   Updated: 2023/05/07 15:51:59 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	dst = malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	j = 0;
	while ((s[start + i] != '\0') && (i < len))
	{
		dst[j] = s[start + i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dst);
}