/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecartuy <lecartuy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:01:18 by lecartuy          #+#    #+#             */
/*   Updated: 2025/08/08 15:56:03 by lecartuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

static char	*read_file(const char *filename)
{
	int		fd;
	char	*buffer;
	char	*tmp;
	char	line[1025];
	int		bytes;

	buffer = NULL;
	buffer = ft_strdup("");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while ((bytes = read(fd, line, 1024)) > 0)
	{
		line[bytes] = '\0';
		tmp = buffer;
		buffer = ft_strjoin(buffer, line);
		free(tmp);
	}
	close(fd);
	return (buffer);
}

static char	**copy_map(char **lines, int start)
{
	int		i;
	int		size;
	char	**map;

	i = start;
	size = 0;
	while (lines[i])
	{
		size++;
		i++;
	}
	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < size)
	{
		map[i] = ft_strdup(lines[start + i]);
		i++;
	}
	map[size] = NULL;
	return (map);
}

void	parse_cub_file(const char *filename, t_data *data)
{
	char	*content;
	char	**lines;
	int		map_start;

	content = read_file(filename);
	if (!content || !*content)
		exit_error(data, EMPTYFILE);
	lines = ft_split(content, '\n');
	free(content);
	init_data(data);
	parse_config(data, lines);
	map_start = data->map.start_index;
	data->map.lines = copy_map(lines, map_start);
	if (!data->map.lines || !data->map.lines[0])
		exit_error(data, NOMAP);
	data->map.lines = normalize_map(data->map.lines);
	data->map.height = count_lines(data->map.lines);
	data->map.width = max_line_length(data->map.lines);
	validate_map(data);
	free_tab(lines);
}
