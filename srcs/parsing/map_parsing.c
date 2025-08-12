/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebrull <jdebrull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:56:36 by lecartuy          #+#    #+#             */
/*   Updated: 2025/08/12 17:36:37 by jdebrull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

static int	is_map_enclosed(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (check_character(data->map.lines[y][x]))
			{
				if (!check_surroundings(data, x, y))
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

static char	*pad_line(const char *src, int width)
{
	char	*line;
	int		i;

	i = 0;
	line = malloc(sizeof(char) * (width + 1));
	if (!line)
		return (NULL);
	while (src[i])
	{
		line[i] = src[i];
		i++;
	}
	while (i < width)
		line[i++] = ' ';
	line[i] = '\0';
	return (line);
}

char	**normalize_map(char **raw_map)
{
	int		height;
	int		width;
	char	**new_map;
	int		i;

	height = get_map_height(raw_map);
	width = get_max_width(raw_map);
	new_map = malloc(sizeof(char *) * (height + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < height)
	{
		new_map[i] = pad_line(raw_map[i], width);
		if (!new_map[i])
			return (free_tab(new_map), NULL);
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

static int	validate_player(char **map, t_player *player)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSWE", map[i][j]))
			{
				player->x = (float)j + 0.5f;
				player->y = (float)i + 0.5f;
				player->dir = map[i][j];
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

// static void	print_map(char **map)
// {
// 	int	i;

// 	i = 0;
// 	while (map[i])
// 	{
// 		printf("%s\n", map[i]);
// 		i++;
// 	}
// }

/* void	assign_dir_plane_axis(t_player *player)
{
	if (player->dir == 'N')
	{
		player->dir_y = -1.0f;
		player->plane_x = 0.66f;
	}
	else if (player->dir == 'S')
	{
		player->dir_y = 1.0f;
		player->plane_x = -0.66f;
	}
	else if (player->dir == 'E')
	{
		player->dir_x = 1.0f;
		player->plane_y = 0.66f;
	}
	else if (player->dir == 'W')
	{
		player->dir_x = -1.0f;
		player->plane_y = -0.66f;
	}
} */

void	assign_dir_plane_axis(t_player *player)
{
	player->dir_x = 0.0f;
	player->dir_y = 0.0f;
	player->plane_x = 0.0f;
	player->plane_y = 0.0f;
	if (player->dir == 'N')
	{
		player->dir_y = -1.0f;
		player->plane_x = 0.66f;
	}
	else if (player->dir == 'S')
	{
		player->dir_y = 1.0f;
		player->plane_x = -0.66f;
	}
	else if (player->dir == 'E')
	{
		player->dir_x = 1.0f;
		player->plane_y = 0.66f;
	}
	else if (player->dir == 'W')
	{
		player->dir_x = -1.0f;
		player->plane_y = -0.66f;
	}
}

void	validate_map(t_data *data)
{
	int	player_count;

	// print_map(data->map.lines);
	if (!validate_map_characters(data->map.lines))
		exit_error(data, INVCHAR);
	if (!is_map_enclosed(data))
		exit_error(data, NOTCLOSED);
	player_count = validate_player(data->map.lines, &data->player);
	if (player_count == 0)
		exit_error(data, NOPLAYER);
	else if (player_count > 1)
		exit_error(data, INVPLAYER);
	assign_dir_plane_axis(&data->player); // j'ai besoin de ceci pour la direction du joueur
}
