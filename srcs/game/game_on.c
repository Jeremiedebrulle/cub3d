/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_on.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebrull <jdebrull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:52:27 by jdebrull          #+#    #+#             */
/*   Updated: 2025/08/26 13:46:12 by jdebrull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3d.h"

void	ft_mlx_put_pixel(t_minilib *minilib, int x, int y, int color)
{
	char	*dst;

	//printf("line length = %d, bpp = %d, endian = %d\n", minilib->line_length, minilib->bpp, minilib->endian);
	dst = minilib->addr + (y * minilib->line_length + x * (minilib->bpp / 8));
	*(unsigned int *)dst = color;
}


void	ft_mlx_start(t_data *data)
{
	data->minilib->win = mlx_new_window(data->minilib->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (!data->minilib->win)
	{
		mlx_destroy_display(data->minilib->mlx);
		//free all
		exit(1);
	}
	data->minilib->img = mlx_new_image(data->minilib->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!data->minilib->img)
	{
		mlx_destroy_display(data->minilib->mlx);
		mlx_destroy_window(data->minilib->win, data->minilib->win);
		//free all
		exit(2);
	}
	data->minilib->addr = mlx_get_data_addr(data->minilib->img, &data->minilib->bpp,
	&data->minilib->line_length, &data->minilib->endian);
}

int	destroy_window(void)
{
	ft_printf("Window closed with 'X' button.");
	//free all
	exit (1);
}

void	fill_square(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < SIZE)
	{
		i = 0;
		while (i < SIZE)
		{
			if (i == 0 || i == SIZE -1 || j == 0 || j == SIZE - 1) // les lignes blanches sur la minimap
				ft_mlx_put_pixel(data->minilib, x + i, y + j, 0xFFFFFFFF);
			else
				ft_mlx_put_pixel(data->minilib, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

void	draw_minimap(t_data *data)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (data->map.lines[y])
	{
		x = 0;
		while (data->map.lines[y][x])
		{
			if (data->map.lines[y][x] == '0' || data->map.lines[y][x] == 'N'
				|| data->map.lines[y][x] == 'E' || data->map.lines[y][x] == 'S'
				|| data->map.lines[y][x] == 'W')
				color = 0x0000FF00; // green
			else if (data->map.lines[y][x] == '1')
				color = 0x000000FF; // blue
			else
				color = 0x00000000; // black
			fill_square(data, x * SIZE, y * SIZE, color);
			x++;
		}
		y++;
	}
}

void	draw_player(t_data *data)
{
	int	i;
	int	j;
	int	px;
	int	py;
	int	size;

	size = SIZE / 8;
	px = (int)(data->player.x * SIZE);
	py = (int)(data->player.y * SIZE);
	j = -size;
	while (j < size)
	{
		i = -size;
		while (i < size)
		{
			ft_mlx_put_pixel(data->minilib, px + i, py + j, 0x00FF0000);
			i++;
		}
		j++;
	}
}

void	draw_dir(t_data *data)
{
	int	px;
	int	py;
	int	dx;
	int	dy;
	int i;
	int	len;

	i = 0;
	dx = 0;
	dy = 0;
	len = SIZE / 2; // ca j'ai decider de faire la longeur du laser de dir 
	px = (int)(data->player.x * SIZE);
	py = (int)(data->player.y * SIZE);
	while (i < len)
	{
		dx = px + (int)(data->player.dir_x * i);
		dy = py + (int)(data->player.dir_y * i);
		ft_mlx_put_pixel(data->minilib, dx, dy, 0x00FF0000);
		i++;
	}
}

/* void	fill_win(t_data *data)
{
	cast_rays(data, &data->player);
	//draw_minimap(data);
	//draw_player(data);
	//draw_dir(data);
	mlx_put_image_to_window(data->minilib->mlx, data->minilib->win, data->minilib->img, 0, 0);
} */

void	mlx_redraw(t_data *data)
{
	if (data->minilib->img)
		mlx_destroy_image(data->minilib->mlx, data->minilib->img);
	data->minilib->img = mlx_new_image(data->minilib->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	data->minilib->addr = mlx_get_data_addr(data->minilib->img, &data->minilib->bpp, &data->minilib->line_length, &data->minilib->endian);
	mlx_put_image_to_window(data->minilib->mlx, data->minilib->win, data->minilib->img, 0, 0);
}

int key_press(int keycode, t_data *data)
{
	if (!keycode)
		return (0);
	else if (keycode == KEY_RIGHT)
		data->keys->r = 1;
	else if (keycode == KEY_LEFT)
		data->keys->l = 1;
	else if (keycode == KEY_W)
		data->keys->w = 1;
	else if (keycode == KEY_A)
		data->keys->a = 1;
	else if (keycode == KEY_S)
		data->keys->s = 1;
	else if (keycode == KEY_D)
		data->keys->d = 1;
	else if (keycode == KEY_ESC)
		exit(0);
    return (0);
}

int key_release(int keycode, t_data *data)
{
	if (!keycode)
		return (0);
	else  if (keycode == KEY_RIGHT)
		data->keys->r = 0;
	else if (keycode == KEY_LEFT)
		data->keys->l = 0;
	else if (keycode == KEY_W)
		data->keys->w = 0;
	else if (keycode == KEY_A)
		data->keys->a = 0;
	else if (keycode == KEY_S)
		data->keys->s = 0;
	else if (keycode == KEY_D)
		data->keys->d = 0;
	return (0);
}

int update(t_data *data)
{
	if (data->keys->r)
		look_right(data, ROT_ANGLE);
	if (data->keys->l)
		look_left(data, ROT_ANGLE);
	if (data->keys->w)
		going_forward(data, PLAYER_RADIUS);
	if (data->keys->a)
		going_left(data, PLAYER_RADIUS);
	if (data->keys->s)
		going_backward(data, PLAYER_RADIUS);
	if (data->keys->d)
		going_right(data, PLAYER_RADIUS);
	mlx_redraw(data);
	cast_rays(data, &data->player);
	//draw_minimap(data);
	//draw_player(data);
	mlx_put_image_to_window(data->minilib->mlx, data->minilib->win, data->minilib->img, 0, 0);
	//fill_win(data);  // redraw minimap + player
	usleep(10000);
	return (0);
}

void	mlx_controls(t_data *data)
{
	mlx_hook(data->minilib->win, 2, 1L<<0, key_press, data);
	mlx_hook(data->minilib->win, 3, 1L<<1, key_release, data);
	mlx_loop_hook(data->minilib->mlx, update, data); 
	mlx_hook(data->minilib->win, 17, 0, destroy_window, NULL);
	mlx_loop(data->minilib->mlx);
}

int	game_on(t_data *data)
{
	int	i;

	i = 0;
	if (!ft_init_minilib(data) || !ft_init_keys(data))
		return (0);
	ft_init_rays(data);
	ft_init_xpms(data);
	ft_load_textures(data);
	while (i < 4)
	{
		if (!data->xpms[i].img)
			return (0);
		i++;
	}
	ft_mlx_start(data);
	mlx_controls(data);
	//pixel_map(data);
	//draw_pixel_map(data);

	return (0);
}
