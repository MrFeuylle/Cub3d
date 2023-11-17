/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:16:17 by jlarue            #+#    #+#             */
/*   Updated: 2023/11/17 03:18:31 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	check_single_player(char **map)
{
	int	i;
	int	j;
	int	nb_player;

	i = 0;
	j = 0;
	nb_player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
				nb_player++;
			j++;
		}
		i++;
	}
	if (nb_player != 1)
	{
		printf("Error\nThere are %d player(s) in the map\n", nb_player);
		return (TRUE);
	}
	return (FALSE);
}

bool	check_surrounding_walls_line(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (check_next_char_line(map, i, j)
				|| check_prev_char_line(map, i, j))
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

bool	check_surrounding_walls_col(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (check_next_char_col(map, i, j)
				|| check_prev_char_col(map, i, j))
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

bool	map_error_controler(char **map)
{
	if (check_surrounding_walls_line(map))
		return (TRUE);
	if (check_surrounding_walls_col(map))
		return (TRUE);
	if (check_single_player(map))
		return (TRUE);
	return (FALSE);
}
