/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:14:30 by mrami             #+#    #+#             */
/*   Updated: 2023/05/25 19:03:57 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* check if horizontal or vertical line */

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
	ft_dda_algo(ptr);
}

/* control my key */

int	ft_control_my_key(int key, t_mtr *ptr)
{
	if (key == 53)
		exit(0);
	if (key == 126)
		ptr->sc_y -= 30;
	if (key == 125)
		ptr->sc_y += 30;
	if (key == 123)
		ptr->sc_x -= 30;
	if (key == 124)
		ptr->sc_x += 30;
	if (key == 69)
		ptr->zoming_z += 1;
	if (key == 78)
		ptr->zoming_z -= 1;
	if (key == 6)
		ptr->teta_x += ft_convert(5);
	if (key == 7)
		ptr->teta_x -= ft_convert(5);
	if (key == 24)
		ptr->zoming += 1;
	if (key == 27 && ptr->zoming >= 1)
		ptr->zoming -= 1;
	ft_rest(key, ptr);
	ft_rest_my_imge(ptr);
	return (0);
}

/* my_mlx_pixel_put */

void	my_mlx_pixel_put(t_mtr *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mlxd.addr + (y * data->mlxd.line_length + x
			* (data->mlxd.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/* close my programe */

int	ft_is_close(int keycode)
{
	if (keycode)
	{
		exit(1);
	}
	return (0);
}

/* main programme */

int	main(int argc, char *argv[])
{
	t_mtr	ptr;

	if (argc != 2)
		ft_print_error("Please use the following"
			" commond: ./fdf path/to/map.fdf");
	ptr.mlxd.mlx_ptr = mlx_init();
	ptr.mlxd.win_ptr = mlx_new_window(ptr.mlxd.mlx_ptr,
			WIDTH, HEIGHT, "fdf_42");
	ptr.mlxd.img = mlx_new_image(ptr.mlxd.mlx_ptr, WIDTH, HEIGHT);
	ptr.mlxd.addr = mlx_get_data_addr(ptr.mlxd.img, &ptr.mlxd.bits_per_pixel,
			&ptr.mlxd.line_length, &ptr.mlxd.endian);
	ptr.height = ft_calc_height(argv[1]);
	ptr.width = ft_calc_width(argv[1]);
	ft_read_maps(argv[1], &ptr);
	ft_tronsformation(&ptr);
	ft_draw(&ptr);
	mlx_put_image_to_window(ptr.mlxd.mlx_ptr,
		ptr.mlxd.win_ptr, ptr.mlxd.img, 0, 0);
	mlx_hook(ptr.mlxd.win_ptr, 2, 0, ft_control_my_key, &ptr);
	mlx_hook(ptr.mlxd.win_ptr, 17, 2, ft_is_close, &ptr);
	mlx_loop(ptr.mlxd.mlx_ptr);
	return (0);
}
