/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebrull <jdebrull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:01:15 by jdebrull          #+#    #+#             */
/*   Updated: 2025/08/11 19:30:47 by jdebrull         ###   ########.fr       */
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


void	going_forward(t_data *data)
{
	float	new_y;
	int	x;
	int	y;

	new_y = data->player.y - 0.04f;
	x = (int)data->player.x;
	y = (int)new_y;
	if (data->map.lines[y][x] != '1')
		data->player.y = new_y;
}

void	going_left(t_data *data)
{
	float	new_x;
	int	x;
	int	y;

	new_x = data->player.x - 0.04f;
	x = (int)new_x;
	y = (int)data->player.y;
	if (data->map.lines[y][x] != '1')
		data->player.x = new_x;
}

void	going_backward(t_data *data)
{
	float	new_y;
	int		x;
	int		y;

	new_y = data->player.y + 0.04f;
	x = (int)data->player.x;
	y = (int)new_y;
	if (data->map.lines[y][x] != '1')
		data->player.y = new_y;
}

void	going_right(t_data *data)
{
	float	new_x;
	int		x;
	int		y;

	new_x = data->player.x + 0.04f;
	x = (int)new_x;
	y = (int)data->player.y;
	if (data->map.lines[y][x] != '1')
		data->player.x = new_x;
}


