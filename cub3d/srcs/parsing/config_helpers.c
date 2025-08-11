/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecartuy <lecartuy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:10:43 by lecartuy          #+#    #+#             */
/*   Updated: 2025/08/08 14:54:01 by lecartuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

int	is_map_line(const char *line)
{
	while (*line)
	{
		if (*line == '1' || *line == '0' || *line == 'N' || *line == 'S'
			|| *line == 'E' || *line == 'W' || *line == ' ')
			return (1);
		line++;
	}
	return (0);
}

void	set_texture_path(t_data *data, char **path, char *value)
{
	if (*path)
		exit_error(data, DUPTEXTURE);
	*path = ft_strdup(value);
	if (!*path)
		exit_error(data, MEMTEXTURE);
}

void	set_color_value(t_data *data, int *color, char *value)
{
	if (*color != -1)
		exit_error(data, DUPCOLOR);
	*color = parse_rgb(data, value);
}

int	word_count(const char *str)
{
	int	count;
	int	in_word;

	in_word = 0;
	count = 0;
	while (*str)
	{
		if ((*str != ' ' && *str != '\t') && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*str == ' ' || *str == '\t')
			in_word = 0;
		str++;
	}
	return (count);
}

char	*next_word(const char *str, int *start)
{
	int i;
	int len;

	i = *start;
	len = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	*start = i;
	while (str[i + len] && str[i + len] != ' ' && str[i + len] != '\t')
		len++;
	return (ft_substr(str, *start, len));
}