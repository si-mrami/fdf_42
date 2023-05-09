/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:12:42 by mrami             #+#    #+#             */
/*   Updated: 2023/05/09 12:57:57 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include<unistd.h>
# include<string.h>
# include<fcntl.h>
# include<stdio.h>
# include<mlx.h>
# include<stdlib.h>
# include<stdio.h>
# include<limits.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

typedef	struct	s_point
{
	int		x;
	int		y;
	char	*ptr;
	int		maps_len;
}	t_point;

size_t	ft_strlen(char const *s);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *s, int c);
char	*ft_get_line(char *str);
char	*ft_next_str(char *r_str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_read_str(int fd, char *str);
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_free(char **dst, int len);
char	**ft_allocation(char **dst, char const *s, char c);
char	**ft_split(char const *s, char c);

#endif