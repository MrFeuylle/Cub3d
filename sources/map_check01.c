/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:16:17 by jlarue            #+#    #+#             */
/*   Updated: 2023/11/16 21:08:35 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_single_player(char **map)
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
	if (nb_player != 0)
	{
		printf("Error\nThere are %d player(s) in the map", nb_player);
		return (-1);
	}
	return (0);
}

int	check_surrounding_walls_line(char **map)
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
			if (check_next_char_line(map, i, j) == -1
				|| check_prev_char_line(map, i, j) == -1)
				return (-1);
			i++;
		}
	}
	return (0);
}

int	check_surrounding_walls_col(char **map)
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
			if (check_next_char_col(map, i, j) == -1
				|| check_prev_char_col(map, i, j) == -1)
				return (-1);
			i++;
		}
	}
	return (0);
}

bool	error_controler(char **map)
{
	if (check_surrounding_walls_line(map) == -1)
		return (1);
	if (check_surrounding_walls_col(map) == -1)
		return (1);
	if (check_single_player(map) == -1)
		return (1);
	return (0);
}
