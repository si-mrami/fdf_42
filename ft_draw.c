/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:45:31 by mrami             #+#    #+#             */
/*   Updated: 2023/05/28 15:20:23 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* 3D rotation on a point represented by its x, y, and z coordinates */

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
	ptr->x0 -= ptr->width * ptr->zoming / 2;
	ptr->y0 -= ptr->height * ptr->zoming / 2;
	ptr->x1 -= ptr->width * ptr->zoming / 2;
	ptr->y1 -= ptr->height * ptr->zoming / 2;
	ft_rotat_mtx(&ptr->x0, &ptr->y0, ptr->z0, ptr);
	ft_rotat_mtx(&ptr->x1, &ptr->y1, ptr->z1, ptr);
	ptr->x0 += ptr->sc_x;
	ptr->y0 += ptr->sc_y;
	ptr->x1 += ptr->sc_x;
	ptr->y1 += ptr->sc_y;
}

/* get max of tow number */

void	ft_get_max(double x, double y, double stp)
{
	if (fabs(x) > fabs(y))
		stp = fabs(x);
	else
		stp = fabs(y);
}

/* draw line using dda algorithm */

void	ft_dda_algo(t_mtr *ptr)
{
	double	stp;
	int		i;

	ft_control_coordinat(ptr);
	ptr->dx = ptr->x1 - ptr->x0;
	ptr->dy = ptr->y1 - ptr->y0;
	if (fabs(ptr->dx) > fabs(ptr->dy))
		stp = fabs(ptr->dx);
	else
		stp = fabs(ptr->dy);
	ptr->x_inc = ptr->dx / stp;
	ptr->y_inc = ptr->dy / stp;
	i = 0;
	while (i < stp)
	{
		if ((round(ptr->x0) > 0) && (round(ptr->x0) < WIDTH)
			&& (round(ptr->y0) > 0) && (round(ptr->y0) < HEIGHT))
			my_mlx_pixel_put(ptr, round(ptr->x0),
				round(ptr->y0), ptr->color);
		ptr->x0 += ptr->x_inc;
		ptr->y0 += ptr->y_inc;
		i++;
	}
}

/* draw line */

void	ft_draw(t_mtr *ptr)
{
	ptr->j = 0;
	while (ptr->j < ptr->height)
	{
		ptr->i = 0;
		while (ptr->i < ptr->width)
		{
			ptr->color = ptr->mps_color[ptr->j][ptr->i];
			if (ptr->i < ptr->width - 1)
				ft_check_wher_line(ptr, ptr->i, ptr->j, 0);
			if (ptr->j < ptr->height - 1)
				ft_check_wher_line(ptr, ptr->i, ptr->j, 1);
			ptr->i++;
		}
		ptr->j++;
	}
}
