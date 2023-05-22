/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:32:35 by mrami             #+#    #+#             */
/*   Updated: 2023/05/20 01:24:40 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

/* get height of maps */

int	ft_caluc_maps_height(char *maps)
{
	int		maps_height;
	char	*line;
	int		fd;

	fd = open(maps, O_RDONLY);
	maps_height = 0;
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		maps_height++;
	}
	free(line);
	return (maps_height);
}

/* get width of maps */

int	ft_calcu_maps_width(char *maps)
{
	int		fd;
	int		maps_width;
	char	*line;
	char	**spliter;

	fd = open(maps, O_RDONLY);
	line = get_next_line(fd);
	spliter = ft_split(line, ' ');
	maps_width = 0;
	while (spliter[maps_width])
		maps_width++;
	free(line);
	return (maps_width);
}

/* read maps */

// void	ft_read_maps(char *maps, t_mtr *ptr)
// {
// 	int		fd;
// 	char	*line;
// 	int		i;

// 	fd = open(maps, O_RDONLY);
// 	if (fd < 0)
// 		return ;
// 	ptr->height = ft_caluc_maps_height(maps);
// 	ptr->mtx = malloc((ptr->height + 1) * sizeof(char *));
// 	if (!ptr->mtx)
// 		return ;
// 	line = get_next_line(fd);
// 	i = 0;
// 	while (line)
// 	{
// 		ptr->mtx[i] = line;
// 		if (!ptr->mtx[i])
// 			break ;
// 		line = get_next_line(fd);
// 		i++;
// 	}
// 	ptr->mtx[i] = NULL;
// }

int	main(int argc, char *argv[])
{
	t_mtr	ptr;
	int		color;
	int		i;
	int		j;
	int		factor;

	(void)argc;
	ptr.mlx_ptr = mlx_init();
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr , WIDTH, HEIGHT, "fdf_42");
	ptr.height = ft_caluc_maps_height(argv[1]);
	ptr.width = ft_calcu_maps_width(argv[1]);
	color = 0xFFFFFF;
	j = 0;
	factor = 30;
	while (j < ptr.height)
	{
		i = 0;
		while (i < ptr.width)
		{
			if (i < ptr.width - 1)
				ft_draw_line(ptr.mlx_ptr , ptr.win_ptr, (i * factor), (j * factor) , (i + 1) * factor, (j * factor), color);
			if (j < ptr.height - 1)
				ft_draw_line(ptr.mlx_ptr , ptr.win_ptr, (i * factor), (j * factor), i * factor, (j + 1) * factor, color);
			i++;
		}
		j++;
	}
	mlx_loop(ptr.mlx_ptr );
	return 0;
}
