/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecartuy <lecartuy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:15:00 by lecartuy          #+#    #+#             */
/*   Updated: 2025/08/08 13:19:07 by lecartuy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

int	check_filename(const char *str)
{
	size_t len;

	len = ft_strlen(str);
	if (len < 4)
		return (1);
	if (ft_strcmp(str + len - 4, ".cub") != 0)
		return (1);
	return (0);
}
