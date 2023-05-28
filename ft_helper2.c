/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:14:30 by mrami             #+#    #+#             */
/*   Updated: 2023/05/28 14:23:29 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* rest maps to default */

void	ft_rest(int key, t_mtr *ptr)
{
	if (key == 1)
		ptr->teta_y += ft_convert(5);
	if (key == 0)
		ptr->teta_y -= ft_convert(5);
	if (key == 12)
		ptr->teta_z += ft_convert(5);
	if (key == 13)
		ptr->teta_z -= ft_convert(5);
	if (key == 34)
	{
		if (ptr->width < 25)
			ptr->zoming = 30;
		else if (ptr->width > 25)
			ptr->zoming = 1;
		ptr->zoming_z = 1;
		ptr->teta_x = ft_convert(45);
		ptr->teta_y = ft_convert(45);
		ptr->teta_z = ft_convert(-30);
		ptr->factor = 2;
		ptr->sc_x = WIDTH / 2;
		ptr->sc_y = HEIGHT / 2;
	}
}

void	ft_rest_my_imge(t_mtr *ptr)
{
	mlx_destroy_image(ptr->mlxd.mlx_ptr, ptr->mlxd.img);
	ptr->mlxd.img = mlx_new_image(ptr->mlxd.mlx_ptr, WIDTH, HEIGHT);
	ptr->mlxd.addr = mlx_get_data_addr(ptr->mlxd.img, &ptr->mlxd.bits_per_pixel,
			&ptr->mlxd.line_length, &ptr->mlxd.endian);
	ft_draw(ptr);
	mlx_put_image_to_window(ptr->mlxd.mlx_ptr,
		ptr->mlxd.win_ptr, ptr->mlxd.img, 0, 0);
}

/* printf error */

void	ft_print_error(const char *err)
{
	write(2, err, ft_strlen(err));
	exit (1);
}
