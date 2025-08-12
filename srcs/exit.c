/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecartuy <lecartuy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:54:18 by lecartuy          #+#    #+#             */
/*   Updated: 2025/08/08 13:46:35 by lecartuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void cleanup(t_data *data)
{
    if (data->map.lines)
        free_tab(data->map.lines);
    if (data->config.no_texture)
        free(data->config.no_texture);
    if (data->config.so_texture)
        free(data->config.so_texture);
    if (data->config.we_texture)
        free(data->config.we_texture);
    if (data->config.ea_texture)
        free(data->config.ea_texture);
}

void	exit_error(t_data *data, const char *msg)
{
	printf("%s", msg);
	cleanup(data);
	exit(1);
}
