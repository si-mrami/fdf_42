/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:13:32 by mrami             #+#    #+#             */
/*   Updated: 2023/05/25 04:24:58 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* clacule height of maps */

int	ft_calc_height(char *maps)
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

/* clacule width of maps */

int	ft_calc_width(char *maps)
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

/* convert str to int */

int	ft_atoi(char *str)
{
	long	i;
	long	num;
	int		sign;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = 10 * num + str[i] - '0';
		i++;
	}
	return (sign * num);
}

/* read maps color */

void	ft_read_maps_color(int *color, char *line, int *map_line)
{
	char	**spt;
	int		i;
	int		j;

	spt = ft_split(line, ' ');
	i = 0;
	while (spt[i])
	{
		map_line[i] = ft_atoi(spt[i]);
		j = 0;
		while (spt[i][j] && spt[i][j] != ',')
			j++;
		if (spt[i][j] == ',')
			color[i] = ft_hex_to_dec(&spt[i][j]);
		else
			color[i] = 0xffffff;
		i++;
	}
	j = 0;
	while (spt[j])
		free(spt[j++]);
	free(spt);
}

/* read maps */

void	ft_read_maps(char *mps, t_mtr *ptr)
{
	int		fd;
	int		i;
	char	*line;
	char	**spt;
	int		len;

	fd = open(mps, O_RDONLY);
	ptr->height = ft_calc_height(mps);
	ptr->mtx = (int **) malloc(sizeof(int *) * (ptr->height + 1));
	ptr->mps_color = (int **) malloc((ptr->height + 1) * sizeof(int *));
	ptr->len2 = check_line(mps);
	i = -1;
	while (++i < ptr->height)
	{
		line = get_next_line(fd);
		spt = ft_split(line, ' ');
		len = ft_length_of_spliter(spt);
		if (i > 2 && len != ptr->len2)
			ft_print_error("Same thing wornng in your maps,"
				" please check your maps and try again!");
		ptr->mtx[i] = (int *) malloc((len + 1) * sizeof(int));
		ptr->mps_color[i] = (int *) malloc(sizeof(int) * (len + 1));
		ft_read_maps_color(ptr->mps_color[i], line, ptr->mtx[i]);
		free(line);
	}
}
