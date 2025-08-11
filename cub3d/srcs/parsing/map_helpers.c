/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecartuy <lecartuy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:25:57 by lecartuy          #+#    #+#             */
/*   Updated: 2025/08/08 13:09:45 by lecartuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

int	check_character(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	check_border(char c)
{
	return (c == ' ' || c == '\0');
}

int	check_surroundings(t_data *data, int x, int y)
{
	if (y == 0 || y == data->map.height - 1 || x == 0 || x == data->map.width
		- 1)
		return (0);
	if (check_border(data->map.lines[y - 1][x])
		|| check_border(data->map.lines[y + 1][x])
		|| check_border(data->map.lines[y][x - 1])
		|| check_border(data->map.lines[y][x + 1]))
		return (0);
	return (1);
}

int	get_max_width(char **map)
{
	int	i;
	int	max;
	int	len;

	i = 0;
	max = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

int	get_map_height(char **map)
{
	int i = 0;
	while (map[i])
		i++;
	return (i);
}