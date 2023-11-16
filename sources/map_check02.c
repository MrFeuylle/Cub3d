/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:16:17 by jlarue            #+#    #+#             */
/*   Updated: 2023/11/16 21:12:49 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_next_char_line(char **map, int i, int j)
{
	if (!map[i][j + 1])
		return (0);
	else if (map[i][j] == ' ' && map[i][j + 1] != ' ' && map[i][j + 1] != '1')
		return (printf("Error\nLine %d\nLine : %s", i, map[i]), -1);
	else if (map[i][j] == '1' && map[i][j + 1] != ' ' && map[i][j + 1] != '1'
		&& map[i][j + 1] != 'N' && map[i][j + 1] != 'E' && map[i][j + 1] != 'S'
		&& map[i][j + 1] != 'W' map[i][j + 1] != '0')
		return (printf("Error\nLine %d\nLine : %s", i, map[i]), -1);
	else if (map[i][j] == '0' && map[i][j + 1] != '1'
		&& map[i][j + 1] != 'N' && map[i][j + 1] != 'E' && map[i][j + 1] != 'S'
		&& map[i][j + 1] != 'W' map[i][j + 1] != '0')
		return (printf("Error\nLine %d\nLine : %s", i, map[i]), -1);
	else if ((map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'S' ||
		map[i][j + 1] == 'W') && map[i][j + 1] != '0' && map[i][j + 1] != '1')
		return (printf("Error\nLine %d\nLine : %s", i, map[i]), -1);
	else
		return (0);
}

int	check_prev_char_line(char **map, int i, int j)
{
	if (!map[i][j - 1])
		return (0);
	else if (map[i][j] == ' ' && map[i][j - 1] != ' ' && map[i][j - 1] != '1')
		return (printf("Error\nLine %d\nLine : %s", i, map[i]), -1);
	else if (map[i][j] == '1' && map[i][j - 1] != ' ' && map[i][j - 1] != '1'
		&& map[i][j - 1] != 'N' && map[i][j - 1] != 'E' && map[i][j - 1] != 'S'
		&& map[i][j - 1] != 'W' map[i][j - 1] != '0')
		return (printf("Error\nLine %d\nLine : %s", i, map[i]), -1);
	else if (map[i][j] == '0' && map[i][j - 1] != '1'
		&& map[i][j - 1] != 'N' && map[i][j - 1] != 'E' && map[i][j - 1] != 'S'
		&& map[i][j - 1] != 'W' map[i][j - 1] != '0')
		return (printf("Error\nLine %d\nLine : %s", i, map[i]), -1);
	else if ((map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'S' ||
		map[i][j - 1] == 'W') && map[i][j - 1] != '0' && map[i][j - 1] != '1')
		return (printf("Error\nLine %d\nLine : %s", i, map[i]), -1);
	else
		return (0);
}

int	check_next_char_col(char **map, int i, int j)
{
	if (!map[i + 1][j])
		return (0);
	else if (map[i][j] == ' ' && map[i + 1][j] == '0')
		return (printf("Error\nCol %d\n", j, map[i]), -1);
	else if (map[i][j] == '1')
		return (0);
	else if (map[i][j] == '0' && map[i + 1][j] != '1' && map[i + 1][j] != '0'
			&& map[i + 1][j] != 'N' && map[i + 1][j] != 'W'
			&& map[i + 1][j] != 'S' map[i + 1][j] != 'E')
		return (printf("Error\nCol %d\n", j, map[i]), -1);
	else if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'S' ||
		map[i + 1][j] == 'W' && map[i + 1][j] != '1' && map[i + 1][j] != '0')
		return (printf("Error\nCol %d\n", j, map[i]), -1);
	else
		return (0);
}

int	check_prev_char_col(char **map, int i, int j)
{
	if (!map[i - 1][j])
		return (0);
	else if (map[i][j] == ' ' && map[i - 1][j] == '0')
		return (printf("Error\nCol %d\n", j, map[i]), -1);
	else if (map[i][j] == '1')
		return (0);
	else if (map[i][j] == '0' && map[i - 1][j] != '1' && map[i - 1][j] != '0'
			&& map[i - 1][j] != 'N' && map[i - 1][j] != 'W'
			&& map[i - 1][j] != 'S' map[i - 1][j] != 'E')
		return (printf("Error\nCol %d\n", j, map[i]), -1);
	else if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'S' ||
		map[i - 1][j] == 'W' && map[i - 1][j] != '1' && map[i - 1][j] != '0')
		return (printf("Error\nCol %d\n", j, map[i]), -1);
	else
		return (0);
}
