/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:14:30 by mrami             #+#    #+#             */
/*   Updated: 2023/05/24 20:04:24 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* check horizontal or vertical */

void	ft_check_wher_line(t_mtr *ptr, int x, int y, int checker)
{
	if (checker == 0)
	{
		ptr->x0 = x;
		ptr->y0 = y;
		ptr->z0 = ptr->mtx[ptr->j][ptr->i] * ptr->factor;
		ptr->x1 = x + 1;
		ptr->y1 = y;
		ptr->z1 = ptr->mtx[ptr->j][ptr->i + 1] * ptr->factor;
	}
	else if (checker == 1)
	{
		ptr->x0 = x;
		ptr->y0 = y;
		ptr->z0 = ptr->mtx[ptr->j][ptr->i] * ptr->factor;
		ptr->x1 = x;
		ptr->y1 = y + 1;
		ptr->z1 = ptr->mtx[ptr->j + 1][ptr->i] * ptr->factor;
	}
	ft_tronsformation(ptr);
	ft_dda_algo(ptr);
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

int	main(int argc, char *argv[])
{
	t_mtr	ptr;

	(void)argc;
	ptr.mlx_ptr = mlx_init();
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, WIDTH, HEIGHT, "fdf_42");
	ptr.height = ft_calc_height(argv[1]);
	ptr.width = ft_calc_width(argv[1]);
	ft_read_maps(argv[1], &ptr);
	ft_draw(&ptr);
	mlx_loop(ptr.mlx_ptr);
	return (0);
}
