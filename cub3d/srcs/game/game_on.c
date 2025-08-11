/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_on.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebrull <jdebrull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:52:27 by jdebrull          #+#    #+#             */
/*   Updated: 2025/08/11 19:20:19 by jdebrull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	ft_mlx_put_pixel(t_minilib *minilib, int x, int y, int color)
{
	char	*dst;

	//printf("line length = %d, bpp = %d, endian = %d\n", minilib->line_length, minilib->bpp, minilib->endian);
	dst = minilib->addr + (y * minilib->line_length + x * (minilib->bpp / 8));
	*(unsigned int *)dst = color;
}


void	ft_mlx_start(t_data *data)
{
	data->minilib->mlx = mlx_init();
	if (!data->minilib->mlx)
	{
		//free_all
		exit(0);
	}
	data->minilib->win = mlx_new_window(data->minilib->mlx, data->map.width * SIZE, data->map.height * SIZE, "cub3D");
	if (!data->minilib->win)
	{
		mlx_destroy_display(data->minilib->mlx);
		//free all
		exit(1);
	}
	data->minilib->img = mlx_new_image(data->minilib->mlx, data->map.width * SIZE, data->map.height * SIZE);
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
			if (i == 0 || i == SIZE -1 || j == 0 || j == SIZE - 1)
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
			if (data->map.lines[y][x] != '1')
				color = 0x0000FF00;
			else
				color = 0x000000FF;
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
	int	center;

	j = 0;
	center = (SIZE / 8) * 3;
	px = (int)(data->player.x * SIZE) + center;
	py = (int)(data->player.y * SIZE) + center;
	while (j < 16)
	{
		i = 0;
		while (i < 16)
		{
			ft_mlx_put_pixel(data->minilib, px + i, py + j, 0x00FF0000);
			i++;
		}
		j++;
	}
}

void	fill_win(t_data *data)
{
	draw_minimap(data);
	draw_player(data);
	mlx_put_image_to_window(data->minilib->mlx, data->minilib->win, data->minilib->img, 0, 0);
}

void	mlx_redraw(t_data *data)
{
	if (data->minilib->img)
		mlx_destroy_image(data->minilib->mlx, data->minilib->img);
	data->minilib->img = mlx_new_image(data->minilib->mlx, data->map.width * SIZE, data->map.height * SIZE);
	data->minilib->addr = mlx_get_data_addr(data->minilib->img, &data->minilib->bpp, &data->minilib->line_length, &data->minilib->endian);
	fill_win(data);
	mlx_put_image_to_window(data->minilib->mlx, data->minilib->win, data->minilib->img, 0, 0);
}

int key_press(int keycode, t_data *data)
{
    if (keycode == KEY_W)
        data->keys.w = 1;
    else if (keycode == KEY_A)
        data->keys.a = 1;
    else if (keycode == KEY_S)
        data->keys.s = 1;
    else if (keycode == KEY_D)
        data->keys.d = 1;
    else if (keycode == KEY_ESC)
        exit(0);
    return (0);
}

int key_release(int keycode, t_data *data)
{
    if (keycode == KEY_W)
        data->keys.w = 0;
    else if (keycode == KEY_A)
        data->keys.a = 0;
    else if (keycode == KEY_S)
        data->keys.s = 0;
    else if (keycode == KEY_D)
        data->keys.d = 0;
    return (0);
}

int update(t_data *data)
{
	if (data->keys.w)
		going_forward(data);
	else if (data->keys.a)
		going_left(data);
	else if (data->keys.s)
		going_backward(data);
	else if (data->keys.d)
		going_right(data);
	fill_win(data);  // redraw minimap + player
	usleep(10000);
    return (0);
}


/* int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		ft_printf("Window was closed with <Esc>.\n");
		//free all
		exit (0);
	}
	else if (keycode == KEY_W)
		going_forward(data);
	else if (keycode == KEY_A)
		going_left(data);
	else if (keycode == KEY_S)
		going_backward(data);
	else if (keycode == KEY_D)
		going_right(data);
	else if (keycode == KEY_RIGHT)
		look_right(data);
	else if (keycode == KEY_LEFT)
		look_left(data);
	//printf("pos x = %d, y = %d\n", data->player->x, data->player->y);
	mlx_redraw(data);
	return (1);
} */

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
	if (!ft_init_minilib(data))
		return (0);
	ft_mlx_start(data);
	mlx_controls(data);
	//pixel_map(data);
	//draw_pixel_map(data);

	return (0);
}
