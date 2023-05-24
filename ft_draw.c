/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:45:31 by mrami             #+#    #+#             */
/*   Updated: 2023/05/24 20:06:26 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotat_mtx(double *x, double *y, int z, t_mtr *ptr)
{
	double	xt;
	double	yt;
	double	zt;

	yt = *y;
	zt = z;

	xt = *x;
	*y = yt * cos(ptr->teta_x) - (zt * sin(ptr->teta_x));
	z = yt * sin(ptr->teta_x) + (zt * cos(ptr->teta_x));

	xt = *x * cos(ptr->teta_y) + (z * sin(ptr->teta_y));
	yt = *y;
	zt = *x * (-sin(ptr->teta_y)) + z * cos(ptr->teta_y);

	*x = xt * cos(ptr->teta_z) - (yt * sin(ptr->teta_z));
	*y = xt * sin(ptr->teta_z) + (yt * cos(ptr->teta_z));
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
		ptr->sc_x = WIDTH / 2 - ptr->width * ptr->zoming / 2;
		ptr->sc_y = HEIGHT / 2 - ptr->height * ptr->zoming / 2;
		mlx_pixel_put(ptr->mlx_ptr, ptr->win_ptr, round(ptr->x0) + ptr->sc_x,
			round(ptr->y0) + ptr->sc_y, ptr->color);
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
