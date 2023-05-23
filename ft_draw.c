/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:45:31 by mrami             #+#    #+#             */
/*   Updated: 2023/05/23 20:08:23 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotat_mtx(double *x, double *y, int z, t_mtr *ptr)
{
	double	xt;
	double	yt;

	xt = *x;
	yt = *y;
	*x = xt * cos(ptr->teta_x) - yt * sin(ptr->teta_x);
	*y = xt * sin(ptr->teta_x) + yt * cos(ptr->teta_x) - z;
}

/* controlling and manipulating coordination */

void	ft_control_coordinat(t_mtr *ptr)
{
	ptr->x0 *= ptr->zoming;
	ptr->y0 *= ptr->zoming;
	ptr->z0 *= ptr->zoming_z;
	ptr->x1 *= ptr->zoming;
	ptr->y1 *= ptr->zoming;
	ptr->z1 *= ptr->zoming_z;
	ft_rotat_mtx(&ptr->x0, &ptr->y0, ptr->z0, ptr);
	ft_rotat_mtx(&ptr->x1, &ptr->y1, ptr->z1, ptr);
}

/* draw line using dda algorithm */

void	ft_dda_algo(t_mtr *ptr)
{
	double	stp;
	double	dx;
	double	dy;
	int		i;

	ft_control_coordinat(ptr);
	dx = ptr->x1 - ptr->x0;
	dy = ptr->y1 - ptr->y0;
	if (fabs(dx) > fabs(dy))
		stp = dx;
	else
		stp = dy;
	ptr->x_inc = dx / stp;
	ptr->y_inc = dy / stp;
	i = 0;
	while (i < stp)
	{
		mlx_pixel_put(ptr->mlx_ptr, ptr->win_ptr, round(ptr->x0),
			round(ptr->y0), ptr->color);
		ptr->x0 += ptr->x_inc;
		ptr->y0 += ptr->y_inc;
		i++;
	}
}
	/* 
	<----- trasformation 3D to 2D----->
	1- scaling!
	2- translation!
	3- rotation 3D to 2D!
	*/
