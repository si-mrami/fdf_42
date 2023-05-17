/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:12:42 by mrami             #+#    #+#             */
/*   Updated: 2023/05/17 15:01:55 by mrami            ###   ########.fr       */
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
#include<math.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

#define WIDTH 1920
#define HEIGHT 1080

typedef	struct	s_mtr
{
	int		x0;
	int		x1;
	int		y0;
	int		y1;
	int		X0;
	int		X1;
	int		Y0;
	int		Y1;
	int		width;
	int		height;
	void	*mlx_ptr;
	void	*win_ptr;
	char	**mtx;
	char	*mps;
	char	*read;
}	t_mtr;

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
void	ft_draw_line(void *mlx_ptr, void *win_ptr, int X0, int Y0, int X1, int Y1, int color);

#endif