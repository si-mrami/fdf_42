/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:14:30 by mrami             #+#    #+#             */
/*   Updated: 2023/05/22 19:26:25 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* check horizontal or vertical */

void	ft_check_wher_line(t_mtr *ptr,int x, int y, int checker)
{
	if (checker == 0)
	{
		ptr->x0 = x;
		ptr->x1 = x + 1;
		ptr->y0 = y;
		ptr->y1 = y;
	}
	else if (checker == 1)
	{
		ptr->x0 = x;
		ptr->x1 = x;
		ptr->y0 = y;
		ptr->y1 = y + 1;
	}
	// ft_tronsformation(ptr);
	ft_dda_algo(ptr);
	// puts("yassin");
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
			// printf("color = %d\n", ptr->color);
			if (ptr->i < ptr->width - 1)
			{
				ft_check_wher_line(ptr, ptr->i, ptr->j, 0);

			}
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
	printf("test01\n");
	ft_draw(&ptr);
	// while (ptr.i < ptr.height)
	// {
	// 	ft_control_coordinat(&ptr);
	// 	while (ptr.j < ptr.width)
	// 	{
	// 		if (ptr.i < ptr.width - 1)
	// 			ft_draw_myline(&ptr);
	// 		if (ptr.j < ptr.height)
	// 			ft_draw_myline(&ptr);
	// 		ptr.j++;
	// 	}
	// 	ptr.i++;
	// }
	mlx_loop(ptr.mlx_ptr);
	return (0);
}
