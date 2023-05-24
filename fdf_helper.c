/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:49:18 by mrami             #+#    #+#             */
/*   Updated: 2023/05/24 20:10:19 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	dst = malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	j = 0;
	while ((s[start + i] != '\0') && (i < len))
	{
		dst[j] = s[start + i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (dst);
}

/* convert a hexadecimal string to decimal */

int	ft_hex_to_dec(char *hexa)
{
	int	len;
	int	i;
	int	base;
	int	decimal;

	base = 1;
	decimal = 0;
	len = ft_strlen(hexa);
	i = len - 1;
	while (i >= 0)
	{
		if (hexa[i] >= '0' && hexa[i] <= '9')
			decimal += (hexa[i] - 48) * base;
		if (hexa[i] >= 'a' && hexa[i] <= 'f')
			decimal += (hexa[i] - 87) * base;
		if (hexa[i] >= 'A' && hexa[i] <= 'F')
			decimal += (hexa[i] - 55) * base;
		base *= 16;
		i--;
	}
	return (decimal);
}

/* convert deg to red */

double	ft_convert(double deg)
{
	double	res;

	res = deg * M_PI / 180;
	return (res);
}

/* all the tronstformation */

void	ft_tronsformation(t_mtr *ptr)
{
	if (ptr->width < 25)
		ptr->zoming = 40;
	else if (ptr->width > 25)
		ptr->zoming = 2;
	ptr->zoming_z = 2;
	ptr->teta_x = ft_convert(45);
	ptr->teta_y = ft_convert(45);
	ptr->teta_z = ft_convert(45);
	ptr->factor = 2;
}

/* lenght of spliter */

int	ft_length_of_spliter(char **spl)
{
	int	i;

	i = 0;
	while (spl[i])
		i++;
	return (i);
}
