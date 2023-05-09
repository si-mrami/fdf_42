/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:32:35 by mrami             #+#    #+#             */
/*   Updated: 2023/05/09 18:20:45 by mrami            ###   ########.fr       */
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
	spliter = ft_split(maps, ' ');
	maps_width = 0;
	while (spliter[maps_width])
		maps_width++;
	free(line);
	return (maps_width);
}

int	main(int argc, char *argv[])
{
	int	height;
	int	width;

	(void)argc;
	height = ft_caluc_maps_height(argv[1]);
	width = ft_calcu_maps_width(argv[1]);
	printf("%d\n", height);
	printf("%d", width);
	return (0);
}
