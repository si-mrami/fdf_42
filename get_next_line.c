/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 00:10:33 by mrami             #+#    #+#             */
/*   Updated: 2023/04/18 22:13:39 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (!s1)
		s1 = ft_strdup("");
	join = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!join)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			join[i] = s1[i];
	while (s2[j] != '\0')
		join[i++] = s2[j++];
	join[i] = '\0';
	free(s1);
	return (join);
}

char	*ft_read_str(int fd, char *str)
{
	char	*buff;
	int		r_byte;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	r_byte = 1;
	while (!ft_strchr(str, '\n') && r_byte != 0)
	{
		r_byte = read(fd, buff, BUFFER_SIZE);
		if (r_byte == -1)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		buff[r_byte] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	str = ft_read_str(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	str = ft_next_str(str);
	return (line);
}
