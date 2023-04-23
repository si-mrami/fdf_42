/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:32:35 by mrami             #+#    #+#             */
/*   Updated: 2023/04/23 10:12:48 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include"fdf.h"

void	ft_draw_line(void *mlx, void *win, int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
	int sx, sy;
    int err = dx - dy;
    int x = x0;
    int y = y0;

	if (x0 < x1)
		sx = 1;
	else
		sx = -1;
	if (y0 < y1)
		sy = 1;
	else
		sy = -1;
    
    while (x != x1 || y != y1)
	{
        mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
        int e2 = 2 * err;
        if (e2 > -dy)
		{
            err -= dy;
            x += sx;
        }
        if (e2 < dx)
		{
            err += dx;
            y += sy;
        }
    }
}

int main(int argc, char *argv[])
{
	void	*mlx;
	void	*win;
	int		x0;
	int		x1;
	int		y0;
	int		y1;
	char	*map_name;
	int		fd;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	while ((map_name = get_next_line(fd)))
	{
		printf("%s", map_name);
		free(map_name);
	}
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1260, "fdf_42");
	x0 = 200;
	x1 = 200;
	y0 = 100;
	y1 = 100;
	while ((x0 != 700 && x1 != 700) && (y0 != 700 && y1 != 700))
	{
		ft_draw_line(mlx, win, x0, 100, x1, 550);
		ft_draw_line(mlx, win, 200, y0, 650, y1);
		x0 = x1 += 50;
		y0 = y1 += 50;
	}
	mlx_loop(mlx);
	return (0);
}
