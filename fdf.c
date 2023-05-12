/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:32:35 by mrami             #+#    #+#             */
/*   Updated: 2023/05/12 16:44:15 by mrami            ###   ########.fr       */
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

/* read maps */

void	ft_read_maps(char *maps, t_mtr *ptr)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	fd = open(maps, O_RDONLY);
	if (fd < 0)
		return ;
	ptr->height = ft_caluc_maps_height(maps);
	ptr->width = ft_calcu_maps_width(maps);
	ptr->mtx = malloc((sizeof(int *)) * (ptr->height + 1));
	if (!ptr->mtx)
		return ;
	i = 0;
	while (i < ptr->height)
	{
		line = get_next_line(fd);
		ptr->mtx[i] = malloc((sizeof(int)) * ptr->width);
		if (ptr->mtx[i])
			return ;
		j = 0;
		while (j < ptr->width && line[j])
		{
			ptr->mtx[i][j] = line[j];
			j++;
		}
		free(line);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_mtr	maps;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (argc < 2)
		write(1, "Error:\n", 8);
	ft_read_maps(argv[1], &maps);
	printf("%d\n", maps.height);
	printf("%d\n", maps.width);
	while (i < maps.height)
	{
		// printf("test01\n");
		while (j < maps.width)
		{
			// printf("test02\n");
			printf("%c", maps.mtx[i][j]);
			j++;
		}
		i++;
	}

	return (0);
}
