/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:13:32 by mrami             #+#    #+#             */
/*   Updated: 2023/05/28 15:19:32 by mrami            ###   ########.fr       */
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
		free(line);
		line = get_next_line(fd);
		maps_height++;
	}
	return (maps_height);
}

/* clacule width of maps */

int	ft_calc_width(char *maps)
{
	int		fd;
	int		maps_width;
	char	*line;
	char	**spliter;
	int		i;

	fd = open(maps, O_RDONLY);
	line = get_next_line(fd);
	spliter = ft_split(line, ' ');
	if (!spliter || !spliter[0])
		ft_print_error("Error: check your maps!");
	maps_width = 0;
	while (spliter[maps_width])
		maps_width++;
	free(line);
	i = 0;
	while (spliter[i])
		free(spliter[i++]);
	free(spliter);
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

	fd = open(mps, O_RDONLY);
	if (fd < 0)
		return ;
	ptr->height = ft_calc_height(mps);
	ptr->mtx = (int **) malloc(sizeof(int *) * (ptr->height + 1));
	ptr->mps_color = (int **) malloc((ptr->height + 1) * sizeof(int *));
	if (!ptr->mtx || !ptr->mps_color)
		return ;
	i = -1;
	while (++i < ptr->height)
	{
		ptr->line = get_next_line(fd);
		ptr->spt = ft_split(ptr->line, ' ');
		ptr->len = ft_length_of_spliter(ptr->spt);
		ptr->mtx[i] = (int *) malloc((ptr->len + 1) * sizeof(int));
		ptr->mps_color[i] = (int *) malloc(sizeof(int) * (ptr->len + 1));
		if (!ptr->mtx[i] || !ptr->mps_color[i])
			return ;
		ft_read_maps_color(ptr->mps_color[i], ptr->line, ptr->mtx[i]);
		free(ptr->line);
		ft_free(ptr->spt, ptr->len);
	}
}
