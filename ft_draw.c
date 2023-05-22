/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:45:31 by mrami             #+#    #+#             */
/*   Updated: 2023/05/22 19:22:32 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	ft_rotat_mtx(double *x, double *y, int z, t_mtr *ptr)
{
	double xt;
	double yt;
	double	zt;

	xt = *x;
	yt = *y;
	zt = z;
	ptr->x_prime = xt * cos(ptr->teta) - yt * sin(ptr->teta);
	ptr->y_prime = xt * sin(ptr->teta) + yt * cos(ptr->teta);
	ptr->z_prime = zt;
}

/* controlling and manipulating coordination */

void	ft_control_coordinat(t_mtr *ptr)
{
	ptr->z0 = ptr->mtx[ptr->j][ptr->i] * ptr->factor;
	ptr->z1 = ptr->mtx[ptr->j][ptr->i] * ptr->factor;
	ptr->x0 *= ptr->zoming;
	ptr->x1 *= ptr->zoming;
	ptr->y0 *= ptr->zoming;
	ptr->y1 *= ptr->zoming;
	
	ft_rotat_mtx(&ptr->x0, &ptr->y0, ptr->z0, ptr);
	ft_rotat_mtx(&ptr->x1, &ptr->y1, ptr->z1, ptr);
}

/* draw line using dda algorithm */

void	ft_dda_algo(t_mtr *ptr)
{
	int steps;
	double x_increment, y_increment;
	double x, y;

	double dx = ptr->x1 - ptr->x0;
	double dy = ptr->y1 - ptr->y0;
	if (fabs(dx) > fabs(dy))
		steps = dx;
	else
		steps = dy;
	x_increment = dx / steps;
	y_increment = dy / steps;

	x = ptr->x0;
	y = ptr->y0;
	ft_control_coordinat(ptr);
	int i = 1;
	while (++i < steps)
	{
		puts("dda");
		mlx_pixel_put(ptr->mlx_ptr, ptr->win_ptr, round(x), round(y), ptr->color);
		x += x_increment;
		y += y_increment;
	}
}
	/* 
	<----- trasformation 3D to 2D----->
	1- scaling!
	2- translation!
	3- rotation 3D to 2D!
	*/
