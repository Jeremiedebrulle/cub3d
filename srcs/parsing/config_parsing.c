/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecartuy <lecartuy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:39:14 by lecartuy          #+#    #+#             */
/*   Updated: 2025/08/08 15:56:28 by lecartuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

static char	**ft_split_whitespace(const char *str)
{
	int		i;
	int		index;
	int		words;
	char	**res;

	words = word_count(str);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	i = 0;
	index = 0;
	while (index < words)
	{
		res[index] = next_word(str, &i);
		if (!res[index])
			return (free_tab(res), NULL);
		i += ft_strlen(res[index]);
		index++;
	}
	res[index] = NULL;
	return (res);
}

static int	parse_config_line(t_data *data, char *line)
{
	char	**tokens;

	tokens = ft_split_whitespace(line);
	if (!tokens[0])
	{
		free_tab(tokens);
		return (0);
	}
	if (ft_strcmp(tokens[0], "NO") == 0)
		set_texture_path(data, &data->config.no_texture, tokens[1]);
	else if (ft_strcmp(tokens[0], "SO") == 0)
		set_texture_path(data, &data->config.so_texture, tokens[1]);
	else if (ft_strcmp(tokens[0], "WE") == 0)
		set_texture_path(data, &data->config.we_texture, tokens[1]);
	else if (ft_strcmp(tokens[0], "EA") == 0)
		set_texture_path(data, &data->config.ea_texture, tokens[1]);
	else if (ft_strcmp(tokens[0], "F") == 0)
		set_color_value(data, &data->config.floor_color, tokens[1]);
	else if (ft_strcmp(tokens[0], "C") == 0)
		set_color_value(data, &data->config.ceiling_color, tokens[1]);
	else
	{
		free_tab(tokens);
		return (0);
	}
	free_tab(tokens);
	return (1);
}
void	parse_config(t_data *data, char **lines)
{
	int	i;
	int	config_count;

	i = 0;
	config_count = 0;
	while (lines[i])
	{
		if (is_empty_line(lines[i]))
		{
			i++;
			continue ;
		}
		if (config_count < 6)
		{
			if (parse_config_line(data, lines[i]))
			{
				config_count++;
			}
			else if (is_map_line(lines[i]))
			{
				if (config_count == 0)
					exit_error(data, MAPBEFORECONFIG);
				else
					exit_error(data, CONFIGMISS);
			}
			else
				exit_error(data, INVCONFIG);
		}
		else
			break ;
		i++;
	}
	data->map.start_index = i;
	if (config_count < 6)
		exit_error(data, CONFIGMISS);
}

int	parse_rgb(t_data *data, const char *str)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;
	int		color;

	rgb = ft_split(str, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		exit_error(data, RGBFORMAT);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		exit_error(data, RGBVALUE);
	color = (r << 16) | (g << 8) | b;
	free_tab(rgb);
	return (color);
}
