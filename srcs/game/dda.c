/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebrull <jdebrull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:52:52 by jdebrull          #+#    #+#             */
/*   Updated: 2025/08/19 19:17:54 by jdebrull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

double	ft_dabs(double num)
{
	if (num < 0)
		return (-num);
	return (num);
}

float	ft_fabs(float num)
{
	if (num < 0.0f)
		return (-num);
	else
		return (num);
}

double ft_floor(double x)
{
	long long	i;

	i = (long long)x;
	if (x < 0 && x != (double)i)
		return (i - 1);
	return (i);
}

void	delta_dist(t_rays *rays)
{
	if (rays->raydirX == 0)
		rays->deltadistX = 1e30;
	else
		rays->deltadistX = ft_dabs(1.0 / rays->raydirX);
	if (rays->raydirY == 0)
		rays->deltadistY = 1e30;
	else
		rays->deltadistY = ft_dabs(1.0 / rays->raydirY);
}

void	step_dist(t_player *player, t_rays *rays)
{
	if (rays->raydirX < 0)
	{
		rays->step_x = -1;
		rays->sidedistX = (player->x - rays->map_x) * rays->deltadistX;
	}
	else
	{
		rays->step_x = 1;
		rays->sidedistX = (rays->map_x + 1.0 - player->x) * rays->deltadistX;
	}
	if (rays->raydirY < 0)
	{
		rays->step_y = -1;
		rays->sidedistY = (player->y - rays->map_y) * rays->deltadistY;
	}
	else
	{
		rays->step_y = 1;
		rays->sidedistY = (rays->map_y + 1.0 - player->y) * rays->deltadistY;
	}
}

/* void	draw_pov(t_data * data, t_rays *rays)
{
	int		px;
	int		py;
	int		dx;
	int		dy;
	double	dist;
	double	step;
	
	dist = 0;
	step = 0.1;
	py = (int)(data->player.y * SIZE);
	px = (int)(data->player.x * SIZE);
	while (dist < rays->perp_wall_dist)
	{
		dx = px + (int)(rays->raydirX * dist * SIZE);
		dy = py + (int)(rays->raydirY * dist * SIZE);
		ft_mlx_put_pixel(data->minilib, dx, dy, 0x00FF0000); // red rays
		dist += step;
	}
} */

void	set_pixel(t_minilib *mlx, int x, int y, int color)
{
	int *pixel;

	pixel = (int *)(mlx->addr + y * mlx->line_length + x * 4);
	*pixel = color;
}

/* void	draw_vertical_line(t_data *data, int x, int	start, int end, t_xpms *xpm)
{
	int	*pixel;
	int	y;

	pixel = (int *)(data->minilib->addr + start * data->minilib->line_length + x * 4);
	y = start;
	while (y <= end)
	{
		*pixel = 0x000000FF;
		pixel = (int *)((char*)pixel + data->minilib->line_length);
		y++;
	}
	y = 0;
	while (y < start)
	{
		set_pixel(data->minilib, x, y, data->config.ceiling_color);
		y++;
	}
	y = end + 1;
	while (y < SCREEN_HEIGHT)
	{
		set_pixel(data->minilib, x, y, data->config.floor_color);
		y++;
	}
} */

void	draw_vertical_line_xpm(t_data *data, int x, int start, int end, t_xpms *xpm, int xpm_x)
{
	int		y;
	int		xpm_y;
	char	*pixel;
	int		color;
	double	step;
	double	xpm_pos;
	
	xpm_pos = 0.0;
	if ((end - start) != 0)	
		step = 1.0 * xpm->height / (end - start);
	else
		step = 0.0;
	y = start;
	while (y <= end)
	{
		xpm_y = (int)xpm_pos;
		if (xpm_y >= xpm->height)
			xpm_y = xpm->height - 1;
		pixel = xpm->addr + (xpm_y * xpm->line_length + xpm_x * (xpm->bpp / 8));
		color = *(int *)pixel;
		set_pixel(data->minilib, x, y, color);
		xpm_pos += step;
		y++;
	}
}

int	get_xpm(t_data *data, t_xpms *xpm, double wall_x, int side)
{
	int	xpm_x;

	xpm_x = (int)(wall_x * (double)xpm->width);
	if (side == 0 && data->rays.raydirX > 0)
		xpm_x = xpm->width - xpm_x -1;
	if (side == 1 && data->rays.raydirY < 0)
		xpm_x = xpm->width - xpm_x - 1;
	return (xpm_x);
}

int	xpm_prep(t_data *data, t_xpms *xpm, int side, double perp_wall_dist)
{
	double	wall_x;
	int		xpm_x;

	if (side == 0)
		wall_x = data->player.y + perp_wall_dist * data->rays.raydirY;
	else
		wall_x = data->player.x + perp_wall_dist * data->rays.raydirX;
	wall_x -= ft_floor(wall_x); // fct de math.h qui permet d'avoir le chiffre derriere la virgule donc ce qu'il nous reste a la fin c'est la co correct du mur
	xpm_x = get_xpm(data, xpm, wall_x, side);
	return (xpm_x);
}

void	draw_in_3d(t_data *data, int x, int side, double perp_wall_dist)
{
	t_xpms	*xpm;
	int		xpm_x;
	int		line_height;
	int		start_point;
	int		end_point;

	line_height = (int)(SCREEN_HEIGHT / perp_wall_dist);
	start_point = -line_height / 2 + SCREEN_HEIGHT / 2;
	end_point = line_height / 2 + SCREEN_HEIGHT / 2;
	if (start_point < 0)
		start_point = 0;
	if (end_point >= SCREEN_HEIGHT)
		end_point = SCREEN_HEIGHT - 1;
	if (side == 0 && data->rays.raydirX > 0)
		xpm = &data->xpms[1];
	else if (side == 0 && data->rays.raydirX < 0)
		xpm = &data->xpms[3];
	else if (side == 1 && data->rays.raydirY > 0)
		xpm = &data->xpms[2];
	else if (side == 1 && data->rays.raydirY < 0)
		xpm = &data->xpms[0];
	xpm_x = xpm_prep(data, xpm, side, perp_wall_dist);
	draw_vertical_line_xpm(data, x, start_point, end_point, xpm, xpm_x);
}

void	wall_dist(t_data *data, t_rays *rays, int side, int x)
{
	double perp_wall_dist;

	if (side == 0)
		perp_wall_dist = (rays->map_x - data->player.x + (1 - rays->step_x) / 2.0) / rays->raydirX;
	else
		perp_wall_dist = (rays->map_y - data->player.y + (1 - rays->step_y) / 2.0) / rays->raydirY;
	if (perp_wall_dist <= 0)
		perp_wall_dist = 0.0001;
	//draw_pov(data, rays);
	draw_in_3d(data, x, side, perp_wall_dist);
}

void	dda_loop(t_data *data, t_rays *rays, int x)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (rays->sidedistX < rays->sidedistY)
		{
			rays->sidedistX += rays->deltadistX;
			rays->map_x += rays->step_x;
			side = 0;
		}
		else
		{
			rays->sidedistY += rays->deltadistY;
			rays->map_y += rays->step_y;
			side = 1;
		}
		if (rays->map_x < 0 || rays->map_y < 0 || rays->map_x >= data->map.width || rays->map_y >= data->map.height)
		{
			rays->perp_wall_dist = 1e30;
			break ;
		}
		if (data->map.lines[rays->map_y][rays->map_x] == '1')
			hit = 1;
	}
	wall_dist(data, rays, side, x);
}

void	cast_rays(t_data *data, t_player *player)
{
	t_rays	rays;
	int		x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		rays.cameraX = 2 * x / (double)SCREEN_WIDTH - 1; // range de la camera de {-1, 1}
		rays.raydirX = player->dir_x + player->plane_x * rays.cameraX; // la dir des laser;
		rays.raydirY = player->dir_y + player->plane_y * rays.cameraX;
		rays.map_x = (int)player->x;
		rays.map_y = (int)player->y;
		delta_dist(&rays);
		step_dist(player, &rays);
		dda_loop(data, &rays, x);
		x++;
	}
}