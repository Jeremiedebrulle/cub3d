/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebrull <jdebrull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:01:15 by jdebrull          #+#    #+#             */
/*   Updated: 2025/08/12 17:33:18 by jdebrull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

/* int can_move_to(t_data *data, float new_x, float new_y)
{
    int left = (int)(new_x - 0.2f);
    int right = (int)(new_x + 0.2f);
    int top = (int)(new_y - 0.2f);
    int bottom = (int)(new_y + 0.2f);

    if (data->map.lines[top][left] == '1')
        return 0;
    if (data->map.lines[top][right] == '1')
        return 0;
    if (data->map.lines[bottom][left] == '1')
        return 0;
    if (data->map.lines[bottom][right] == '1')
        return 0;
    return 1;
} */


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
