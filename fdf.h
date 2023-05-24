/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:12:42 by mrami             #+#    #+#             */
/*   Updated: 2023/05/24 16:11:06 by mrami            ###   ########.fr       */
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
# include<math.h>

# ifndef BUFFER_SIZE
#define	BUFFER_SIZE 10
# endif

#define WIDTH 1920
#define HEIGHT 1080

typedef	struct	s_mtr
{
	int		width;
	int		height;
	void	*mlx_ptr;
	void	*win_ptr;
	int		**mtx;
	int		**mps_color;
	double	teta_x;
	double	teta_y;
	double	teta_z;
	double	x0;
	double	y0;
	double	x1;
	double	y1;
	double	z0;
	double	z1;
	double	zoming;
	double	zoming_z;
	double	factor;
	int		i;
	int		j;
	int		color;
	double	x_inc;
	double	y_inc;
	int		sc_x;
	int		sc_y;
}	t_mtr;

int		ft_atoi(char *str);
int		ft_calc_width(char *maps);
int		ft_hex_to_dec(char *hexa);
int		ft_calc_height(char *maps);
int		ft_length_of_spliter(char **spl);
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
void	ft_read_maps_color(int *color, char *line, int *map_line);
void	ft_read_maps(char *mps, t_mtr *ptr);
void	ft_dda_algo(t_mtr *ptr);
void	ft_control_coordinat(t_mtr *ptr);
void	ft_tronsformation(t_mtr *ptr);

#endif