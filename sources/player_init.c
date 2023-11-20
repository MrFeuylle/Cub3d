/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 05:49:48 by jlarue            #+#    #+#             */
/*   Updated: 2023/11/20 22:15:41 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_player_direction(char dir, t_player *player)
{
	if (dir == 'N')
	{
		player->dx = 0;
		player->dy = 1;
	}
	else if (dir == 'E')
	{
		player->dx = 1;
		player->dy = 0;
	}
	else if (dir == 'S')
	{
		player->dx = 0;
		player->dy = -1;
	}
	else
	{
		player->dx = -1;
		player->dy = 0;
	}
	player->plane_x = -player->dy;
	player->plane_y = player->dx;
}

void	init_player_position(t_player *player, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'S'
				|| map[i][j] == 'W')
			{
				player->x = j;
				player->y = i;
				return (init_player_direction(map[i][j], player));
			}
			j++;
		}
		i++;
	}
	printf("Error\nThere are 0 player(s) in the map\n");
}
