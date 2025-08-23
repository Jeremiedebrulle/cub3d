/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jdebrull <jdebrull@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:01:15 by jdebrull          #+#    #+#             */
/*   Updated: 2025/08/23 14:53:41 by Jdebrull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

void	going_forward(t_data *data, float speed)
{
	int		map_x;
	int		map_y;
	float	new_x;
	float	new_y;

	new_x = data->player.x + data->player.dir_x * speed;
	new_y = data->player.y + data->player.dir_y * speed;
	map_x = (int)new_x;
	map_y = (int)data->player.y;
	if (data->map.lines[map_y][map_x] != '1')
		data->player.x = new_x;
	map_x = (int)data->player.x;
	map_y = (int)new_y;
	if (data->map.lines[map_y][map_x] != '1')
		data->player.y = new_y;
}

void	going_left(t_data *data, float speed)
{
	int		map_x;
	int		map_y;
	float	new_x;
	float	new_y;

	new_x = data->player.x - data->player.plane_x * speed;
	new_y = data->player.y - data->player.plane_y * speed;
	map_x = (int)new_x;
	map_y = (int)data->player.y;
	if (data->map.lines[map_y][map_x] != '1')
		data->player.x = new_x;
	map_x = (int)data->player.x;
	map_y = (int)new_y;
	if (data->map.lines[map_y][map_x] != '1')
		data->player.y = new_y;
}

void	going_backward(t_data *data, float speed)
{
	int		map_x;
	int		map_y;
	float	new_x;
	float	new_y;

	new_x = data->player.x - data->player.dir_x * speed;
	new_y = data->player.y - data->player.dir_y * speed;
	map_x = (int)new_x;
	map_y = (int)data->player.y;
	if (data->map.lines[map_y][map_x] != '1')
		data->player.x = new_x;
	map_x = (int)data->player.x;
	map_y = (int)new_y;
	if (data->map.lines[map_y][map_x] != '1')
		data->player.y = new_y;
}

void	going_right(t_data *data, float speed)
{
	int		map_x;
	int		map_y;
	float	new_x;
	float	new_y;

	new_x = data->player.x + data->player.plane_x * speed;
	new_y = data->player.y + data->player.plane_y * speed;
	map_x = (int)new_x;
	map_y = (int)data->player.y;
	if (data->map.lines[map_y][map_x] != '1')
		data->player.x = new_x;
	map_x = (int)data->player.x;
	map_y = (int)new_y;
	if (data->map.lines[map_y][map_x] != '1')
		data->player.y = new_y;
}

void	look_right(t_data *data, float rot_angle)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.plane_x;
	data->player.dir_x = data->player.dir_x * cos(rot_angle) - data->player.dir_y * sin(rot_angle);
	data->player.dir_y = old_dir_x * sin(rot_angle) + data->player.dir_y * cos(rot_angle);
	data->player.plane_x = data->player.plane_x * cos(rot_angle) - data->player.plane_y * sin(rot_angle);
	data->player.plane_y = old_plane_x * sin(rot_angle) + data->player.plane_y * cos(rot_angle);
}

void	look_left(t_data *data, float rot_angle)
{
	look_right(data, -(rot_angle));
}
