/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:12:42 by mrami             #+#    #+#             */
/*   Updated: 2023/04/21 21:25:59 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE	10
# endif

size_t	ft_strlen(char *s);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *s, int c);
char	*ft_get_line(char *str);
char	*ft_next_str(char *r_str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_read_str(int fd, char *str);
char	*get_next_line(int fd);

#endif