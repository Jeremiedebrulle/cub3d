/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebrull <jdebrull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:01:15 by jdebrull          #+#    #+#             */
/*   Updated: 2025/08/26 13:59:03 by jdebrull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

void going_forward(t_data *data, float rad)
{
	float	new_x;
	float	new_y;

	new_x = data->player.x + data->player.dir_x * SPEED;
	new_y = data->player.y + data->player.dir_y * SPEED;
	if (data->map.lines[(int)(data->player.y + rad)][(int)(new_x + rad)] != '1' &&
	data->map.lines[(int)(data->player.y + rad)][(int)(new_x - rad)] != '1' &&
	data->map.lines[(int)(data->player.y - rad)][(int)(new_x - rad)] != '1' &&
	data->map.lines[(int)(data->player.y - rad)][(int)(new_x + rad)] != '1')
		data->player.x = new_x;
	if (data->map.lines[(int)(new_y + rad)][(int)(data->player.x + rad)] != '1' &&
	data->map.lines[(int)(new_y + rad)][(int)(data->player.x - rad)] != '1' &&
	data->map.lines[(int)(new_y - rad)][(int)(data->player.x + rad)] != '1' &&
	data->map.lines[(int)(new_y - rad)][(int)(data->player.x - rad)] != '1')
		data->player.y = new_y;
}

void going_left(t_data *data, float rad)
{
	float	new_x;
	float	new_y;

	new_x = data->player.x - data->player.plane_x * SPEED;
	new_y = data->player.y - data->player.plane_y * SPEED;
	if (data->map.lines[(int)(data->player.y + rad)][(int)(new_x + rad)] != '1' &&
	data->map.lines[(int)(data->player.y + rad)][(int)(new_x - rad)] != '1' &&
	data->map.lines[(int)(data->player.y - rad)][(int)(new_x + rad)] != '1' &&
	data->map.lines[(int)(data->player.y - rad)][(int)(new_x - rad)] != '1')
		data->player.x = new_x;
	if (data->map.lines[(int)(new_y + rad)][(int)(data->player.x + rad)] != '1' &&
	data->map.lines[(int)(new_y + rad)][(int)(data->player.x - rad)] != '1' &&
	data->map.lines[(int)(new_y - rad)][(int)(data->player.x + rad)] != '1' &&
	data->map.lines[(int)(new_y - rad)][(int)(data->player.x - rad)] != '1')
		data->player.y = new_y;
}

void going_backward(t_data *data, float rad)
{
	float	new_x;
	float	new_y;

	new_x = data->player.x - data->player.dir_x * SPEED;
	new_y = data->player.y - data->player.dir_y * SPEED;
	if (data->map.lines[(int)(data->player.y + rad)][(int)(new_x + rad)] != '1' &&
	data->map.lines[(int)(data->player.y + rad)][(int)(new_x - rad)] != '1' &&
	data->map.lines[(int)(data->player.y - rad)][(int)(new_x - rad)] != '1' &&
	data->map.lines[(int)(data->player.y - rad)][(int)(new_x + rad)] != '1')
		data->player.x = new_x;
	if (data->map.lines[(int)(new_y + rad)][(int)(data->player.x + rad)] != '1' &&
	data->map.lines[(int)(new_y + rad)][(int)(data->player.x - rad)] != '1' &&
	data->map.lines[(int)(new_y - rad)][(int)(data->player.x + rad)] != '1' &&
	data->map.lines[(int)(new_y - rad)][(int)(data->player.x - rad)] != '1')
		data->player.y = new_y;
}

void going_right(t_data *data, float rad)
{
	float	new_x;
	float	new_y;

	new_x = data->player.x + data->player.plane_x * SPEED;
	new_y = data->player.y + data->player.plane_y * SPEED;
	if (data->map.lines[(int)(data->player.y + rad)][(int)(new_x + rad)] != '1' &&
	data->map.lines[(int)(data->player.y + rad)][(int)(new_x - rad)] != '1' &&
	data->map.lines[(int)(data->player.y - rad)][(int)(new_x + rad)] != '1' &&
	data->map.lines[(int)(data->player.y - rad)][(int)(new_x - rad)] != '1')
		data->player.x = new_x;
	if (data->map.lines[(int)(new_y + rad)][(int)(data->player.x + rad)] != '1' &&
	data->map.lines[(int)(new_y + rad)][(int)(data->player.x - rad)] != '1' &&
	data->map.lines[(int)(new_y - rad)][(int)(data->player.x + rad)] != '1' &&
	data->map.lines[(int)(new_y - rad)][(int)(data->player.x - rad)] != '1')
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
