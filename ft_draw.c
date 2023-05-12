/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:45:31 by mrami             #+#    #+#             */
/*   Updated: 2023/05/12 17:12:35 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_abs(int n)
{
	if (n < 0)
		n = n * (-1);
	return (n);
}

/* fraw line using dda algorithm */

void	ft_draw_line(void *win, void *mlx, t_mtr point)
{
	int		dx;
	int		dy;
	float	x_inc;
	float	y_inc;
	int		stp;
	float	x;
	float	y;
	int		i;

	dx = point.x1 - point.x0;
	dy = point.y1 - point.y0;
	if (abs(dx) > abs(dy))
		stp = abs(dx);
	else
		stp = abs(dy);
	x_inc = dx / (float)stp;
	y_inc = dy / (float)stp;
	x = point.x0;
	y = point.y0;
	i = 0;
	while (i <= stp)
	{
		mlx_pixel_put(mlx, win, (int)x, (int)y, 0xFFFFFF);
		x += x_inc;
		y += y_inc;
	}
}
