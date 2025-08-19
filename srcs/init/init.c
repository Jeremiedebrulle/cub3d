/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebrull <jdebrull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 14:46:23 by lecartuy          #+#    #+#             */
/*   Updated: 2025/08/19 19:10:22 by jdebrull         ###   ########.fr       */
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

void    ft_init_xpms(t_data *data)
{
    int i;

    i = 0;
    while (i < 4)
    {
        data->xpms[i].img = NULL;
        data->xpms[i].addr = NULL;
        data->xpms[i].bpp = 0;
        data->xpms[i].line_length = 0;
        data->xpms[i].endian = 0;
        data->xpms[i].width = 0;
        data->xpms[i].height = 0;
        i++;
    }
}

void    ft_load_textures(t_data *data)
{
    data->xpms[0].img = mlx_xpm_file_to_image(data->minilib->mlx, "textures/north.xpm", &data->xpms[0].width, &data->xpms[0].height);
    if (!data->xpms[0].img)
        exit(printf("Error\nFailed to load north.xpm\n"));
    data->xpms[0].addr = mlx_get_data_addr(data->xpms[0].img, &data->xpms[0].bpp, &data->xpms[0].line_length, &data->xpms[0].endian);
    data->xpms[1].img = mlx_xpm_file_to_image(data->minilib->mlx, "textures/east.xpm", &data->xpms[1].width, &data->xpms[1].height);
    if (!data->xpms[1].img)
        exit(printf("Error\nFailed to load east.xpm\n"));
    data->xpms[1].addr = mlx_get_data_addr(data->xpms[1].img, &data->xpms[1].bpp, &data->xpms[1].line_length, &data->xpms[1].endian);
    data->xpms[2].img = mlx_xpm_file_to_image(data->minilib->mlx, "textures/south.xpm", &data->xpms[2].width, &data->xpms[2].height);
    if (!data->xpms[2].img)
        exit(printf("Error\nFailed to load south.xpm\n"));
    data->xpms[2].addr = mlx_get_data_addr(data->xpms[2].img, &data->xpms[2].bpp, &data->xpms[2].line_length, &data->xpms[2].endian);
    data->xpms[3].img = mlx_xpm_file_to_image(data->minilib->mlx, "textures/west.xpm", &data->xpms[3].width, &data->xpms[3].height);
    if (!data->xpms[3].img)
        exit(printf("Error\nFailed to load west.xpm\n"));
    data->xpms[3].addr = mlx_get_data_addr(data->xpms[3].img, &data->xpms[3].bpp, &data->xpms[3].line_length, &data->xpms[3].endian);
}

void ft_init_rays(t_data *data)
{
    data->rays.cameraX = 0;
    data->rays.deltadistX = 0;
    data->rays.deltadistY = 0;
    data->rays.map_x = 0;
    data->rays.map_y = 0;
    data->rays.raydirX = 0;
    data->rays.raydirY = 0;
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