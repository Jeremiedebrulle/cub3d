/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebrull <jdebrull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:16:20 by lecartuy          #+#    #+#             */
/*   Updated: 2025/08/11 19:02:51 by jdebrull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// Keycodes

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307
# define SIZE 64

// Error messages

# define INVNAME "Error\nThe filename is incorrect.\n"
# define NOMAP "Error\nMap not found.\n"
# define INVCHAR "Error\nCharacters used are invalid.\n"
# define NOPLAYER "Error\nThere is no player/start.\n"
# define NOTCLOSED "Error\nThe map is not enclosed.\n"
# define READERR "Error\nCouldn't reading .cub file.\n"
# define INVCONFIG "Error\nInvalid congif line.\n"
# define INVPLAYER "Error\nThere are more than 1 player/start position.\n"
# define RGBVALUE "Error\nRGB values must be between 0 and 255\n"
# define CONFIGMISS "Error\nMissing config lines, need 6.\n"
# define RGBFORMAT "Error\nInvalid RGB format.\n"
# define MAPBEFORECONFIG "Error\nThe map is found before all the config.\n"
# define DUPTEXTURE "Error\nDuplicate texture path.\n"
# define MEMTEXTURE "Error\nMemory allocation failed for texture path.\n"
# define DUPCOLOR "Error\nDuplicate color definition.\n"
# define EMPTYFILE "Error\nEmpty .cub file.\n"

// Libraries

# include "../Libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Stuctures

typedef struct s_player
{
	float		x;
	float		y;
	char		dir;
}				t_player;

typedef struct s_config
{
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	int			floor_color;
	int			ceiling_color;
}				t_config;

typedef struct s_map
{
	char 		**lines; // normalized map
	int		*pixel_map;
	int			width;
	int			height;
	int			start_index;
}				t_map;

typedef struct s_keys
{
	int w;
	int	a;
	int	s;
	int	d;
	int	esc;
}				t_keys;

typedef struct s_minilib
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	
}				t_minilib;

typedef struct s_data
{
	t_config	config;
	t_map		map;
	t_player	player;
	t_minilib	*minilib;
	t_keys		keys;
	char		*file_content;
}				t_data;

//exec
int	ft_init_minilib(t_data *data);
int	game_on(t_data *data);

void	going_forward(t_data *data);
void	going_left(t_data *data);
void	going_backward(t_data *data);
void	going_right(t_data *data);


// Init

void			init_data(t_data *data);

// Args_Parsing

int				check_filename(const char *str);

// Config_parsing

void			parse_config(t_data *data, char **lines);
int				parse_rgb(t_data *data, const char *str);

// Config_helpers

int				word_count(const char *str);
char			*next_word(const char *str, int *start);
void			set_color_value(t_data *data, int *color, char *value);
void			set_texture_path(t_data *data, char **path, char *value);
int				is_map_line(const char *line);

// File parsing

void			parse_cub_file(const char *filename, t_data *data);

// Map_parsing

char			**normalize_map(char **raw_map);
void			validate_map(t_data *data);

// Map_elpers

int				check_surroundings(t_data *data, int x, int y);
int				check_character(char c);
int				get_max_width(char **map);
int				get_map_height(char **map);

// Utils

int				count_lines(char **lines);
int				max_line_length(char **lines);
int				is_empty_line(const char *line);
int				ft_strcmp(const char *s1, const char *s2);
int				validate_map_characters(char **map);

// Exit.c

void			free_tab(char **tab);
void			cleanup(t_data *data);
void			exit_error(t_data *data, const char *msg);

// Main.c

int				main(int argc, char **argv);

#endif