/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebrull <jdebrull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:37:34 by lecartuy          #+#    #+#             */
/*   Updated: 2025/08/12 13:48:50 by jdebrull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2 || check_filename(argv[1]))
	{
		printf("Error\nNot a .cub file\n");
		return (1);
	}
	init_data(&data);
	parse_cub_file(argv[1], &data);
	printf("Parsing OK!\n");
	if (!game_on(&data))
		return (0);
	cleanup(&data);
	return (0);
}
