/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebrull <jdebrull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:46:23 by lecartuy          #+#    #+#             */
/*   Updated: 2025/08/12 17:54:12 by jdebrull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

void init_data(t_data *data)
{
    data->map.lines = NULL;
    data->map.pixel_map = NULL;
    data->config.no_texture = NULL;
    data->config.so_texture = NULL;
    data->config.we_texture = NULL;
    data->config.ea_texture = NULL;
    data->config.floor_color = -1;
    data->config.ceiling_color = -1;
    data->map.height = 0;
    data->map.width = 0;
    data->player.dir = 0;
    data->player.dir_x = 0.0f;
    data->player.dir_y = 0.0f;
    data->player.plane_x = 0.0f;
    data->player.plane_y = 0.0f;
    data->player.x = 0.0f;
    data->player.y = 0.0f;
}

int ft_init_minilib(t_data *data)
{
    data->minilib = malloc(sizeof(t_minilib));
    if (!data->minilib)
        return (printf("Error\nMemory allocation failed.\n"), 0);
    data->minilib->bpp = 0;
    data->minilib->endian = 0;
    data->minilib->line_length = 0;
    data->minilib->addr = NULL;
    data->minilib->img = NULL;
    data->minilib->mlx = NULL;
    data->minilib->win = NULL;
    return (1);
}

int ft_init_keys(t_data *data)
{
    data->keys = malloc(sizeof(t_keys));
    if (!data->keys)
        return (printf("Error\nMemory allocation failed.\n"), 0);
    data->keys->w = 0;
    data->keys->a = 0;
    data->keys->s = 0;
    data->keys->d = 0;
    data->keys->l = 0;
    data->keys->r = 0;
    data->keys->esc = 0;
    return (1);
}