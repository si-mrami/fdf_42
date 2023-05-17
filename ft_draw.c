/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:45:31 by mrami             #+#    #+#             */
/*   Updated: 2023/05/17 15:12:12 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_abs(int n)
{
	if (n < 0)
		n = n * (-1);
	return (n);
}

/* draw line using dda algorithm */

void	ft_draw_line(void *mlx_ptr, void *win_ptr, int X0, int Y0, int X1, int Y1, int color)
{
	int		dx;
	int		dy;
	int		stps;
	double	Xinc;
	double	Yinc;
	double	X;
	double	Y;
	int		i;

	dx = X1 - X0;
	dy = Y1 - Y0;

	if (ft_abs(dx) > ft_abs(dy))
		stps = ft_abs(dx);
	else
		stps = ft_abs(dy);

	Xinc = dx / (double)stps;
	Yinc = dy / (double)stps;

	X = round(X0);
	Y = round(Y0);
	i = 0;
	while (i <= stps)
	{
		if (X >= 0 && X < WIDTH && Y >= 0 && Y < HEIGHT)
			mlx_pixel_put(mlx_ptr, win_ptr, X, Y, color);
		X += Xinc;
		Y += Yinc;
		i++;
	}
}
	/* 
	<----- trasformation 3D to 2D----->
	1- scaling!
	2- translation!
	3- rotation 3D to 2D!
	*/
